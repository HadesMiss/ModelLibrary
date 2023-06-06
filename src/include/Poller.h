#pragma once
#include "common.h"
#include <vector>
#include <sys/epoll.h>

class Poller{
public:
    DISALLOW_COPY_AND_MOVE(Poller);
    Poller();
    ~Poller();

    RC UpdateChannel(Channel *ch) const;
    RC DeleteChannel(Channel *ch) const;

    std::vector<Channel *> Poll(long timeout = -1) const;

private:
    int fd_;
    struct epoll_event *events_{nullptr};

};
