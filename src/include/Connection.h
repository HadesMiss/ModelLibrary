#pragma once
#include <functional>
#include "common.h"
#include <string>
#include <memory>
#include "HandleRequest.h"

class Connection{
public:
    enum State{
        Invalid = 0,
        Connecting,
        Connected,
        Closed
    };
    DISALLOW_COPY_AND_MOVE(Connection);
    Connection(int fd, EventLoop* loop);
    ~Connection();
    
    void set_delete_connection(std::function<void(int)> const &fn);
    void set_on_connect(std::function<void(Connection *)> const &fn);
    void set_on_recv(std::function<void(Connection *)> const &fn);
    State state() const;
    Socket *socket() const;
    void set_send_buf(const std::vector<char> &str);
    Buffer *read_buf();
    Buffer *send_buf();

    RC Read();
    RC Write();
    RC Send(std::vector<char> &msg);

    void Close();

    // void onConnect(std::function<void()> fn);
    // void onMessage(std::function<void()> fn);
    EventLoop *loop_;
    
private:
    void Business();
    RC ReadNonBlocking();
    RC WriteNonBlocking();
    RC ReadBlocking();
    RC WriteBlocking();

private:
    std::unique_ptr<Socket> socket_;
    std::unique_ptr<Channel> channel_;
    

    size_t offset_ = 0;
    State state_;
    std::unique_ptr<Buffer> read_buf_;
    std::unique_ptr<Buffer> send_buf_;

    std::function<void(int)> delete_connectioin_;
    std::function<void(Connection *)> on_recv_;
};
