#pragma once
#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>
#include "common.h"

class ThreadPool{
public:
    DISALLOW_COPY_AND_MOVE(ThreadPool);
    explicit ThreadPool(unsigned int size = std::thread::hardware_concurrency() / 4);
    ~ThreadPool();

    template<class F, class... Args>
    auto Add(F &&f, Args &&...args) -> std::future<typename std::__invoke_result<F, Args...>::type>;
    std::atomic<bool> stop_{false};
private:
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> tasks_;
    std::mutex queue_mutex_;
    std::condition_variable condition_variable_;

};

template<class F, class... Args>\
// std::future表示异步任务未执行出来的结果的类型，帮助auto推导函数类型
auto ThreadPool::Add(F &&f, Args &&...args) -> std::future<typename std::__invoke_result<F, Args...>::type>{
    using return_type = typename std::__invoke_result<F, Args...>::type;
    
    auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex_);

        if(stop_){
            throw std::runtime_error("enqueue on stoppend ThreadPool");
        }
        tasks_.push([task](){(*task)();});
    }
    condition_variable_.notify_one();
    printf("\n notice once");
    return res;
}