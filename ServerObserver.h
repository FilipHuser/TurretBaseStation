#ifndef DISPLAY_OBSERVER_H
#define DISPLAY_OBSERVER_H

#include "Display.h"
#include "Server.h"
#include "Observer.h"

class ServerObserver : public Observer {
public:
    ServerObserver(Display* display) : display(display) {}

    void update(Subject* subject) override;

private:
    Display* display;
};

#endif //DISPLAY_OBSERVER_H