#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#include "Subject.h"
#include "Config.h"
#include "Dismissable.h"

struct Client{
    struct client_address;
};

class Server : public Subject , public Dismissable {
public:
//CONSTRUCTOR
    Server();

    void createSocket(int port);

//METHODS
    size_t sendData(const char* data , int clientIndex);
    size_t sendData(std::vector<char> data , int clientIndex);
    void* receiveData(int socketIndex);
    static void* receiveDataStatic(void* context);

//GETTERS
    std::vector<char>& getCamBuffer() { return this->cam_buffer; }

//DESTRUCTOR
    ~Server();

private:
    std::vector<int> sockets;

    std::vector<char> cam_buffer;
    std::vector<char> com_buffer;
    std::vector<char> set_buffer;

    std::vector<struct sockaddr_in> client_addresses;
};

#endif //SERVER_H