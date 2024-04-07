#include "Joystick.h"

Joystick::Joystick() : fd(-1)
{
    this->fd = open("/dev/input/js0", O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
}

void* Joystick::monitorJoystickStatic(void* context)
{
    return ((Joystick*)(context))->monitorJoystick();
}


void* Joystick::monitorJoystick()
{
    while (shouldContinue()) 
    {
        ssize_t bytesRead = read(this->fd, &this->joystick, sizeof(this->joystick));

        if (bytesRead == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            } else {
                perror("read");
                exit(1);
            }
        }

        int event_type = this->joystick.type  & ~JS_EVENT_INIT;

        if(event_type== JS_EVENT_AXIS || event_type == JS_EVENT_BUTTON) 
        {
            notify();
        }
    }
    pthread_exit(nullptr);
}