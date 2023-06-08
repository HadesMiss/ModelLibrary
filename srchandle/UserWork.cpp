#include <string>
#include <json/json.h>
#include "UserWork.h"
#include <jwt.h>
#include <base.h>

UserWork::UserWork(SqlServer* sqlServer_) : sqlServer(sqlServer_){

}

UserWork::~UserWork(){
    
}


std::string UserWork::loginWork(std::string body){
    Json::Value jsonData;
    Json::Reader jsonReader;
    if(jsonReader.parse(body, jsonData)){
        username = jsonData["username"].asString();
        password = jsonData["password"].asString();
        
        std::string query = "select * from user where username = '" + username + "'";
        
        Json::Value tempAns = sqlServer->getResult(query.c_str());
        if(tempAns.size() == 0) {
            msg = "用户名错误";
            code = 0;
            isReal = false;
        }
        else{
            if(tempAns[0]["password"] == password){
                msg = "success";
                code = 1;
                isReal = true;
            }
            else{
                msg = "密码错误";
                code = 0;
                isReal = false;
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

std::string UserWork::personalInformation(std::string token_){
    data = Json::Value();
    token_ = token_.substr(token_.find(" ") + 1);
    token_ = token_.substr(0, token_.find("\r"));
    std::cout<<token_<<std::endl;
    //token_ = "eyJhbGciOiJIUzI1NiJ9.eyJhdmF0YXIiOiJcL2xvZ28xOTIucG5nIiwiZXhwIjoxNjg2MjUzODcwLCJpc3MiOiJoY3giLCJ0ZWFtIjoiaXNzIiwidXNlcm5hbWUiOiJoY3gifQ.rdFF2NIAtF1bKL7rgaAvvq8P_YnfIMh3s5aWEv_p7ZY";
    std::cout<<token_.length()<<std::endl;
    auto decoded = jwt::decode(token_);
    try{
        std::cout<<"yyyy"<<std::endl;
        auto verify = jwt::verify().allow_algorithm(jwt::algorithm::hs256("liumingshabi")).with_issuer("hcx");
        std::cout<<"yyyy"<<std::endl;
        auto decoded = jwt::decode(token_);
        std::cout<<"yyyy"<<std::endl;
        verify.verify(decoded);
        isReal = true;
        for (auto& e : decoded.get_header_json())
		   tokenMp[e.first] = e.second.to_str();
	    for (auto& e : decoded.get_payload_json())
		   tokenMp[e.first] = e.second.to_str();
        std::cout<<"yyyy"<<std::endl;
        data["username"] = tokenMp["username"];
        username = tokenMp["username"];
        data["team"] = tokenMp["team"];
        team = tokenMp["team"];
        data["avatar"] = tokenMp["avatar"];
        avatar = tokenMp["avatar"];
        code = 1;
        msg = "success";
        std::cout<<"yyyy"<<std::endl;
    }
    catch(...){
        std::cout<<"byyyy"<<std::endl;
        isReal = false;
        code = 0;
        msg = "no login";
        data.append("null");
    }
    ans["code"] = code;
    ans["msg"] = msg;
    ans["data"] = data;
    Json::FastWriter writer;
    std::string _content = writer.write(ans);
    return _content;
}


std::string UserWork::verifyWork(std::string name_){
    std::string username = name_;
    
    std::string query = "select * from user where username = '" + username + "'";
    
    Json::Value tempAns = sqlServer->getResult(query.c_str());
    if(tempAns.size() == 0) {
        return "1";
    }
    else return "0";
}


void UserWork::makeToken(){
    auto token_ = jwt::create()
                .set_issuer("hcx")
                .set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{36000})
                .set_payload_claim("username", jwt::claim(username))
                .set_payload_claim("team", jwt::claim(team))
                .set_payload_claim("avatar", jwt::claim(avatar))
                .sign(jwt::algorithm::hs256("liumingshabi"));
    token = token_;
}

std::string UserWork::getJwtToken(){
    if(isReal){
        makeToken(); 
        return token;
    }
    else{
        return "mistake";
    }
}