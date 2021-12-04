#ifndef __HTTPCLIENT_H__
#define __HTTPCLIENT_H__

#include <iostream>
#include <string>
#include "RequestMessage.h"
#include "ResponseMessage.h"

class HttpClient{
    
public:
    int startTcpConnection();
    int closeTcpConnection();
    void setServerIp();
    int getServerIp();
    void setServerPort();
    int getServerPort();
    RequestMessage createRequestMessage();
    int sendMessage(RequestMessage rm);
    ResponseMessage receiveMessage();

    
private:
    std::string _server_domain;
    int _server_ip;
    int _server_port;
    int _socket_fd;

};


#endif