#ifndef DISPLAY_OBSERVER_H
#define DISPLAY_OBSERVER_H

#include "Display.h"
#include "Server.h"
#include "Observer.h"

class DisplayObserver : public Observer {
public:
    DisplayObserver(Display* display) : display(display) {}

    void update(Subject* subject) override;

private:
    Display* display;
};

#endif //DISPLAY_OBSERVER_H