#include <string>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
class Client {
public:
    Client(){}
    
    Client(int port, std::string ip_addr) {
        this->server_port = port;
        this->server_ip_addr = ip_addr;
    }

    void set_ip(std::string ip) {
        this->server_ip_addr = ip;
    }

    void set_port(int port) {
        this->server_port = port;
    }

    int get_ip() {
        return this->server_port;
    }

    std::string get_port() {
        return this->server_ip_addr;
    }

    void set_message(std::string msg) {
        this->msg = msg;
    }

    std::string get_message() {
        return this->msg;
    }

    int init() {
        this->sock = socket(AF_INET, SOCK_STREAM, 0);
        this->srv.sin_family = AF_INET;
        this->srv.sin_port = htons(this->server_port);
        this->srv.sin_addr.s_addr = inet_addr(this->server_ip_addr.c_str());
        return 0;
    }

    int connect_and_send() {
        connect(this->sock, (struct sockaddr*)&this->srv, sizeof(this->srv));
        send(this->sock, this->msg.c_str(), sizeof(this->msg), 0);
        return 0;
    }

private:
    int server_port;
    int sock;
    struct sockaddr_in srv;
    std::string server_ip_addr;
    std::string msg;

};

int main() {
    Client c(8080, "127.0.0.1");
    c.set_message("aaabbb");
    c.init();
    c.connect_and_send();

}