#include "ResponseMessage.h"


ResponseMessage::ResponseMessage(std::string raw_response_message){
    // TO BE FINISHED
    std::size_t left = raw_response_message.find("\r\n");
    std::size_t right = raw_response_message.find("\r\n\r\n");
    _status_line.assign(raw_response_message.begin(), raw_response_message.begin() + left);
    _message_payload.assign(raw_response_message.begin() + right + 4, raw_response_message.end());

    parse_status_line(_status_line);

}

std::string ResponseMessage::get_status_line(){
    return _status_line;
}

std::string ResponseMessage::get_response_header(){
    return _response_header;
}

std::string ResponseMessage::get_message_payload(){
    return _message_payload;
}

std::string ResponseMessage::get_http_version(){
    return _http_version;
}

int ResponseMessage::get_status_code(){
    return _status_code;
}

std::string ResponseMessage::get_status_code_description(){
    return _status_code_description;
}

std::unordered_map<std::string, std::string> ResponseMessage::get_response_header_fields(){
    return _response_header_fields;
}

