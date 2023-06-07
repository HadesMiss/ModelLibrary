#include "TcpServer.h"
#include "EventLoop.h"
#include "Acceptor.h"
#include "ThreadPool.h"
#include "Connection.h"
#include <cassert>
#include <unistd.h>

TcpServer::TcpServer(){
    main_reactor_ = std::make_unique<EventLoop>();
    acceptor_ = std::make_unique<Acceptor>(main_reactor_.get());
    std::function<void(int)> cb = std::bind(&TcpServer::NewConnection, this, std::placeholders::_1);
    acceptor_->set_new_connection_callback(cb);

    unsigned int size = std::thread::hardware_concurrency() / 4;
    thread_pool_ = std::make_unique<ThreadPool>(size);
    for(size_t i = 0; i < size; i++){
        std::unique_ptr<EventLoop> sub_reactor_ = std::make_unique<EventLoop>();
        sub_reactors_.push_back(std::move(sub_reactor_));
    }
}
TcpServer::~TcpServer(){}

void TcpServer::Start(){
    for (size_t i = 0; i < sub_reactors_.size(); i++) {
        size_t index = i;
        std::function<void()> sub_loop = [this, index]() { // 捕获stop参数
            sub_reactors_[index]->Loop(thread_pool_->stop_);
        };
        thread_pool_->Add(std::move(sub_loop));
    }
    main_reactor_->Loop(thread_pool_->stop_);
}

RC TcpServer::NewConnection(int fd) {
    assert(fd != -1);
    uint64_t random = fd % sub_reactors_.size();

    std::unique_ptr<Connection> conn = std::make_unique<Connection>(fd, sub_reactors_[random].get());
    std::function<void(int)> cb = std::bind(&TcpServer::DeleteConnection, this, std::placeholders::_1);
    
    conn->set_delete_connection(cb);
    conn->set_on_recv(on_recv_);

    connections_[fd] = std::move(conn);
    if (on_connect_) {
        on_connect_(connections_[fd].get());
    }
    return RC_SUCCESS;
}

RC TcpServer::DeleteConnection(int fd) {
    auto it = connections_.find(fd);
    assert( it != connections_.end() );
    connections_.erase(fd);
    return RC_SUCCESS;
}

void TcpServer::onConnect(std::function<void(Connection *)> fn) { on_connect_ = std::move(fn); }

void TcpServer::onRecv(std::function<void(Connection *)> fn) { on_recv_ = std::move(fn); }