#include <string>
#include <json/json.h>
#include "UserWork.h"
#include <jwt.h>
#include <base.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <filesystem>

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
            if(tempAns[0]["password"].asCString() == password){
                msg = "success";
                code = 1;
                isReal = true;
                avatar = tempAns[0]["avatar"].asCString();
            }
            else{
                msg = "密码错误";
                code = 0;
                isReal = false;

            }
        }
    } 

    ans = Json::Value();
    ans["code"] = code;
    ans["msg"] = msg;
    ans["data"] = data;

    return writer.write(ans);;
}

std::string UserWork::personalInformation(std::string token_){
    data = Json::Value();
    token_ = token_.substr(token_.find(" ") + 1);
    token_ = token_.substr(0, token_.find("\r"));
    std::cout<<token_<<std::endl;
    //token_ = "eyJhbGciOiJIUzI1NiJ9.eyJhdmF0YXIiOiJcL2xvZ28xOTIucG5nIiwiZXhwIjoxNjg2MjUzODcwLCJpc3MiOiJoY3giLCJ0ZWFtIjoiaXNzIiwidXNlcm5hbWUiOiJoY3gifQ.rdFF2NIAtF1bKL7rgaAvvq8P_YnfIMh3s5aWEv_p7ZY";
    std::cout<<token_.length()<<std::endl;
    //auto decoded = jwt::decode(token_);
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

    return writer.write(ans);
}


std::string UserWork::verifyWork(std::string name_){
    std::cout<<name_<<std::endl;
    reader.parse(name_, root);
    username = root["username"].asCString();
    
    std::string query = "select * from user where username = '" + username + "'";
    
    Json::Value tempAns = sqlServer->getResult(query.c_str());
    if(tempAns.size() == 0) {
        code = 1;
        msg = "verification successful";
        data = Json::Value();
    }
    else{
        code = 0;
        msg = "user name registered";
        data = Json::Value();
    }

    ans = Json::Value();
    ans["code"] = code;
    ans["msg"] = msg;
    ans["data"] = data;

    return writer.write(ans);
}

std::string UserWork::submitUserInfo(std::vector<char> &bodyRe, std::string boundary){
    parseMultipartFormDate(bodyRe, boundary);

    code = 1;
    msg = "registration completed";
    data = Json::Value();

    sqlServer->preSearch("INSERT INTO user (username, password, avatar) VALUES (?, ?, ?)");
    sqlServer->setParameter(1, username);
    sqlServer->setParameter(2, password);
    sqlServer->setParameter(3, avatar);

    sqlServer->executeUpdate();
    ans = Json::Value();
    ans["code"] = code;
    ans["msg"] = msg;
    ans["data"] = data;

    return writer.write(ans);
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

void UserWork::parseMultipartFormDate(std::vector<char> &formData, std::string boundary){
    std::cout<<"endPos"<<std::endl;
    std::cout<<std::string(formData.begin(), formData.end());
    std::cout<<"endformdata"<<std::endl;
    std::vector<std::vector<char>> fields;
    auto startPos = std::search(formData.begin(), formData.end(), boundary.begin(), boundary.end()) + boundary.size() + 2;
    auto endPos = std::search(startPos, formData.end(), boundary.begin(), boundary.end()) - 8;
    while(endPos != formData.end()){
        std::cout<<"startPos1"<<std::endl;
        std::vector<char> temp = std::vector<char>(startPos, endPos);
        fields.push_back(temp);
        std::cout<<std::string(temp.begin(), temp.end());
        std::cout<<"startPos2"<<std::endl;

        startPos = std::search(endPos + 8, formData.end(), boundary.begin(), boundary.end()) + boundary.size() + 2;
        endPos = std::search(startPos, formData.end(), boundary.begin(), boundary.end());
        if(endPos != formData.end()){
            endPos = endPos - 8;
        }
        //std::cout<<"startPos"<<std::endl;

    }

    for(std::vector<char>& field :fields){
        std::cout<<std::string(field.begin(), field.end());
        std::string nameS = "name=\"";
        std::string nameE = "\"";
        std::string valueS = "\r\n\r\n";
        std::string valueE = "\r\n------";
        auto namePos = std::search(field.begin(), field.end(), nameS.begin(), nameS.end()) + 6;
        auto nameEndPos = std::search(namePos, field.end(), nameE.begin(), nameE.end());

        auto valuePos = std::search(field.begin(), field.end(), valueS.begin(), valueS.end()) + 4;
        auto valueEndPos = std::search(valuePos, field.end(), valueE.begin(), valueE.end());

        std::vector<char> fieldName = std::vector<char>(namePos, nameEndPos);
        std::vector<char> fieldValue = std::vector<char>(valuePos, valueEndPos);
        std::string nameStr = std::string(fieldName.begin(), fieldName.end());
        std::string valueStr = std::string(fieldValue.begin(), fieldValue.end());
        std::cout<<"startPos"<<std::endl;
        std::cout<<nameStr<<std::endl;
        std::cout<<valueStr<<std::endl;

        if(nameStr == "team") team = valueStr;
        else if(nameStr == "avatar"){
            std::string filename = generateUniqueFilename();
            //std::cout<<filename<<std::endl;
            saveImageToFile(valueStr, "../build/frontend/build/images/" + filename);
            avatar = "/images/" + filename;
            //std::cout<<avatar<<std::endl;
        }
        else if(nameStr == "password"){
            password = valueStr;
        }
        else if(nameStr == "username"){
            username = valueStr;
        }
    }
}

std::string UserWork::generateUniqueFilename(){
    std::time_t currentTime = std::time(nullptr);
    std::string timestamp = std::to_string(currentTime);

    return timestamp + "_" + username + ".jpg";
}

void UserWork::saveImageToFile(const std::string& imageData, const std::string& filePath){
    // std::filesystem::path directory = std::filesystem::path(filePath).parent_path();

    // // Create directory if it doesn't exist
    // if (!std::filesystem::exists(directory)) {
    //     if (!std::filesystem::create_directories(directory)) {
    //         std::cout << "Failed to create directory: " << directory << std::endl;
    //         return;
    //     }
    // }
    std::ofstream file(filePath, std::ios::out | std::ios::binary);

    if(file.is_open()){
        file << imageData;
        file.close();
    }
    else{
        std::cout<<"Failed to open file: "<<filePath<<std::endl;
    }
}