#pragma once
#include <hiredis/hiredis.h>
#include <string>

class RedisDb
{
private:
    redisContext* c;
    redisReply* reply;
public:
    RedisDb();
    ~RedisDb();
    void set(std::string key, std::string value);
    std::string bpop(std::string message_key);
    void push(std::string message_key, std::string& message);
    bool getLock(std::string message_lock);
    int check(std::string key);
    std::string getValue(std::string key);
    void delLock(std::string message_lock);
};