#include "modelWork.h"
#include <json/json.h>
#include <iostream>
#include <vector>
#include <unordered_map>


std::string modelListWork(std::map<std::string, std::string>& parameters, SqlServer* hcxServer){
    int offset = getOffset(parameters["pageIndex"]);
    std::cout<<offset<<std::endl;
    std::string sortType = sortTypeMp(parameters["sortType"]);
    std::cout<<sortType<<std::endl;
    std::vector<std::string>  labelList = getLabel(parameters);
    if(labelList.size() > 0 && parameters.count("name") == 0){
        handelModellistLabelQuery(labelList, hcxServer, sortType, offset);
        return handleModelListQueryResult(hcxServer);
    }
    else if(labelList.size() > 0 && parameters.count("name") == 1){
        handelModellistLabelNameQuery(labelList, hcxServer, sortType, offset, parameters);
        return handleModelListQueryResult(hcxServer);
    }

    if(parameters.count("name")){
        handleModeListNameQuery(parameters, hcxServer, sortType, offset);
    }
    else{
        std::string query = "select * from model order by " + sortType + " DESC limit 30 offset ?";
        std::cout<<query<<std::endl;
        hcxServer->preSearch(query);
        hcxServer->setParameter(1, offset);
        std::cout<<query<<std::endl;
    }

    return handleModelListQueryResult(hcxServer);
}

std::string modelLabelWork(SqlServer* hcxServer){
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

std::vector<std::string> extractPlusParameters(const std::string& str) {
    std::vector<std::string> parameters;
    std::string parameter;
    for (char c : str) {
        if (c == '+') {
            if (!parameter.empty()) {
                parameters.push_back(parameter);
                parameter.clear();
            }
        } else {
            parameter += c;
        }
    }
    if (!parameter.empty()) {
        parameters.push_back(parameter);
    }
    return parameters;
}

std::string handleModelListQueryResult(SqlServer* hcxServer){
    Json::Value tempAns = hcxServer->getResult();
    Json::Value tempString;
    Json::Value tempInString;
    tempInString["modelList"] = tempAns;
    tempInString["numTotalItems"] = tempAns.size();
    tempString["code"] = 1;
    tempString["msg"] = "liuming";
    tempString["data"] = tempInString;

    Json::FastWriter writer;
    std::string _content = writer.write(tempString);

    return _content;
}

void handleModeListNameQuery(std::map<std::string, std::string>& parameters, SqlServer* hcxServer, std::string sortType, int offset){
    std::string name = parameters["name"];
    std::vector<std::string> names = extractPlusParameters(name);
    
    std::string query = "select * from model where ";
    for(size_t i = 0; i < names.size(); i ++){
        query += "name like ?";

        if(i < names.size() - 1){
            query += " and ";
        }
    }
    query += " order by " + sortType + " desc limit 30 offset ?";
    hcxServer->preSearch(query);
    for(size_t i = 0; i < names.size(); i++){
        hcxServer->setParameter(i + 1, "%" + names[i] + "%");
    }
    hcxServer->setParameter(names.size() + 1, offset);
}


std::vector<std::string> getLabel(std::map<std::string, std::string>& parameters){
    std::vector<std::string> labelList;
    std::vector<std::string> labelTypeList = {"task", "library", "dataset", "other", "language"};
    for(auto & a : labelTypeList){
        std::string tempLabel = parameters[a];
        if(a == "") {
            continue;
        }
        else{
            extractCommaParameters(labelList, tempLabel);
        }
    }
    return labelList;
}

void extractCommaParameters(std::vector<std::string> &parameters, const std::string& str) {
    std::string parameter;
    for (char c : str) {
        if (c == ',') {
            if (!parameter.empty()) {
                parameters.push_back(parameter);
                parameter.clear();
            }
        } else {
            parameter += c;
        }
    }
    if (!parameter.empty()) {
        parameters.push_back(parameter);
    }
}


void handelModellistLabelQuery(std::vector<std::string> labelLists, SqlServer* hcxServer, std::string sortType, int offset){

    std::string query = "SELECT DISTINCT model.* FROM model";

    for (size_t i = 0; i < labelLists.size(); i++) {
        std::string labelList = labelLists[i];
        std::string labelAlias = "l" + std::to_string(i + 1);
        std::string label2ModelAlias = "lm" + std::to_string(i + 1);

        query += " JOIN label2model " + label2ModelAlias + " ON model.id = " + label2ModelAlias + ".model_id";
        query += " JOIN label " + labelAlias + " ON " + label2ModelAlias + ".lable_id = " + labelAlias + ".id";
        query += " AND " + labelAlias + ".label = '" + labelList + "'";
    }

    query += " order by model." + sortType + " desc limit 30 offset ?";
    hcxServer->preSearch(query);
    hcxServer->setParameter(1, offset);
}

std::string sortTypeMp(std::string sp){
    if(sp == "most-downloads") return "downloads";
    else if(sp == "recently-updated") return "lastModified";
}

void handelModellistLabelNameQuery(std::vector<std::string> labelLists, SqlServer* hcxServer, std::string sortType, int offset, std::map<std::string, std::string>& parameters){
    std::string query = "SELECT DISTINCT model.* FROM model";

    for (size_t i = 0; i < labelLists.size(); i++) {
        std::string labelList = labelLists[i];
        std::string labelAlias = "l" + std::to_string(i + 1);
        std::string label2ModelAlias = "lm" + std::to_string(i + 1);

        query += " JOIN label2model " + label2ModelAlias + " ON model.id = " + label2ModelAlias + ".model_id";
        query += " JOIN label " + labelAlias + " ON " + label2ModelAlias + ".lable_id = " + labelAlias + ".id";
        query += " AND " + labelAlias + ".label = '" + labelList + "'";
    }

    std::string name = parameters["name"];
    std::vector<std::string> names = extractPlusParameters(name);
    
    query += " where ";
    for(size_t i = 0; i < names.size(); i ++){
        query += ("model.name like '%" + names[i] + "%'");

        if(i < names.size() - 1){
            query += " and ";
        }
    }

    query += " order by model." + sortType + " desc limit 30 offset ?";
    std::cout<<query<<std::endl;
    hcxServer->preSearch(query);
    hcxServer->setParameter(1, offset);
}

int getOffset(std::string pageIndex){
    return 30 * (std::stoi(pageIndex) - 1);
}
