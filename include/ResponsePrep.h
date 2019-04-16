#include <iostream>
#include <string>
#include <unordered_map>
#include "request.h"
class ResponsePrep
{
    std::unordered_map<std::string, std::string> uri2file;
    std::unordered_map<std::string, std::string> uri2type;

public:
    ResponsePrep()
    {
        uri2file["notFound"] = "staticFiles/notFound.html";
        uri2type["notFound"] = "text/html";
        uri2type["html"] = "text/html";
        uri2type["htm"] = "text/html";
        uri2type["txt"] = "text/html";
        uri2type["jpg"] = "image/jpeg";
        uri2type["jpeg"] = "image/jpeg";
        uri2type["png"] = "text/png";
        uri2type["gif"] = "image/gif";
    }
    std::string getResponse(const std::string uri);
    const std::string static_dir_ = "staticFiles/";
};