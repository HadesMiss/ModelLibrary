#include "HandleRequest.h"
#include <fstream>
#include <iostream>
#include <json/json.h>
#include "modelWork.h"
#include "datasetWork.h"
#include <Connection.h>
#include <Buffer.h>
#include <DatabaseConnectionPool.h>
#include "DatabaseConnectionPool1.h"
#include <cstdlib>
#include <future>

HandleRequest::HandleRequest(DatabaseConnectionPool* pool_) : prePath("./frontend/build"){
    pool = pool_;
    userWork = new UserWork(hcxServer);
    printf("\n sql server success");
    myRedis = std::make_unique<RedisDb>();
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
    originPath = path;
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
        long long length = stoll(headersMp["Content-Length"]);
        std::cout<<"length"<<std::endl;
        while(bodyRe.size() < length){
            con_->Read();
            std::vector<char> buf_ = con_->read_buf()->bufOrigin();
            bodyRe.insert(bodyRe.end(), buf_.begin(), buf_.end());
            std::cout << "Message1 from client \n" << bodyRe.size()<< std::endl;
            //std::cout << "Message1 from client \n" << bodyRe.data()<< std::endl;
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
        if(myRedis->check(originPath)){
            _content = myRedis->getValue(originPath);
        }
        else{
            _content = modelListWork(parameters, hcxServer);
            myRedis->set(originPath, _content);
        }
        _contentType = "application/javascript";
    }
    else if(path == "/api/modelLabel"){
        if(myRedis->check(originPath)){
            _content = myRedis->getValue(originPath);
        }
        else{
            _content = modelLabelWork(hcxServer);
            myRedis->set(originPath, _content);
        }
        _contentType = "application/javascript";
    }
    else if(path == "/api/datasetList"){
        if(myRedis->check(originPath)){
            _content = myRedis->getValue(originPath);
        }
        else{
            _content = datasetListWork(parameters, hcxServer);
            myRedis->set(originPath, _content);
        }
        _contentType = "application/javascript";
    }
    else if(path == "/api/datasetLabel"){
        if(myRedis->check(originPath)){
            _content = myRedis->getValue(originPath);
        }
        else{
            _content = datasetLabelWork(hcxServer);
            myRedis->set(originPath, _content);
        }
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
    else if(path == "/playground"){
        std::ofstream file("/home/python_projects/ner_playground/predict/input.txt", std::ios::out);
        std::string gg = "全国GDP80亿$，吉尔吉斯纠结中国铁路《环球时报》报道，5月30日，吉尔吉斯斯坦总统扎帕罗夫接受当地媒体采访，，表示自己刚刚在莫斯科参加了集安组织峰会，他和普京恳谈了中吉乌铁路问题。中吉乌铁路的“乌”不是正在打仗的乌克兰，而是吉尔吉斯西面的乌兹别克斯坦。这是一条从中国最西部城市喀什出发，向西面里海方向延伸的铁路。按扎帕罗夫的说法，他对普京表示，中吉乌铁路对吉尔吉斯斯坦就像“空气和水”一样重要。而普京表示“不反对建设这一铁路”。拿到普京的不干预承诺之后，扎帕罗夫总统宣布，2023年开建中吉乌铁路。督工你怎么看这条铁路的前景？俄罗斯的抵制，并不是中吉乌铁路唯一的障碍。虽然普京这次明确答应不再阻挠，但中吉乌铁路的前景还有很多其他变数，不能太乐观。中吉乌铁路计划最早出现在1997年，中国利用“欧洲—高加索—亚洲运输走廊组织”这个平台，在巴黎会议上提出中吉乌铁路规划。在中国积极推动下，中吉乌三国当年就联通三国的铁路项目签署了备忘录。1999年，按照中国铁道部的安排,铁道部第一勘测设计院做出了《新建中吉乌国际铁路建设方案-中国境内段可行性研究报告》。虽然只规划了中国境内的铁路，但还是考虑了全线布局，提出了南、北两个方案。从国际交通地理来说，中吉乌铁路是新亚欧大陆桥规划的重要补充，在帕米尔高原最窄的地方打穿山地，把中国和里海、咸海平原地区连通起来。铁路进入中亚平原地区之后，下一步无论是绕里海南面的伊朗方向，还是继续绕北面从哈萨克斯坦、俄罗斯去欧洲，中国都可以选择和不同的国家谈判，走比较优惠的线路。2006年，中国将中吉乌铁路的中国段计划列入了经济发展五年计划。经过三个国家沟通，2008年中国专家组最终确认最终采用南线方案，全长523公里，东部起点是喀什，在中国境内213公里，吉尔吉斯斯坦境内260公里，最后在乌兹别克斯坦境内再延伸50 公里就到达安集延，进入中亚最富饶、人口最密集的费尔干纳盆地。从项目里程来看，政治上最大的难点就是让吉尔吉斯斯坦同意。至少在2008年，吉尔吉斯斯坦官方确认了路线走向。但是接下来十几年，不仅工程没有推进，项目研究都基本停滞，只是每隔几年互联网上会重新提一下还有这么个项目。这次网上重新提起中吉乌铁路，原因是吉尔吉斯斯坦总统声称铁路得到了普京的认可。有人说，几十年来铁路一直没有推进，原因是俄罗斯不愿意中国经济影响力进入中亚，是这样吗？";
        if(file.is_open()){
            file << gg;
            file.close();
        }
        std::string ccm = "docker run --rm -v /home/python_projects/ner_playground:/home/python_projects/ner_playground -v /root/.cache/huggingface/hub:/root/.cache/huggingface/hub --shm-size 4G --gpus all dl_env_base:v1.0 python3 /home/python_projects/ner_playground/src/predict.py";
        myRedis->push("message_queue", ccm);
        // auto systemTask = [](){system(" docker run --rm -v /home/python_projects/ner_playground:/home/python_projects/ner_playground -v /root/.cache/huggingface/hub:/root/.cache/huggingface/hub --shm-size 4G --gpus all dl_env_base:v1.0 python3 /home/python_projects/ner_playground/src/predict.py");
        // };
        //std::async(std::launch::async, systemTask);
        //std::thread backgroundThread(systemTask);
        //backgroundThread.detach();
        //std::ifstream file1("/home/python_projects/ner_playground/predict/output.json");
        //std::string content1((std::istreambuf_iterator<char>(file1)), std::istreambuf_iterator<char>());
        //std::cout<<"hello everyone"<<std::endl;
        _content = "is doing something";
        _contentType = "text/plain";
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
    //std::cout<<"hello everyone2"<<std::endl;
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

