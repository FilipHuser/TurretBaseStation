#ifndef SERVER_DISPATCHER_H
#define SERVER_DISPATCHER_H

#include <vector>

#include "Server.h"
#include "Subject.h"

class ServerDispatcher : public Subject{
public:
    ServerDispatcher() = default;

    static void* dispatchStatic(void* context);
    void* dispatch();

private:
};

#endif //SERVER_DISPATCHER_H