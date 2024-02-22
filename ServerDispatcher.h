#ifndef SERVER_DISPATCHER_H
#define SERVER_DISPATCHER_H

#include "Server.h"

class ServerDispatcher {
public:
    ServerDispatcher(Server* server) : server(server) {}

    static void* dispatchStatic(void* context);
    void* dispatch();

private:
    Server* server;
};

#endif //SERVER_DISPATCHER_H