#ifndef DISPLAY_OBSERVER_H
#define DISPLAY_OBSERVER_H

#include "Observer.h"
#include "Display.h"
#include "Server.h"

class DisplayObserver : public Observer {
public:
//CONSTRUCTOR
    DisplayObserver(Server* server) : server(server) {}

//METHODS
    void update(Subject* subject) override;

private:
    Server* server;
};

#endif //DISPLAY_OBSERVER_H