#include "Server.h"

Server::Server()
{
    createSocket(SERVER_CAM_PORT);     // CAM = camera socket
    createSocket(SERVER_COM_PORT);     // COM = communication socket
    createSocket(SERVER_SET_PORT);     // SET = settings socket
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
    server_address.sin_port = htons(port);
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

    if (!args)
    {
        std::cerr << "Static cast was not sucessfull !" << std::endl;
        pthread_exit(nullptr);
    }

    int socketIndex = args->first;
    Server* server = args->second;

    return server->receiveData(socketIndex);
}

void* Server::receiveData(int socketIndex)
{
    std::cout << "Listening on sokcet: " << this->sockets[socketIndex] << std::endl;


    char buffer[MAX_BUFFER_SIZE];
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

        this->buffer_queue.push(std::vector<char>(buffer , buffer + received_bytes));

        //std::cout << this->buffer_queue.size() << std::endl;

        memset(buffer , 0, sizeof(buffer));
    }
}

Server::~Server()
{
    for(auto& socket : this->sockets)
    {
        close(socket);
    }
}