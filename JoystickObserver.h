#ifndef JOYSTICK_OBSERVER_H
#define JOYSTICK_OBSERVER_H

#include <iostream>
#include <linux/joystick.h>
#include <string>
#include <cmath>

#include "Joystick.h"
#include "Observer.h"
#include "Server.h"

class JoystickObserver : public Observer {
public:
//CONSTRUCTOR
    JoystickObserver(Server* server) : server(server) {};

//METHODS
    void update(Subject* subject) override;

private:
    Server* server;
};

#endif //JOYSTICK_OBSERVER_H