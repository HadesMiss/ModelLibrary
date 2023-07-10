#include "SqlServer.h"
#include <iostream>


SqlServer::SqlServer(){
    driver = get_driver_instance();
    connection = driver->connect("tcp://127.0.0.1:3306", "root", "hcx159263");
    connection->setSchema("yourdb");
}

SqlServer::SqlServer(char* hostName, char* username, char* password, char* databasename){
    driver = get_driver_instance();
    connection = driver->connect(hostName, username, password);
    connection->setSchema(databasename);
}

SqlServer::~SqlServer(){
    delete result;
    delete pstmt;
    delete stmt;
    delete connection;
    printf("\n sql server disconnect");
}

void SqlServer::preSearch(std::string question){
    pstmt = connection->prepareStatement(question);
}

void SqlServer::setParameter(int index, std::string para){
    pstmt->setString(index, para);
}

void SqlServer::setParameter(int index, int para){
    pstmt->setInt(index, para);
}

Json::Value SqlServer::getResult(std::string query){
    stmt = connection->createStatement();
    result = stmt->executeQuery(query);

    return convertResultToJsonString(result);
}


Json::Value SqlServer::getResult(){
    result = pstmt->executeQuery();
    return convertResultToJsonString(result);
}

void SqlServer::executeUpdate(){
    pstmt->executeUpdate();
}


Json::Value SqlServer::convertResultToJsonString(sql::ResultSet *result){
    Json::Value jsonResult;
    Json::Value jsonData;

    // 获取结果集的元数据
    sql::ResultSetMetaData *metaData = result->getMetaData();

    // 获取列数
    int columnCount = metaData->getColumnCount();

    // 循环遍历每一行
    while (result->next()) {
        jsonData = Json::Value(Json::objectValue);

        // 遍历每一列，并将其添加到 JSON 对象中
        for (int i = 1; i <= columnCount; i++) {
            std::string columnName = metaData->getColumnLabel(i);
            std::string columnValue = result->getString(i);

            jsonData[columnName] = columnValue;
        }

        jsonResult.append(jsonData);
    }
    return jsonResult;
}