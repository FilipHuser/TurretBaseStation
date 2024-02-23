#ifndef SERVER_DISPATCHER_H
#define SERVER_DISPATCHER_H

#include <vector>

#include "Server.h"

class ServerDispatcher {
public:
    ServerDispatcher(Server* server) : server(server) {}

    static void* dispatchStatic(void* context);
    void* dispatch();
    void addToImgBuffer(std::vector<char>);

private:
    Server* server;

    std::vector<char> img_buffer;
};

#endif //SERVER_DISPATCHER_H