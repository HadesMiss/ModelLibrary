#include <iostream>
#include "pine.h"
#include "HandleRequest.h"
#include "jwt-cpp/jwt.h"
#include "jwt-cpp/base.h"
#include "DatabaseConnectionPool.h"

int main(){
    DatabaseConnectionPool& pool = DatabaseConnectionPool::getInstance();
    TcpServer *server = new TcpServer(&pool);

    Signal::signal(SIGINT, 
        [&]{
            std::cout<<"\nServer to exit!" << std::endl;
            delete server;
            std::cout<<"\nServer exit!" << std::endl;
            exit(0);
        });

    server->onConnect([](Connection *conn) { std::cout << "New connection fd: " << conn->socket()->fd() << std::endl; });

    server->onRecv([](Connection *conn) {
        if(conn->state() == Connection::State::Closed) {conn->Close();return;}
        //conn->handlerequest->setrequest(conn->read_buf()->buf());
        std::cout << "Message from client \n" << conn->read_buf()->bufStr()<< std::endl;
        std::cout << "Message from client \n" << conn->read_buf()->Size()<< std::endl;
        conn->loop_->testhandle->setrequest(conn->read_buf()->bufOrigin(), conn);
        std::string ans = conn->loop_->testhandle->response();
        // while(!ans.length()) {
        //     conn->Read();
        //     std::cout << "Message from client \n" << conn->read_buf()->bufStr()<< std::endl;
        //     std::cout << "Message from client \n" << conn->read_buf()->Size()<< std::endl;
        //     conn->loop_->testhandle->setrequest(conn->read_buf()->bufOrigin());
        //     ans = conn->loop_->testhandle->response();
        // }

        std::cout<<"get ans"<<ans.length()<<std::endl;
        std::vector<char> charVector(ans.begin(), ans.end());
        conn->Send(charVector);
        std::cout<<"send success"<<std::endl;
    });
    server->Start();

    delete server;
    return 0;
}