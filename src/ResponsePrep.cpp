#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
// #include <memory>
#include "../include/ResponsePrep.h"

using namespace std;
string ResponsePrep::getResponse(const string uri)
{
    string filename = static_dir_ + (uri).substr(1); //remove leading /, add static directory
    size_t type_pos = filename.rfind(".");
    string type = filename.substr(type_pos + 1);
    // string filename = uri2file["notFound"];
    // string type = uri2type["notFound"];
    ifstream in_file(filename, ios::in | ios::binary | ios::ate);
    if (!in_file)
    {
        // in_file.close();
        filename = uri2file["notFound"];
        type = "notFound";
        ifstream in_file2(filename, ios::in | ios::binary | ios::ate);
        if (!in_file2)
        {
            perror("fail to read the file not found");
            exit(1);
        }
        int bytes_num = in_file2.tellg();
        char file_content[bytes_num];
        in_file2.seekg(0, ios::beg);
        in_file2.read(file_content, bytes_num);
        in_file2.close();
        string response_header = string("HTTP/1.1 200 OK \n") +
                                 "Content-Length: " + to_string(bytes_num) + " \n" +
                                 "Connection: close \n" +
                                 "Content-Type: text/html\n charset=UTF-8\n" + "\r\n" + file_content;

        return response_header;
    }

    in_file.seekg(0, std::ios::end);
    size_t size = in_file.tellg();
    std::string body(size, ' ');
    in_file.seekg(0);
    in_file.read(&body[0], size);

    string body_len = to_string(size);
    string response_header = string("HTTP/1.1 200 OK \n") +
                             "Content-Length: " + body_len + " \n" +
                             "Connection: close \n" +
                             "Content-Type: " + uri2type[type] + "\n charset=UTF-8\n" + "\r\n" + body;

    return response_header;
}
