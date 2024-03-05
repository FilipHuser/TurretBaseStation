#ifndef JOYSTICK_OBSERVER_H
#define JOYSTICK_OBSERVER_H

#include <string>

#include "Joystick.h"
#include "Observer.h"
#include "Server.h"

class JoystickObserver : public Observer {
public:
    JoystickObserver(Server* server) : server(server) {};

    void update(Subject* subject) override;

private:
    Server* server;
};

#endif //JOYSTICK_OBSERVER_H