#include "HandleRequest.h"
#include <fstream>
#include <iostream>
#include <json/json.h>
#include "modelWork.h"
#include "datasetWork.h"
#include <Connection.h>
#include <Buffer.h>
#include <DatabaseConnectionPool.h>

extern DatabaseConnectionPool pool;

HandleRequest::HandleRequest(DatabaseConnectionPool* pool_) : prePath("./frontend/build"){
    pool = pool_;
    userWork = new UserWork(hcxServer);
    printf("\n sql server success");
}

HandleRequest:: HandleRequest(std::vector<char> _request, Connection* conn, std::string _prePath) : requestRe(_request), prePath(_prePath){
    userWork = new UserWork(hcxServer);
    con_ = conn;
    translation();
}

HandleRequest::~HandleRequest(){
    delete userWork;
}

void HandleRequest::translation(){
    // if(multipartUserInfo) {
    //     bodyRe.insert(bodyRe.end(), requestRe.begin(), requestRe.end());
    //     std::cout<<"kongbody"<<std::string(bodyRe.data(), bodyRe.size())<<std::endl;
    //     method = "";
    //     return;
    // }

    std::string request(requestRe.data(), requestRe.size());

    std::istringstream iss(request);

    // 解析请求行
    std::string requestLine;
    std::getline(iss, requestLine);

    std::istringstream lineStream(requestLine);
    lineStream >> method >> path >> httpVersion;

    replaceSpaces();

    // 解析报文头部
    std::string header;
    while(std::getline(iss, header) && header.size() > 1){
        std::string temp = header.substr(header.find(':') + 2, header.find('\r'));
        headersMp[header.substr(0, header.find(':'))] = temp;
    }


    std::string bodyDelimiter = "\r\n\r\n";
    auto bodyStartPos = std::search(requestRe.begin(), requestRe.end(), bodyDelimiter.begin(), bodyDelimiter.end());
    if (bodyStartPos != requestRe.end()) {
        bodyStartPos += bodyDelimiter.size();
        bodyRe = std::vector<char>(bodyStartPos, requestRe.end());
        body = std::string(bodyRe.data(), bodyRe.size());
        // 处理主体部分，包括二进制数据
    }
    if(headersMp.count("Content-Length") == 1)
    {
        long long length = stoi(headersMp["Content-Length"]);
        std::cout<<"length"<<std::endl;
        while(bodyRe.size() < length){
            con_->Read();
            std::vector<char> buf_ = con_->read_buf()->bufOrigin();
            bodyRe.insert(bodyRe.end(), buf_.begin(), buf_.end());
            std::cout << "Message1 from client \n" << bodyRe.size()<< std::endl;
            //sleep(5);
        }
        headersMp["Content-Length"] = "0";
        body = std::string(bodyRe.data(), bodyRe.size()) ;
    }
}

std::string HandleRequest::response(){
    std::string content;
    std::string contentType;
    std::string connection;
    if(headersMp.count("Connection")){
        connection = headersMp["Connection"];
    }
    else{
        connection = "close";
    }
    std::cout<<"method"<<std::endl;
    if(method == "GET"){
        getResponse(content, contentType);
    }
    else if(method == "POST"){
        postResponse(content, contentType);
    }
    else{
        if(multipartUserInfo) {
            std::cout<<"zhentshichuli"<<std::endl;
            content = userWork->submitUserInfo(bodyRe, boundary);
            contentType = "application/javascript";
            multipartUserInfo = false;
        }
        else{
            content = "NO GET OR POST";
        }
    }
    std::cout<<"content"<<std::endl;
    std::string responseContent = "HTTP/1.1 200 OK\r\n";
        responseContent += "Content-Type: " + contentType + "\r\n";
        responseContent += "Content-Length: " + std::to_string(content.size()) + "\r\n";
        responseContent += "Connection: " + connection + "\r\n";
        responseContent += "Authorization: " + userWork->getJwtToken() + "\r\n\r\n";
        responseContent += content;

    // if (needJWT) {
    //     responseContent += ("Authorization: " + userWork->getJwtToken() + "\r\n");
    //     needJWT = false;
    // }

    // responseContent += ("\r\n" + content + "\r\n");
    // //if(multipartUserInfo) responseContent = "";
    pool->releaseConnection(hcxServer);
    return responseContent;
}

