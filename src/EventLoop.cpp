#include "EventLoop.h"
#include <vector>
#include "Channel.h"
#include "Poller.h"
#include <stdio.h>
#include <ThreadPool.h>
#include <iostream>
#include "HandleRequest.h"

EventLoop::EventLoop(){
    poller_ = std::make_unique<Poller>();
    testhandle = new HandleRequest();
}

EventLoop::~EventLoop(){printf("\n eventloop xigou");delete testhandle;}

void EventLoop::Loop(std::atomic<bool>& stop) const {
    printf("\n 循环等事件");
    while(true){
        try{
            while (!stop.load()) {
                for (Channel *active_ch : poller_->Poll()) {
                    active_ch->HandleEvent();
                }
            }
        }
        catch(...){
            std::cout<<"some thing happen"<<std::endl;
        }
    }
    printf("\n 结束 task 结束");
}

void EventLoop::UpdateChannel(Channel *ch) const { poller_->UpdateChannel(ch); }

void EventLoop::DeleteChannel(Channel *ch) const { poller_->DeleteChannel(ch); }