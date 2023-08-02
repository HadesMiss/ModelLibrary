#include "Connection.h"
#include <unistd.h>
#include "Buffer.h"
#include "Channel.h"
#include "Socket.h"
#include <cassert>
#include <cstring>

Connection::Connection(int fd, EventLoop *loop){
    loop_ = loop;
    socket_ = std::make_unique<Socket>();
    socket_->set_fd(fd);
    if(loop != nullptr){
        channel_ = std::make_unique<Channel>(fd, loop);
        channel_->EnableRead();
        channel_->EnableET();
        printf("\n 包装成connection channel 并设置成可读和非阻塞");
    }

    read_buf_ = std::make_unique<Buffer>();
    send_buf_ = std::make_unique<Buffer>();

    state_ = State::Connected;
}

Connection::~Connection(){printf("\n 析构connection");}

RC Connection::Read(){

    printf("\n 进入阅读");
    if(state_ != Connected){
        perror("Connection is not connected, can not read");
        return RC_CONNECTION_ERROR;
    }
    assert(state_ == State::Connected && "connection state is disconnected!");
    read_buf_->Clear();
    if(socket_-> IsNonBlocking()){
        return ReadNonBlocking();
    }
    else{
        return ReadBlocking();
    }
}

RC Connection::Write(){
    if(state_ != State::Connected){
        perror("Connection is not connected, can not write");
        return RC_CONNECTION_ERROR;
    }
    RC rc = RC_UNDEFINED;
    if(socket_->IsNonBlocking()){
        rc = WriteNonBlocking();
        while (rc != RC_SUCCESS)
        {
            rc = WriteNonBlocking();
        }
    }
    else{
        rc = WriteNonBlocking();
    }
    send_buf_->Clear();
    return rc;
}

RC Connection::ReadNonBlocking(){
    //std::vector<char> received_data;
    printf("\n read");
    int sockfd = socket_->fd();
    char buf[1024];
    while(true){
        memset(buf, 0, sizeof(buf));
        ssize_t bytes_read = read(sockfd, buf, sizeof(buf));
        if(bytes_read > 0){
            //received_data.insert(received_data.end(), buf, buf + bytes_read);
            read_buf_->Append(buf, bytes_read);
        }
        else if(bytes_read == -1 && errno == EINTR){
            printf("continue reading\n");
        }
        else if(bytes_read == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))){
            //read_buf_->castTostring(received_data);
            printf("\n 正常中断读取");
            break;
        }
        else if(bytes_read == 0){
            printf("\n read EOF, client fd %d disconnected\n", sockfd, strerror(errno));
            state_ = State::Closed;
            return RC_UNDEFINED;
        }
        else{
            printf("Other error on client fd %d\n", sockfd, strerror(errno));
            state_ = State::Closed;
            break;
        }
    }
    return RC_SUCCESS;
}

RC Connection::WriteNonBlocking(){
    int sockfd = socket_->fd();
    const char* data = send_buf_->c_str();
    int data_size = send_buf_->Size();
    //std::cout<<"data_size"<<std::endl;
    //std::cout<<data_size<<std::endl;
    int data_left = data_size - offset_;  // 计算剩余数据的大小
    ssize_t bytes_written = 0;

    while (data_left > 0) {
        bytes_written = write(sockfd, data + offset_, data_left);
        std::cout<<bytes_written<<std::endl;
        if (bytes_written == -1 && errno == EINTR) {
            printf("continue writing\n");
            continue;
        }
        if (bytes_written == -1 && errno == EAGAIN) {
            // 数据无法完全写入，返回 RC_WRITE_INCOMPLETE，表示需要继续写入
            std::cout<<"continue??"<<std::endl;
            return RC_UNDEFINED;
        }
        if (bytes_written == -1) {
            printf("Other error1 on client fd %d\n", sockfd, strerror(errno));
            state_ = State::Closed;
            return RC_SUCCESS; // 返回错误代码，根据需要进行处理
        }
        offset_ += bytes_written;  // 更新偏移量
        data_left -= bytes_written;
        std::cout<<"offset"<<std::endl;
        //std::cout<<offset_<<std::endl;
        //std::cout<<"data_left"<<std::endl;
        //std::cout<<data_left<<std::endl;
    }

    if (offset_ == data_size) {
        offset_ = 0;  // 重置偏移量为0，以便下一次重新开始写入
    }
    std::cout<<"return"<<std::endl;
    return RC_SUCCESS;
}

RC Connection::ReadBlocking() {
    int sockfd = socket_->fd();
    // unsigned int rcv_size = 0;
    // socklen_t len = sizeof(rcv_size);
    // getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &rcv_size, &len);
    // size_t data_size = socket_->RecvBufSize();
    char buf[4413414];
    ssize_t bytes_read = read(sockfd, buf, sizeof(buf));
    if (bytes_read > 0) {
        read_buf_->Append(buf, bytes_read);
    } else if (bytes_read == 0) {
        printf("read EOF, blocking client fd %d disconnected\n", sockfd);
        state_ = State::Closed;
    } else if (bytes_read == -1) {
        printf("Other error on blocking client fd %d\n", sockfd);
        state_ = State::Closed;
    }
    return RC_SUCCESS;
}

RC Connection::WriteBlocking() {
    // 没有处理send_buffer_数据大于TCP写缓冲区，的情况，可能会有bug
    int sockfd = socket_->fd();
    const char* data = send_buf_->c_str();
    ssize_t bytes_write = write(sockfd, data, send_buf_->Size());
    if (bytes_write == -1) {
        printf("Other error on blocking client fd %d\n", sockfd);
        state_ = State::Closed;
    }
    return RC_SUCCESS;
}

RC Connection::Send(std::vector<char> &msg) {
    set_send_buf(msg);
    Write();
    return RC_SUCCESS;
}

void Connection::Business() {
    printf("进入Bussiness");
    Read();
    printf("read success");
    on_recv_(this);
}

void Connection::set_delete_connection(std::function<void(int)> const &fn) { delete_connectioin_ = std::move(fn); }

void Connection::set_on_recv(std::function<void(Connection *)> const &fn) {
    on_recv_ = std::move(fn);
    std::function<void()> bus = std::bind(&Connection::Business, this);
    if(channel_->read_callback_) printf("\n good for channel \n");
    channel_->set_read_callback(bus);
    if(channel_->read_callback_) printf("\n good for channel \n");
    printf("set_read_callback");
}

void Connection::Close() { delete_connectioin_(socket_->fd()); }

Connection::State Connection::state() const { return state_; }

Socket *Connection::socket() const { return socket_.get(); }

void Connection::set_send_buf(const std::vector<char> &str) { send_buf_->set_buf(str); }
Buffer *Connection::read_buf() { return read_buf_.get(); }
Buffer *Connection::send_buf() { return send_buf_.get(); }

