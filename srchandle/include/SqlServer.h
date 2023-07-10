#pragma once
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <json/json.h>

class SqlServer
{
public:
    SqlServer();
    SqlServer(char* hostName, char* username, char* password, char* databasename);
    ~SqlServer();

    Json::Value getResult();
    Json::Value getResult(std::string query);
    Json::Value convertResultToJsonString(sql::ResultSet *result);
    void preSearch(std::string question);
    void setParameter(int index, std::string para);
    void setParameter(int index, int para);
    void executeUpdate();
private:
    sql::Driver *driver;
    sql::Connection *connection;
    sql::PreparedStatement *pstmt;
    sql::Statement *stmt;
    sql::ResultSet *result;
};
