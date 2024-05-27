#ifndef SERVER_OBSERVER_H
#define SERVER_OBSERVER_H

#include "Display.h"
#include "Server.h"
#include "Observer.h"

class ServerObserver : public Observer {
public:
//CONSTRUCTOR
    ServerObserver(Display* display) : display(display) {}
    
//METHODS
    void update(Subject* subject) override;

private:
    Display* display;
};

#endif //SERVER_OBSERVER_H