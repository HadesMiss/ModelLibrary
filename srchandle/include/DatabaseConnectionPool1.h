#pragma once
#include<iostream>
#include<vector>
#include<SqlServer.h>
#include<mutex>


class DatabaseConnectionPool1{
private:
    DatabaseConnectionPool1() {
        initializePool();
    }

     ~DatabaseConnectionPool1() {
        for (SqlServer* connection : connections) {
            delete(connection);
        }
        connections.clear();
    }

    void initializePool() {
        for (int i = 0; i < maxConnections; ++i) {
            SqlServer* connection = createConnection();
            if (connection != nullptr) {
                connections.push_back(connection);
            }
        }
    }

    SqlServer* createConnection() {
        SqlServer* connection = new SqlServer();
        return connection;
    }

    const int maxConnections = 10;
    std::vector<SqlServer*> connections;
    std::mutex connectionsMutex;
public:
    static DatabaseConnectionPool1& getInstance(){
        static DatabaseConnectionPool1 instance;
        return instance;
    }

    SqlServer* getConnection() {
        std::cout<<"getConnection"<<std::endl;
        std::lock_guard<std::mutex> lock(connectionsMutex);
        if (connections.empty()) {
            SqlServer* connection = createConnection();
            return connection;
        } else {
            SqlServer* connection = connections.back();
            connections.pop_back();
            return connection;
        }
    }

    void releaseConnection(SqlServer* connection) {
        std::lock_guard<std::mutex> lock(connectionsMutex);
        connections.push_back(connection);
        std::cout<<"releaseconnection"<<std::endl;
    }
};
