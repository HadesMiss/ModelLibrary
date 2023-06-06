#pragma once
#include <iostream>
#include "SqlServer.h"

std::string loginWork(std::string body, SqlServer* hcxServer);
std::string verifyWork(std::string body, SqlServer* hcxServer);