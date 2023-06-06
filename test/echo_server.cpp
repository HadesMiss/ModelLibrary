#include <iostream>
#include "pine.h"
#include "HandleRequest.h"

int main(){
    TcpServer *server = new TcpServer();

    Signal::signal(SIGINT, 
        [&]{
            std::cout<<"\nServer to exit!" << std::endl;
            delete server;
            std::cout<<"\nServer exit!" << std::endl;
            exit(0);
        });

    server->onConnect([](Connection *conn) { std::cout << "New connection fd: " << conn->socket()->fd() << std::endl; });

    server->onRecv([](Connection *conn) {
        std::cout<< "\n 检测断开连接?";
        if(conn->state() == Connection::State::Closed) {std::cout<< "\n 检测断开连接";conn->Close();return;}
        // conn->handlerequest->setrequest(conn->read_buf()->c_str());
        std::cout << "Message from client \n" << conn->read_buf()->buf().substr(0, 100) << std::endl;
        conn->loop_->testhandle->setrequest(conn->read_buf()->c_str());
        std::cout << "\n initial success handleRequest"<<std::endl;;
        std::string ans = conn->loop_->testhandle->response();
        std::cout<<"get ans"<<std::endl;
        conn->Send(ans);
        std::cout << "Message To client success" << std::endl;
    });
    server->Start();

    delete server;
    return 0;
}