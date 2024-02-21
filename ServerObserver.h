#ifndef SERVER_OBSERVER_H
#define SERVER_OBSERVER_H

#include <iostream>

#include "Observer.h"
#include "Server.h"
#include "EventHandler.h"

class ServerObserver : public Observer {
public:
    ServerObserver(EventHandler* eventHandler) : eventHandler(eventHandler) {}

    void update(Subject* Subject) override;

private:
    EventHandler* eventHandler;
};

#endif //SERVER_OBSERVER_H