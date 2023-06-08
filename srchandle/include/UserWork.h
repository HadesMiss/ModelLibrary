#pragma once
#include <iostream>
#include "SqlServer.h"
#include <unordered_map>

class UserWork{
public:
    UserWork() = default;
    UserWork(SqlServer* sqlServer_); 
    ~UserWork();


    std::string loginWork(std::string body);
    std::string personalInformation(std::string token_);
    std::string verifyWork(std::string body);
    std::string getJwtToken();
    void makeToken();

private:
    std::string username;
    std::string password;
    std::string token;
    std::string avatar = "/logo192.png";
    std::string team = "iss";
    std::string rsa_pub_key = "liumingshabi";
    SqlServer* sqlServer;
    Json::Value data;
    Json::Value ans;
    std::string msg;
    bool isReal = false;
    int code;

    std::unordered_map<std::string, std::string> tokenMp;
};
