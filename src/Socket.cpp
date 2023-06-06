#include "Socket.h"
#include "unistd.h"
#include "fcntl.h"
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <cstring>
#include <cassert>

Socket::Socket() : fd_(-1){}

Socket::~Socket(){
    if(fd_ != -1){
        close(fd_);
        fd_ = -1;
    }
}

void Socket::set_fd(int fd) {fd_ = fd;}

int Socket::fd() const{return fd_;}

std::string Socket::get_addr() const {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    socklen_t len = sizeof(addr);
    if(getpeername(fd_, (struct sockaddr*)&addr, &len) == -1){
        return "";
    }
    std::string ret(inet_ntoa(addr.sin_addr));
    ret += ":";
    ret += std::to_string(htons(addr.sin_port));
    return ret;
}

RC Socket::SetNonBlocking() const{
    if(fcntl(fd_, F_SETFL, fcntl(fd_, F_GETFL) | O_NONBLOCK) == -1){
        perror("Socket set non-blocking failed");
        return RC_SOCKET_ERROR;
    }
    return RC_SUCCESS;
}

bool Socket::IsNonBlocking() const {return (fcntl(fd_, F_GETFL) & O_NONBLOCK) != 0;}

size_t Socket::RecvBufSize() const {
  size_t size = -1;
  if (ioctl(fd_, FIONREAD, &size) == -1) {
    perror("Socket get recv buf size failed");
  }
  return size;
}

RC Socket::Create(){
    assert(fd_ == -1);
    fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if(fd_ == -1){
        perror("Failed to create socket");
        return RC_SOCKET_ERROR;
    }
    return RC_SUCCESS;
}

RC Socket::Bind(const char *ip, uint16_t port) const{
    assert(fd_ != -1);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    if(::bind(fd_, (struct sockaddr*)&addr, sizeof(addr)) == -1){
        perror("Failed to bind socket");
        return RC_SOCKET_ERROR;
    }
    return RC_SUCCESS;
}

RC Socket::Listen() const{
    assert(fd_ != -1);
    if(::listen(fd_, SOMAXCONN) == -1){
        perror("Failed to listen socket");
        return RC_SUCCESS;
    }
    return RC_SUCCESS;
}

RC Socket::Accept(int &clnt_fd) const{
    assert(fd_ != -1);
    clnt_fd = ::accept(fd_, NULL, NULL);
    if(clnt_fd == -1){
        perror("Failed to accept socket");
        return RC_SOCKET_ERROR;
    }
    return RC_SUCCESS;
}

RC Socket::Connect(const char *ip, uint16_t port) const {
  // TODO: non-blocking
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons(port);
  if (::connect(fd_, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Failed to connect socket");
    return RC_SOCKET_ERROR;
  }
  return RC_SUCCESS;
}

