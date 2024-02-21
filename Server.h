#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#include "Subject.h"
#include "Config.h"

struct Client{
    struct client_address;
    int clientSocket;
};

class Server : public Subject {
public:
//CONSTRUCTOR
    Server();

    void createSocket(int port);

//COMUNICATION
    void* receiveData(int socketIndex);
    static void* receiveDataStatic(void* context);

//GETTERS
    std::vector<char> getBufferFromQueue();

//DESTRUCTOR
    ~Server();

private:
    std::vector<int> sockets;

    std::queue<std::vector<char>> buffer_queue;

    std::vector<Client> clients;
};

#endif //SERVER_H