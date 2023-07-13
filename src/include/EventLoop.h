#pragma once
#include "common.h"
#include <memory>
#include "HandleRequest.h"

class EventLoop{
public:
    DISALLOW_COPY_AND_MOVE(EventLoop);
    EventLoop(DatabaseConnectionPool* pool);
    ~EventLoop();

    void Loop(std::atomic<bool>& stop) const;
    void UpdateChannel(Channel *ch) const;
    void DeleteChannel(Channel *ch) const;
    HandleRequest *testhandle;
private:
    std::unique_ptr<Poller> poller_;
};