#include "ThreadPool.h"
#include <iostream>

ThreadPool::ThreadPool(unsigned int size){
    for(unsigned int i = 0; i < size; i++){
        workers_.emplace_back(std::thread(
            [this](){
                while(true){
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex_);
                        printf("\nthread wait");
                        condition_variable_.wait(lock, [this](){return stop_ || !tasks_.empty(); });
                        printf("\nthread dont wait");
                        if(stop_ && tasks_.empty()){
                            return;
                        }
                        task = tasks_.front();
                        tasks_.pop();
                    }
                    printf("\n一轮task开始");
                    task();
                    printf("\n一轮task结束");
                }
            }));
    }
}

ThreadPool::~ThreadPool(){
    printf("\n threadpool xigou");
    {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        stop_ = true;
    }
    condition_variable_.notify_all();
    printf("\n notice all");

    for(std::thread &th : workers_){
        if(th.joinable()){
            th.join();
            printf("\n thread join");
        }
    }
}