#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include "../include/ResponsePrep.h"

using namespace std;
string ResponsePrep::getResponse(const string uri) {
    string filename = uri2file["notFound"];
    string type = uri2type["notFound"];
    ifstream in_file(filename, ios::in | ios::binary | ios::ate);
    if (!in_file) {
        perror("fail to read the file");
        exit(1); 
    }
    int bytes_num = in_file.tellg();
    char file_content [bytes_num];
    in_file.seekg(0, ios::beg);
    in_file.read(file_content, bytes_num);
    in_file.close();
    string response_header = string("HTTP/1.1 200 OK \n")
                             + "Content-Length: " + to_string(bytes_num) + " \n"
                             + "Connection: close "
                             + "Content-Type: text/html; charset=UTF-8\n"
                             + "\r\n"
                             + file_content;

    return  response_header;

}