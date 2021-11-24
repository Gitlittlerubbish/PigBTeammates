#include "ResponseMessage.h"


ResponseMessage(std::string){
    // TODO;
}

std::string ResponseMessage::get_status_line(){
    return _status_line;
}

std::string ResponseMessage::get_response_header(){
    return _response_header;
}

unsigned char *ResponseMessage::get_message_payload(){
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

std::unordered_map ResponseMessage::get_response_header_fields(){
    return get_response_header_fields;
}

