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
    char * getResponse(const std::string uri, int * resp_size);
    const std::string static_dir_ = "staticFiles/";

private:
    std::pair<std::string, size_t> file2StrSize(std::string filename);
    char * file2StrSize_v2(std::string filename, int * file_size);
};