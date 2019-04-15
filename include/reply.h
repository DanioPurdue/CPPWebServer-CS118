
// Based on original code from: 
// https://www.boost.org/doc/libs/1_69_0/doc/html/boost_asio/example/cpp11/http/server/reply.hpp


#pragma once
#include <string>
#include <vector>
#include "header.h"

/// A reply to be sent to a client.
struct reply
{
    /// The status of the reply.
    enum status_type
    {
        ok = 200,
        bad_request = 400,
        not_found = 404,
    } status;

    /// The headers to be included in the reply.
    std::vector<header> headers;

    /// The content to be sent in the reply.
    std::string content;
};
