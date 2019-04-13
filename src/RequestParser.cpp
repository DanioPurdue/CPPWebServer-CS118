#include <string>
#include <iostream>
#include <memory>
#include "../include/request.h"
#include "../include/RequestParser.h"
using namespace std;
unique_ptr<http::request> RequestParser::parseRequest(char * buff, int buff_size){
    int idx = 0;
    // find the header
    while (idx < buff_size) {
        if (idx + 1 < buff_size && buff[idx] == '\r' && buff[idx+1] == '\n') {
            break;
        }
        idx++;
    }
    if (idx == buff_size) {
        cerr << "invalid http request" << endl;
        return nullptr;
    }
    string header_str(buff, idx);
    cout << "testing header: " << header_str << endl;
    std::unique_ptr<http::request> req_ptr = make_unique<http::request>();
    return parseHeaderStr(header_str);
}

std::unique_ptr<http::request> RequestParser::parseHeaderStr(const std::string header_str) {
    if (header_str.length() == 0) return nullptr;
    std::unique_ptr<http::request> req_ptr = std::make_unique<http::request>();
    int start_idx = 0;
    //find http method
    int end_idx;
    if ((end_idx = header_str.find(" ", start_idx)) == -1) return nullptr;
    else {
        req_ptr->method = header_str.substr(start_idx, end_idx - start_idx);
        start_idx = end_idx + 1;
        cout << "testing method: " << req_ptr->method << endl;
    }
    // find http uri
    if ((end_idx = header_str.find(" ", start_idx)) == -1) return nullptr;
    else {
        req_ptr->uri = header_str.substr(start_idx, end_idx - start_idx);
        start_idx = end_idx + 1;
        cout<< "testing uri : "<< req_ptr->uri << endl;
    }
    return req_ptr;
}