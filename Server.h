#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>

#include "Config.h"

struct Client{
    struct client_address;
    int clientSocket;
};

class Server{
public:
    Server();
    void* receiveData();
    static void* receiveDataStatic(void* context);

private:
    int serverSocket;
    struct sockaddr_in server_address;
    std::vector<Client> clients;
};

#endif //SERVER_H