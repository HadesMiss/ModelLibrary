#pragma once
#include <string>
#include <map>
#include "SqlServer.h"

std::string datasetListWork(std::map<std::string, std::string>& parameters, SqlServer* hcxServer);
std::string datasetLabelWork(SqlServer* hcxServer);