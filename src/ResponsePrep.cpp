#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sys/stat.h>
#include <regex>
#include "../include/ResponsePrep.h"
#include <arpa/inet.h>
#include <cstring>

using namespace std;
/**
 * prepare the response based on uri
 * caller it is the caller's responsibility 
 * to free the returned pointer  
 * 
 * @param uri, path of the file
 *        resp_size, pointer to the size of the returned response
 * @return char pointer that points to response size
 * 
 * */


char * ResponsePrep::getResponse(const string uri, int * resp_size)
{
    string filename = static_dir_ + (uri).substr(1); //remove leading /, add static directory
    size_t type_pos = filename.rfind(".");
    string type = filename.substr(type_pos + 1);
    filename = regex_replace(filename, std::regex("\\%20"), " "); //replace escape for spaces with space
    int file_size;
    char * file_content = file2StrSize_v2(filename, &file_size);
    int status_code = 200;
    if (file_content == nullptr)
    {
        filename = uri2file["notFound"];
        type = "html";
        file_content = file2StrSize_v2(filename, &file_size);
        if (file_content == nullptr)
        {
            perror("fail to read the file not found");
            exit(1);
        }
        status_code = 404;
    }
    string response_header = "HTTP/1.1 "+ to_string(status_code) +" OK \n" +
                             "Content-Length: " + to_string(file_size) + " \n" +
                             "Connection: close \n" +
                             "Content-Type: " + uri2type[type] 
                             + "\n" + "\r\n";
    *resp_size = response_header.length() + file_size;
    int header_size = response_header.length();
    char * response = new char[*resp_size];
    memcpy(response, response_header.c_str(), header_size);
    memcpy(response + header_size, file_content, file_size);
    if (file_content != nullptr) {
        delete [] file_content;
        file_content = nullptr;
    }
    return response;
}

/**
 * convert a file to a std::string, 
 * 
 * @param filename, name of the file
 *        file_size, int pointer that indicates the size of the returned file
 * @return char pointer that points to the loaded file
 * the strigified file and size_t is the size of the file,
 * size_t is 0 and string is empty if the file couldn't be found 
 * */

char * ResponsePrep::file2StrSize_v2(string filename, int * file_size)
{
    
    if (filename == static_dir_) {
        *file_size = -1;
        return nullptr;
    }
    ifstream in_file(filename, ios::in | ios::binary | ios::ate);
    if (!in_file)
    {
        *file_size = -1;
        return nullptr;
    }
    else {
        *file_size = in_file.tellg();
        char * file_content = new char[*file_size + 1];
        in_file.seekg(0, ios::beg);
        in_file.read(file_content, *file_size);
        file_content[*file_size] = '\0';
        in_file.close();
        return file_content;
    }
}