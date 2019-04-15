#pragma once
#include <string>
#include <memory>
#include "../include/request.h"
class RequestParser
{

public:
    std::unique_ptr<request> parseRequest(char *buff, int buff_size);
    std::unique_ptr<request> parseHeaderStr(const std::string header_str);
};