#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include <regex>
// #include <memory>
#include "../include/ResponsePrep.h"

using namespace std;
string ResponsePrep::getResponse(const string uri)
{
    string filename = static_dir_ + (uri).substr(1); //remove leading /, add static directory
    size_t type_pos = filename.rfind(".");
    string type = filename.substr(type_pos + 1);
    filename = regex_replace(filename, std::regex("\\%20"), " "); //replace escape for spaces with spaces

    pair<string, size_t> body = file2StrSize(filename);
    if (body.second == 0)
    {
        filename = uri2file["notFound"];
        type = "notFound";
        body = file2StrSize(filename);
        if (body.second == 0)
        {
            perror("fail to read the file not found");
            exit(1);
        }
    }

    string response_header = string("HTTP/1.1 200 OK \n") +
                             "Content-Length: " + to_string(body.second) + " \n" +
                             "Connection: close \n" +
                             "Content-Type: " + uri2type[type] + "\n charset=UTF-8\n" + "\r\n" + body.first;

    return response_header;
}

/**
 * convert a file to a std::string, 
 * 
 * @param filename, name of the file
 * @return std::pair<string, size_t> where string is
 * the strigified file and size_t is the size of the file,
 * size_t is 0 and string is empty if the file couldn't be found 
 * */
pair<string, size_t> ResponsePrep::file2StrSize(string filename)
{
    ifstream in_file(filename, ios::in | ios::binary | ios::ate);
    if (!in_file)
    {
        return make_pair("", 0);
    }

    in_file.seekg(0, std::ios::end);
    size_t size = in_file.tellg();
    std::string body(size, ' ');
    in_file.seekg(0);
    in_file.read(&body[0], size);

    return make_pair(body, size * 2);
    ;
}