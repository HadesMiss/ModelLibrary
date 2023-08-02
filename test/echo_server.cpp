#include <iostream>
#include "pine.h"
#include "HandleRequest.h"
#include "jwt-cpp/jwt.h"
#include "jwt-cpp/base.h"
#include "DatabaseConnectionPool.h"
#include "RedisDb.h"
#include <sys/wait.h>

std::mutex message_queue_mutex;
std::condition_variable message_queue_cv;
bool stop_flag = false;

int main(){
    DatabaseConnectionPool& pool = DatabaseConnectionPool::getInstance();
    TcpServer *server = new TcpServer(&pool);

    Signal::signal(SIGINT, 
        [&]{
            stop_flag = true;
            int status;
            pid_t finished_child_pid;
            while ((finished_child_pid = wait(&status)) > 0) {
                std::cout << "Child process " << finished_child_pid << " finished." << std::endl;
            }
            std::cout<<"\nServer to exit!" << std::endl;
            delete server;
            std::cout<<"\nServer exit!" << std::endl;
            exit(0);
        });

    server->onConnect([](Connection *conn) { std::cout << "New connection fd: " << conn->socket()->fd() << std::endl; });

    server->onRecv([](Connection *conn) {
        if(conn->state() == Connection::State::Closed) {conn->Close();return;}
        //conn->handlerequest->setrequest(conn->read_buf()->buf());
        std::cout << "Message from client \n" << conn->read_buf()->bufStr().substr(0, 500)<< std::endl;
        sleep(1);
        std::cout << "Message from client \n" << conn->read_buf()->Size()<< std::endl;
        conn->loop_->testhandle->setrequest(conn->read_buf()->bufOrigin(), conn);
        std::string ans = conn->loop_->testhandle->response();
        std::cout<<"get ans"<<ans.length()<<std::endl;
        std::vector<char> charVector(ans.begin(), ans.end());
        conn->Send(charVector);
        std::cout<<"send success"<<std::endl;
    });

    const int num_child_process = 3;
    const char* queue_key = "message_queue";
    const char* lock_key = "message_queue_lock";
    for(int i = 0; i < num_child_process; i++){
        pid_t pid = fork();

        if(pid < 0){
            std::cerr<<"failed to create child process" << std::endl;
            break;
        }
        else if(pid == 0){
            std::unique_ptr<RedisDb> child_process_redis = std::make_unique<RedisDb>();
            while(!stop_flag){
                if(child_process_redis->getLock(lock_key)){
                    //std::cout<<"zuseduqu"<<std::endl;
                    std::string sysCommand = child_process_redis->bpop(queue_key);
                    child_process_redis->delLock(lock_key);
                    system(sysCommand.c_str()); 
                }
                else{
                    sleep(10);
                }  
            }
            //std::cout<<"tuichul "<<std::endl;
        }
    }

    server->Start();

    delete server;
    return 0;
}