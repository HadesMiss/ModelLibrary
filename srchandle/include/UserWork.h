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
    std::string submitUserInfo(std::vector<char> &body, std::string boundary);
    void makeToken();
    void parseMultipartFormDate(std::vector<char> &formData, std::string boundary);
    std::string generateUniqueFilename();
    void saveImageToFile(const std::string& imageData, const std::string& filePath);

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
    Json::Value root;
    Json::Reader reader;
    Json::FastWriter writer;
    std::string msg;
    bool isReal = false;
    int code;

    std::unordered_map<std::string, std::string> tokenMp;
};
