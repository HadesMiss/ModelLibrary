#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "SqlServer.h"
#include "UserWork.h"

class HandleRequest{
public:
    HandleRequest();
    explicit HandleRequest(std::string _request, std::string _prePath = "./frontend/build");
    void translation();
    std::string response();
    void getResponse(std::string& _content, std::string& _contentType);
    void postResponse(std::string& _content, std::string& _contentType);
    std::string readFile(std::string _path, bool isBinary = false);
    void setprePath(std::string _prePath);
    void setrequest(std::string _request);
    std::string getBody();
    ~HandleRequest();

    void parseURLParameters(const std::string& url);
private:

    void replaceSpaces();


    std::string request;
    std::string method;
    std::string path;
    std::string httpVersion;
    std::vector<std::string> headers;
    std::string body;
    std::string prePath;
    std::map<std::string, std::string> parameters;
    std::map<std::string, std::string> headersMp;
    SqlServer *hcxServer;
    UserWork* userWork;
    bool needJWT = false;


    std::string content;
    std::string contentType;
    std::string connection;


};