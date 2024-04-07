#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <iostream>
#include <fcntl.h>
#include <linux/joystick.h>

#include "Subject.h"
#include "Dismissable.h"
#include "Config.h"

class Joystick : public Subject , public Dismissable{
public:
//CONSTRUCTOR
    Joystick();

//METHODS
    static void* monitorJoystickStatic(void* context);
    void* monitorJoystick();

//GETTERS
    struct js_event get_joystick() { return this->joystick; }

private:
    int fd;
    struct js_event joystick;
};

#endif //JOYSTICK_H