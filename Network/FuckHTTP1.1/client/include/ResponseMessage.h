#ifndef __RESPONSEMESSAGE_H__
#define __RESPONSEMESSAGE_H__

#include <cstdio>
#include <iostream>

class ResponseMessage{
    
public:
    ResponseMessage() = default;
    ResponseMessage(std::string);
    
    std::string get_status_line();
    std::string get_response_header();
    unsigned char *get_message_payload();
    std::string get_http_version();
    int get_status_code();
    std::string get_status_code_description();
    std::unordered_map get_response_header_fields();

    
private:
    std::string _status_line;
    std::string _response_header;
    unsigned char *_message_payload;

    std::string _http_version;
    int _status_code;
    std::string _status_code_description;
    std::unordered_map response_header_fields;


};


#endif