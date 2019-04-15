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
        uri2type["jpg"] = "text/html";
        uri2type["jpeg"] = "text/html";
        uri2type["png"] = "text/html";
        uri2type["gif"] = "text/html";
    }
    std::string getResponse(const std::string uri);
    const std::string static_dir_ = "staticFiles/";
};