void HandleRequest::getResponse(std::string& _content, std::string& _contentType){
    if(path.find('?') != std::string::npos){
        parseURLParameters(path.substr(path.find('?') + 1));
        path = path.substr(0, path.find('?'));
    }

    if(path == "/") {
        _content = readFile(prePath + "/index.html");
        _contentType = "text/html";
    }
    else if(path == "/api/modelList"){
        _content = modelListWork(parameters, hcxServer);
        _contentType = "application/javascript";
    }
    else if(path == "/api/modelLabel"){
        _content = modelLabelWork(hcxServer);
        _contentType = "application/javascript";
    }
    else if(path == "/api/datasetList"){
        _content = datasetListWork(parameters, hcxServer);
        _contentType = "application/javascript";
    }
    else if(path == "/api/datasetLabel"){
        _content = datasetLabelWork(hcxServer);
        _contentType = "application/javascript";
    }
    else if(path.find(".png") != std::string::npos){
            _contentType = "image/png";
            _content = readFile(prePath + path, true);
    }
    else if(path.find(".ico") != std::string::npos){
        _contentType = "image/x-icon";
        _content = readFile(prePath + path, true);
    }
    else if(path.find("hcxhcx") != std::string::npos){
        _contentType = "image/x-icon";
        _content = readFile("onemodelt", true);
    }
    else if(path.find(".js") != std::string::npos){
        _contentType = "application/javascript";
        _content = readFile(prePath + path);
    }
    else if(path == "/api/personalInformation"){
        needJWT = true;
        _contentType = "application/javascript";
        _content = userWork->personalInformation(headersMp["Authorization"]);
    }
    else if(path == "/api/register/verifyUsername"){
        _contentType = "application/javascript";
        _content = userWork->verifyWork(headersMp["Authorization"]);
    }
    else{
        if(path.find(".js") != std::string::npos){
            _contentType = "application/javascript";
        }
        else if(path.find(".css") != std::string::npos){
            _contentType = "text/css";
        }
        else if(path.find(".png") != std::string::npos){
            _contentType = "image/png";
        }
        else if(path.find(".html") != std::string::npos){
            _contentType = "text/html";
        }
        else if(path.find(".ico") != std::string::npos){
            _contentType = "image/x-icon";
        }
        else if(path.find(".jpg") != std::string::npos){
            _contentType = "image/jpg";
        }
        else{
            path = "/index.html";
            _contentType = "text/html";
        }
        _content = readFile(prePath + path);
    }
    
}

void HandleRequest::postResponse(std::string& _content, std::string& _contentType){
    if(path == "/api/login"){
        needJWT = true;
        _content = userWork->loginWork(body);
        _contentType = "application/javascript";
    }
    else if(path == "/api/register/verifyUsername"){
        _content = userWork->verifyWork(body);
        _contentType = "application/javascript";
    }
    else if(path == "/api/register/submitUserInfo"){
        boundary = headersMp["Content-Type"].substr(headersMp["Content-Type"].find("=") + 5);
        boundary = boundary.substr(0, boundary.find("\r"));
        std::cout<<boundary<<std::endl;
        std::cout<<boundary.length()<<std::endl;
        //needJWT = true;
        //multipartUserInfo = true;
        //method = "";
        _content = userWork->submitUserInfo(bodyRe, boundary);
        _contentType = "application/javascript";
    }
    else if(path == "/api/modelhcx"){
        std::string filename = "onemodelt";
            //std::cout<<filename<<std::endl;
        std::ofstream file(filename, std::ios::out | std::ios::binary);

        if(file.is_open()){
            file << body;
            file.close();
        }
        else{
            std::cout<<"Failed to open file: "<<filename<<std::endl;

        //continueRead = true;
    }
    }
}

std::string HandleRequest::readFile(std::string path, bool isBinary) {
    // if(isBinary == true){
    //     std::ifstream file(path, std::ios::binary);
    //     std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    //     file.close();
    //     return content;
    // }
    // else{
    //     std::ifstream file(path);
    //     std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    //     file.close();
    //     return content;
    // }
    fileRAII inputFile(path, isBinary);
    return inputFile.readFile();


}

void HandleRequest::setprePath(std::string _prePath){
    
    prePath = _prePath;
    translation();
}

void HandleRequest::setrequest(std::vector<char> _request, Connection* connn){
    hcxServer = pool->getConnection();
    std::cout<<"hcxS"<<std::endl;
    con_ = connn;
    requestRe = _request;
    translation();
}

std::string HandleRequest::getBody(){
    if(body.size() == 0){
        return "size0";
    }
    return body;
}

void HandleRequest::parseURLParameters(const std::string& url){
    size_t pos = 0;
    parameters.clear();
    while(pos < url.size()){
        size_t nameEnd = url.find('=', pos);
        size_t valueEnd = url.find('&', pos);

        std::string name = url.substr(pos, nameEnd - pos);
        std::string value;
        if (valueEnd != std::string::npos) {
            value = url.substr(nameEnd + 1, valueEnd - nameEnd - 1);
        } else {
            value = url.substr(nameEnd + 1);
        }
        parameters[name] = value;

        if(valueEnd == std::string::npos){
            break;
        }
        pos = valueEnd + 1;
    }
}

void HandleRequest::replaceSpaces(){
    std::string replacement = " ";
    std::string target = "%20";
    size_t pos = 0;

    while((pos = path.find(target, pos)) != std::string::npos){
        path.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }
}

