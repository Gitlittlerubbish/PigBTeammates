#include <iostream>
#include <string>

#include "ResponseMessage.h"

int main(int argc, const char *argv[])
{
    std::string test_response_message = "HTTP/1.1 200 OK\r\n"
                               "Date: Thu, 02 Dec 2021 12:02:02 GMT\r\n"
                               "Content-Type: application/json\r\n"
                               "Content-Length: 285\r\n"
                               "Connection: close\r\n"
                               "Server: gunicorn/19.9.0\r\n"
                               "Access-Control-Allow-Origin: *\r\n"
                               "Access-Control-Allow-Credentials: true\r\n\r\n"
                               "FUCK_THIS_IS_THE_TEST_PAYLOAD";

    // std::cout << "The test response message is:\n----------------------------\n" << test_response_message << std::endl;


    ResponseMessage test_rm = ResponseMessage(test_response_message);
    
    // std::cout << "Parsed status line:\n" << test_rp.get_status_line() << std::endl;
    std::cout << "Parsed message payload:\t" << test_rm.get_message_payload() << std::endl;
    std::cout << "http version:\t" << test_rm.get_http_version() << std::endl;
    std::cout << "status code:\t" << test_rm.get_status_code() << std::endl;
    std::cout << "status code description:\t" << test_rm.get_status_code_description() << std::endl;

    return 0;
}