#include "Poller.h"

#include "unistd.h"
#include <cstring>
#include "Channel.h"
#include "Socket.h"
#include "util.h"
#include <iostream>

#define MAX_EVENTS 1000

Poller::Poller(){
    fd_ = epoll_create1(0);
    ErrorIf(fd_ == -1, "epoll create error");
    events_ = new epoll_event[MAX_EVENTS];
    memset(events_, 0, sizeof(*events_) * MAX_EVENTS);
}

Poller::~Poller(){
    if(fd_ != -1){
        close(fd_);
    }
    delete[] events_;
}

std::vector<Channel*> Poller::Poll(long timeout) const{
    std::vector<Channel*> active_channels;
    int nfds = 0;
    try{
        nfds = epoll_wait(fd_, events_, MAX_EVENTS, 500000);
    }
    catch (...) {
        std::cout << "Error occurred during epoll_wait: " << std::endl;
    }
    for(int i = 0; i < nfds; i++){
        Channel *ch = (Channel*)events_[i].data.ptr;
        int events = events_[i].events;
        if(events & EPOLLIN){
            ch->set_ready_event(Channel::READ_EVENT);
        }
        if(events & EPOLLOUT){
            ch->set_ready_event(Channel::WRITE_EVENT);
        }
        if(events & EPOLLET){
            ch->set_ready_event(Channel::ET);
        }
        active_channels.push_back(ch);
    }
    std::cout<<active_channels.size()<<std::endl;
    return active_channels;
}

RC Poller::UpdateChannel(Channel* ch) const{
    int sockfd = ch->fd();
    struct epoll_event ev{};
    ev.data.ptr = ch;
    if(ch->listen_events() & Channel::READ_EVENT){
        ev.events |= EPOLLIN | EPOLLPRI;
    }
    if(ch->listen_events() & Channel::WRITE_EVENT){
        ev.events |= EPOLLOUT;
    }
    if(ch->listen_events() & Channel::ET){
        ev.events |= EPOLLET;
    }
    if(!ch->exist()){
        ErrorIf(epoll_ctl(fd_, EPOLL_CTL_ADD, sockfd, &ev) == -1, "epoll and erroe");
        ch->set_exist(true);
    }
    else{
        ErrorIf(epoll_ctl(fd_, EPOLL_CTL_MOD, sockfd, &ev) == -1, "epoll modify error");
    }

    return RC_SUCCESS;
}

RC Poller::DeleteChannel(Channel *ch) const{
    int sockfd = ch->fd();
    ErrorIf(epoll_ctl(fd_, EPOLL_CTL_DEL, sockfd, nullptr) == -1, "epoll delete error");
    ch->set_exist(false);

    return RC_SUCCESS;
}
