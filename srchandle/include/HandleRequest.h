#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "SqlServer.h"
#include "UserWork.h"
#include <Connection.h>
#include <FileRAII.h>
#include "DatabaseConnectionPool.h"

class HandleRequest{
public:
    HandleRequest(DatabaseConnectionPool* pool_);
    explicit HandleRequest(std::vector<char> _request, Connection* conn, std::string _prePath = "./frontend/build");
    void translation();
    std::string response();
    void getResponse(std::string& _content, std::string& _contentType);
    void postResponse(std::string& _content, std::string& _contentType);
    std::string readFile(std::string _path, bool isBinary = false);
    void setprePath(std::string _prePath);
    void setrequest(std::vector<char> _request, Connection* conn);
    std::string getBody();
    ~HandleRequest();

    void parseURLParameters(const std::string& url);
private:

    void replaceSpaces();
    DatabaseConnectionPool* pool;
    Connection* con_;
    std::vector<char> requestRe;
    std::string method;
    std::string path;
    std::string httpVersion;
    std::vector<std::string> headers;
    std::vector<char> bodyRe;
    std::string prePath;
    std::map<std::string, std::string> parameters;
    std::map<std::string, std::string> headersMp;
    SqlServer *hcxServer;
    UserWork* userWork;
    bool needJWT = false;
    bool multipartUserInfo = false;

    std::string content;
    std::string contentType;
    std::string connection;
    std::string boundary;
    std::string body = "";


};