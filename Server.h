#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#include "Subject.h"
#include "Config.h"
#include "Dismissable.h"

#include <sys/time.h>
#include <ctime>

struct Client{
    std::vector<struct sockaddr_in> addresses; //3
};

class Server : public Subject , public Dismissable {
public:
//CONSTRUCTOR
    Server();

    void createSocket(int port);
    void createClient(std::string clientIP);

//METHODS
    size_t sendData(const char* data , int clientIndex , int socketIndex);
    size_t sendData(std::vector<char> data , int clientIndex , int socketIndex);
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
    std::vector<Client> clients;
};

#endif //SERVER_H