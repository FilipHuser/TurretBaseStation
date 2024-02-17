#include "Server.h"

Server::Server() : serverSocket(-1)
{
    if((this->serverSocket = socket(AF_INET , SOCK_DGRAM , 0)) < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    this->server_address.sin_family = AF_INET;
    this->server_address.sin_port = SERVER_PORT;
    this->server_address.sin_addr.s_addr = INADDR_ANY;

    if(bind(this->serverSocket , (struct sockaddr*)&this->server_address , sizeof(this->server_address)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    pthread_t com_thread;

    pthread_create(&com_thread , NULL , &Server::receiveData , this);




}

void* Server::receiveData(void* arg) {
    char buffer[1024];
    struct sockaddr_in client_address;
    socklen_t addr_len = sizeof(client_address);

    ssize_t received_bytes = recvfrom(this->serverSocket, buffer, sizeof(buffer), 0,
                                      (struct sockaddr*)&client_address, &addr_len);
    if (received_bytes < 0) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }

    buffer[received_bytes] = '\0';
    
    std::cout << "Received data from client: " << buffer << std::endl;

    pthread_exit(NULL);
}