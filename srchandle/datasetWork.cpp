#include "datasetWork.h"
#include <json/json.h>
#include <iostream>

std::string datasetListWork(std::map<std::string, std::string>& parameters, SqlServer* hcxServer){
    std::string pageIndex = parameters["pageIndex"];
    std::string sortType = parameters["sortType"];
    std::string name = "";
    if(parameters.count("name")){
        name = parameters["name"];
    }
    if(sortType == "most-downloads") sortType = "downloads";
    else sortType = "lastModified";

    std::string offset = std::to_string(30 * (std::stoi(pageIndex) - 1));
    std::string query;
    if(name == ""){
        query = "select * from model order by " + sortType + " desc limit 30 offset ?";
        hcxServer->preSearch(query);
        hcxServer->setParameter(1, offset);
    }
    else{
        if(name.find('+') == std::string::npos){
            query = "select * from model where name like ? order by " + sortType + " desc limit 30 offset ?";
            hcxServer->preSearch(query);
            hcxServer->setParameter(1, "%" + name + "%");
            hcxServer->setParameter(2, offset);
        }
    }

    Json::Value tempAns = hcxServer->getResult();
    Json::Value tempString;
    Json::Value tempInString;
    tempInString["datasetList"] = tempAns;
    tempInString["numTotalItems"] = tempAns.size();
    tempString["code"] = 1;
    tempString["msg"] = "liuming";
    tempString["data"] = tempInString;

    Json::FastWriter writer;
    std::string _content = writer.write(tempString);

    return _content;
}

std::string datasetLabelWork(SqlServer* hcxServer){
    Json::Value jsonString;

    std::string query = "select * from label";
    Json::Value tempAns = hcxServer->getResult(query.c_str());
    for(auto& jv : tempAns){
        jsonString["data"][jv["type"].asString()].append(jv["label"].asCString());
    }

    jsonString["code"] = 1;
    jsonString["mas"] = " ";

    Json::FastWriter writer;
    std::string _content = writer.write(jsonString);

    return _content;
}