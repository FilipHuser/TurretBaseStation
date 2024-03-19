#include "JoystickObserver.h"

std::string joystickCommandFormatter(struct js_event js)
{
    std::string cmd_base = "M:";

    switch(js.type & ~JS_EVENT_INIT)
    {
        case JS_EVENT_AXIS:

            if(js.number == 0) //X axis
            {
                cmd_base += "ST:";
            } else {
                cmd_base += "SE:";
            }

        break;

        case JS_EVENT_BUTTON:

            if(js.number == 0) { return cmd_base += "SH"; }
            break;
    }

    if (js.value > 0)  //
    {
        cmd_base += "CW:";
    } else {
        cmd_base += "CCW:";
    }

    double value = std::abs(js.value);
    std::string result;

    if (value <= JOYSTICK_LOW_THRESHOLD) {
        result = "L"; // L => LOW
    } else if (value <= JOYSTICK_MEDIUM_THRESHOLD) {
        result = "M"; // M => MEDIUM
    } else if (value <= JOYSTICK_MAX_THRESHOLD) {
        result = "H"; // H => HIGH
    }

return cmd_base + result;
}

void JoystickObserver::update(Subject* subject)
{
    if (Joystick* j = dynamic_cast<Joystick*>(subject))
    {
        std::string cmd = joystickCommandFormatter(j->get_joystick());




        std::cout << cmd << std::endl;



        //if (!cmd.empty()) { server->sendData(cmd.c_str() , 0); }
    }
}