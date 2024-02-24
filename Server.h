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

#include "ThreadSafeQueue.h"
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


//DESTRUCTOR
    ~Server();


    std::vector<int> sockets;

    std::vector<char> img_buffer;
    std::vector<char> com_buffer;
    std::vector<char> set_buffer;

    std::vector<Client> clients;
};

#endif //SERVER_H