//
// request.h
// ~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Src:https://www.boost.org/doc/libs/1_69_0/doc/html/boost_asio/example/cpp11/http/server/request.hpp

#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "header.h"

namespace http
{
namespace server
{

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

} // namespace server
} // namespace http
