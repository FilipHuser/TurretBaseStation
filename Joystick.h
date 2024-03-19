#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <iostream>
#include <fcntl.h>
#include <linux/joystick.h>

#include "Subject.h"
#include "Config.h"
#include "unistd.h"

class Joystick : public Subject {
public:
    Joystick();

    static void* monitorJoystickStatic(void* context);
    void* monitorJoystick();

    struct js_event get_joystick() { return this->joystick; }

    void dismiss() { this->loop = 0; }

private:
    int fd;
    struct js_event joystick;
    bool loop;
};

#endif //JOYSTICK_H