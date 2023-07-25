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
    int check(std::string key);
    std::string getValue(std::string key);
};