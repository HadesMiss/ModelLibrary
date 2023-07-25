#include "RedisDb.h"
#include <hiredis/hiredis.h>
#include <iostream>

RedisDb::RedisDb(){
    c = redisConnect("127.0.0.1", 6379);
    if (c == NULL || c->err) {
        if (c) {
            printf("Error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Could not allocate redis context\n");
        }
    }
    redisReply *reply = (redisReply *)redisCommand(c, "AUTH %s", "123");
    if (reply == NULL) {
        printf("Error executing AUTH command: %s\n", c->errstr);
        redisFree(c);
    }
    freeReplyObject(reply);
}

RedisDb::~RedisDb(){
    freeReplyObject(reply);
    redisFree(c);
}

void RedisDb::set(std::string key, std::string value){
    std::cout<<key<<std::endl<<value<<std::endl;
    reply = (redisReply *)redisCommand(c, "SET %s %s", key.c_str(), value.c_str());
    if (reply == NULL) {
    printf("Command execution error\n");
    // 处理命令执行错误
    } else {
        // 处理命令执行成功的情况
        printf("SET: %s\n", reply->str);
        freeReplyObject(reply);
    }
}

int RedisDb::check(std::string key){
    reply = (redisReply *)redisCommand(c, "EXISTS %s", key);
        if (reply == NULL) {
        printf("Command execution error\n");
        // 处理命令执行错误
        return -1; // 返回-1表示发生错误
    }

    if (reply->type == REDIS_REPLY_INTEGER) {
        int exists = reply->integer;
        freeReplyObject(reply);
        return exists; // 返回1表示键存在，返回0表示键不存在
    } else {
        printf("Unexpected reply type: %d\n", reply->type);
        freeReplyObject(reply);
        return -1; // 返回-1表示发生错误
    }
}

std::string RedisDb::getValue(std::string key){
    reply = (redisReply *)redisCommand(c, "GET %s", key);
    if (reply == NULL) {
        printf("Command execution error\n");
        // 处理命令执行错误
        return NULL;
    }

    std::string value;
    if (reply->type == REDIS_REPLY_STRING) {
        value = reply->str; // 复制值到新的字符
    } else if (reply->type == REDIS_REPLY_NIL) {
        printf("Key '%s' does not exist in Redis.\n", key);
    } else {
        printf("Unexpected reply type: %d\n", reply->type);
    }
    freeReplyObject(reply);
    return value;
}