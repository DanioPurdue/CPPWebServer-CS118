//
// header.hpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once
#include <string>

namespace http
{
namespace server
{

struct header
{   
    std::string name;
    std::string value;
public:
    header() {} // keep default constructor
    header(std::string n, std::string v) 
    {
        name = n;
        value = v;
    }
};

} // namespace server
} // namespace http

// HTTP_HEADER_HPP