#ifndef __RESPONSEMESSAGE_H__
#define __RESPONSEMESSAGE_H__

#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

class ResponseMessage{
    
public:
    ResponseMessage() = default;
    ResponseMessage(std::string raw_response_message);
    
    std::string get_status_line();
    std::string get_response_header();
    std::string get_message_payload();
    std::string get_http_version();
    int get_status_code();
    std::string get_status_code_description();
    std::unordered_map<std::string, std::string> get_response_header_fields();

    
private:
    std::string _status_line;
    std::string _response_header;
    std::string _message_payload;

    std::string _http_version;
    int _status_code;
    std::string _status_code_description;
    std::unordered_map<std::string, std::string> _response_header_fields;

    inline void parse_status_line(std::string sl) {
        std::stringstream str2int;
        std::string tmp_status_code_str;

        std::size_t left = sl.find(" "), right = sl.rfind(" ");

        _http_version.assign(sl.begin(), sl.begin() + left);


        tmp_status_code_str.assign(sl.begin() + left, sl.begin() + right);
        str2int << tmp_status_code_str; str2int >> _status_code;
        
        _status_code_description.assign(sl.begin() + right + 1, sl.end());
}

};



#endif