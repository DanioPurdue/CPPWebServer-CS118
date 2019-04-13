#include <iostream>
#include <string>
#include <unordered_map>
#include "request.h"
class ResponsePrep {
    std::unordered_map<std::string, std::string> uri2file;
    std::unordered_map<std::string, std::string> uri2type;
    public:
    ResponsePrep() {
        uri2file["notFound"] = "staticFiles/notFound.html";
        uri2type["notFound"] = "text/html";
    }
    std::string getResponse(const std::string uri);
};