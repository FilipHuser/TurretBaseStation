#include "Server.h"

Server::Server()
{
    createSocket(SERVER_CAM_PORT);     // CAM = camera socket
    createSocket(SERVER_COM_PORT);     // COM = communication socket
    createSocket(SERVER_SET_PORT);     // SET = settings socket

    createClient(TURRET_1_IP);


    std::cout << clients[0].addresses.size() << std::endl;

    std::cout << "Port: " << ntohs(clients[0].addresses[1].sin_port) << std::endl;
}

void Server::createClient(std::string clientIP)
{
    Client c;
    struct sockaddr_in client_address;

    memset(&client_address, 0, sizeof(client_address));
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = inet_addr(clientIP.c_str());
    client_address.sin_port = htons(CLIENT_CAM_PORT);

    c.addresses.push_back(client_address);

    memset(&client_address, 0, sizeof(client_address));
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = inet_addr(clientIP.c_str());
    client_address.sin_port = htons(CLIENT_COM_PORT);

    c.addresses.push_back(client_address);

    memset(&client_address, 0, sizeof(client_address));
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = inet_addr(clientIP.c_str());
    client_address.sin_port = htons(CLIENT_SET_PORT);

    c.addresses.push_back(client_address);

    this->clients.push_back(c);
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

    int flags = fcntl(serverSocket, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    flags |= O_NONBLOCK;
    if (fcntl(serverSocket, F_SETFL, flags) == -1) {
        perror("fcntl");
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
    std::cout << "Listening" << socketIndex <<std::endl;

    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in client_address;
    socklen_t addr_len = sizeof(client_address);

    while (shouldContinue())
    {
        ssize_t received_bytes = recvfrom(this->sockets[socketIndex], buffer, sizeof(buffer), 0,
                                          (struct sockaddr*)&client_address, &addr_len);

        if (received_bytes < 0)
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK) 
            { 
                continue; 
            } else {
                perror("recvfrom");
                break;
            }
        }

        switch(socketIndex)
        {
            case 0:
                this->cam_buffer.insert(this->cam_buffer.end(), buffer, buffer + received_bytes);
                notify(0);
                this->cam_buffer.clear();
            break;

            case 2:
                std::cout << buffer << std::endl;
            break;
        }
        memset(buffer , 0, sizeof(buffer));
    }
    pthread_exit(nullptr);
}

size_t Server::sendData(const char* data , int clientIndex , int socketIndex) 
{
    size_t bytesSent{0};
    if ((bytesSent = sendto(this->sockets[socketIndex], data, strlen(data), 0, (struct sockaddr*)&(this->clients[clientIndex].addresses[socketIndex]), sizeof(this->clients[clientIndex].addresses[socketIndex]))) < 0) 
    {
        perror("sendto");
        exit(EXIT_FAILURE);
    }
    return bytesSent;
}

size_t Server::sendData(std::vector<char> data , int clientIndex , int socketIndex) 
{
    size_t bytesSent{0};
    if ((bytesSent = sendto(this->sockets[socketIndex], data.data(), data.size(), 0, (struct sockaddr*)&(this->clients[clientIndex].addresses[socketIndex]), sizeof(this->clients[clientIndex].addresses[socketIndex]))) < 0) 
    {
        perror("sendto");
        exit(EXIT_FAILURE);
    }
    return bytesSent;
}


Server::~Server()
{
    for(auto& socket : this->sockets)
    {
        close(socket);
    }
}