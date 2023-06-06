#pragma once
#include <string>
#include <map>
#include "SqlServer.h"
#include <vector>

std::string sortTypeMp(std::string sp);


std::string modelListWork(std::map<std::string, std::string>& parameters, SqlServer* hcxServer);
std::string modelLabelWork(SqlServer* hcxServer);
std::vector<std::string> extractPlusParameters(const std::string& str);
void extractCommaParameters(std::vector<std::string> &parameters, const std::string& str);
void handelModellistLabelQuery(std::vector<std::string> labelList, SqlServer* hcxServer, std::string sortType, int offset);
std::vector<std::string> getLabel(std::map<std::string, std::string>& parameters);
void handleModeListNameQuery(std::map<std::string, std::string>& parameters, SqlServer* hcxServer, std::string sortType, int offset);
std::string handleModelListQueryResult(SqlServer* hcxServer);
int getOffset(std::string pageIndex);

void handelModellistLabelNameQuery(std::vector<std::string> labelLists, SqlServer* hcxServer, std::string sortType, int offset, std::map<std::string, std::string>& parameters);