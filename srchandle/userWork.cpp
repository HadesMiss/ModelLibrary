#include <string>
#include <json/json.h>
#include "userWork.h"

std::string loginWork(std::string body, SqlServer* hcxServer){
    Json::Value jsonData;
    Json::Reader jsonReader;
    int code = 1;
    std::string msg = "success";
    std::string data = "adgadgadgasdgsdgagd";
    if(jsonReader.parse(body, jsonData)){
        std::string username = jsonData["username"].asString();
        std::string password = jsonData["password"].asString();
        
        std::string query = "select * from user where username = '" + username + "'";
        
        Json::Value tempAns = hcxServer->getResult(query.c_str());
        if(tempAns.size() == 0) {
            msg = "NO USERNAME";
            code = 0;
        }
        else{
            if(tempAns[0]["password"] == password){
                msg = "SUCCESS";
            }
            else{
                msg = "PASSWORD MISTAKE";
                code = 0;
            }
        }

    } 


    Json::Value tempString;

    tempString["code"] = code;
    tempString["msg"] = msg;
    tempString["data"] = data;


    Json::FastWriter writer;
    std::string _content = writer.write(tempString);
    return _content;
}

std::string verifyWork(std::string body, SqlServer* hcxServer){
    std::string username = body;
    
    std::string query = "select * from user where username = '" + username + "'";
    
    Json::Value tempAns = hcxServer->getResult(query.c_str());
    if(tempAns.size() == 0) {
        return "1";
    }
    else return "0";
}
