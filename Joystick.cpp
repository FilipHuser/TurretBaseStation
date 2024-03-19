#include "Joystick.h"

Joystick::Joystick() : fd(-1) , loop(1)
{
    // Open the joystick device
    this->fd = open("/dev/input/js0", O_RDONLY);
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
    while (1) 
    {
        if (read(this->fd, &this->joystick, sizeof(this->joystick)) != sizeof(this->joystick)) {
            perror("read");
            exit(1);
        }

        int event_type = this->joystick.type  & ~JS_EVENT_INIT;

        if(event_type== JS_EVENT_AXIS || event_type == JS_EVENT_BUTTON) 
        {
            notify();
        }
    }
        usleep(5000);

    pthread_exit(nullptr);
}