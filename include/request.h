// Based on original code from: 
// https://www.boost.org/doc/libs/1_69_0/doc/html/boost_asio/example/cpp11/http/server/request.hpp

#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "header.h"

struct request
{
  std::string method;
  std::string uri;
  std::string body;
  int http_version_major;
  int http_version_minor;
  std::unordered_map<std::string, std::string> headers;
  const char *raw_request;
};
