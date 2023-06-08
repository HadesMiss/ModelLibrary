#include "HandleRequest.h"
#include <fstream>
#include <iostream>
#include <json/json.h>
#include "modelWork.h"
#include "datasetWork.h"

HandleRequest::HandleRequest() : prePath("./frontend/build"){
    hcxServer = new SqlServer();
    userWork = new UserWork(hcxServer);
    printf("\n sql server success");
}

HandleRequest:: HandleRequest(std::string _request, std::string _prePath) : request(_request), prePath(_prePath){
    hcxServer = new SqlServer();
    userWork = new UserWork(hcxServer);
    translation();
}

HandleRequest::~HandleRequest(){
    delete hcxServer;
    delete userWork;
}

void HandleRequest::translation(){
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

    // 解析报文正文
    std::stringstream bodyStream;
    bodyStream << iss.rdbuf();
    body = bodyStream.str();
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

    if(method == "GET"){
        getResponse(content, contentType);
    }
    else if(method == "POST"){
        postResponse(content, contentType);
    }
    else{
        content = "NO GET OR POST";
    }
    std::cout<<"content"<<std::endl;
    std::string responseContent =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: "+ contentType + "\r\n"
        "Content-Length: " + std::to_string(content.length()) + "\r\n"
        "Connection: " + connection + "\r\n";

    if (needJWT) {
        responseContent += "Authorization: " + userWork->getJwtToken() + "\r\n";
        needJWT = false;
    }

    responseContent += "\r\n" + content;

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
    else if(path.find(".js") != std::string::npos){
        _contentType = "application/javascript";
        _content = readFile(prePath + path);
    }
    else if(path == "/api/personalInformation"){
        needJWT = true;
        _contentType = "application/javascript";
        _content = userWork->personalInformation(headersMp["Authorization"]);
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
        else if(path.find(".png") != std::string::npos){
            _contentType = "image/png";
        }
        else{
            _contentType = "text/plain";
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
    else if(path == "/api/verifyUsername"){
        _content = userWork->verifyWork(body);
        _contentType = "text/plain";
    }

}

std::string HandleRequest::readFile(std::string path, bool isBinary) {
    if(isBinary == true){
        std::ifstream file(path, std::ios::binary);
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }
    else{
        std::ifstream file(path);
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }

}

void HandleRequest::setprePath(std::string _prePath){
    prePath = _prePath;
    translation();
}

void HandleRequest::setrequest(std::string _request){
    request = _request;
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

