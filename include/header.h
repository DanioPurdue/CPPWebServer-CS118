// Based on original code from: 
// https://www.boost.org/doc/libs/1_69_0/doc/html/boost_asio/example/cpp11/http/server/header.hpp

#pragma once
#include <string>

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
