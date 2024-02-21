#include "Server.h"

Server::Server()
{
    createSocket(1025);     // CAM = camera socket
    createSocket(1026);     // COM = communication socket
    createSocket(1027);     // SET = settings socket
}

void Server::createSocket(int port)
{
    struct sockaddr_in server_address;
    int serverSocket = -1;

    if((serverSocket = socket(AF_INET , SOCK_DGRAM , 0)) < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = port;
    server_address.sin_addr.s_addr = INADDR_ANY;

    if(bind(serverSocket , (struct sockaddr*)&server_address , sizeof(server_address)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    this->sockets.push_back(serverSocket);
}


void* Server::receiveDataStatic(void* context)
{
   std::pair<int , Server*>* args = static_cast<std::pair<int , Server*>*>(context); 

    int socketIndex = args->first;
    Server* server = args->second;

    return server->receiveData(socketIndex);
}

void* Server::receiveData(int socketIndex)
{
    char buffer[1024];
    struct sockaddr_in client_address;
    socklen_t addr_len = sizeof(client_address);

    while (true)
    {
        ssize_t received_bytes = recvfrom(this->sockets[socketIndex], buffer, sizeof(buffer), 0,
                                          (struct sockaddr*)&client_address, &addr_len);
        if (received_bytes < 0)
        {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        std::cout << "Received data from client: " << buffer << std::endl;
    }

    pthread_exit(nullptr);
}

Server::~Server()
{
    for(auto& socket : this->sockets)
    {
            close(socket);
    }
}