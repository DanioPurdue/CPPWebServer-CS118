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
    int bytes_num = in_file.tellg();
    char file_content[bytes_num];
    in_file.seekg(0, ios::beg);
    in_file.read(file_content, bytes_num);
    in_file.close();
    string response_header = string("HTTP/1.1 200 OK \n") +
                             "Content-Length: " + to_string(bytes_num) + " \n" +
                             "Connection: close \n" +
                             "Content-Type: " + uri2type[type] + "\n charset=UTF-8\n" + "\r\n" + file_content;

    return response_header;
}
