#include "JoystickObserver.h"

std::pair<int , std::string> joystickCommandFormatter(struct js_event js)
{
    std::string cmd_base = "";

    switch(js.type & ~JS_EVENT_INIT)
    {
        case JS_EVENT_AXIS:
            cmd_base += "M:";
            if(js.number == 0) //X axis
            {
                cmd_base += "ST:";
            } else {
                cmd_base += "SE:";
            }
        break;

        case JS_EVENT_BUTTON:
            if(js.number == 0 && js.value == 1) { return std::make_pair(1 , cmd_base += "T:F");}

            if(js.number == 1 && js.value == 1) { return std::make_pair(2 , cmd_base + "SET:T:"); }
        break;
    }

    if (js.value > 0)
    {
        cmd_base += "CW:";
    } else {
        cmd_base += "CCW:";
    }

    double value = std::abs(js.value);
    std::string result;

    if (value > JOYSTICK_DEADZONE)
    {
        if (value <= JOYSTICK_LOW_THRESHOLD) {
            result = "L"; // L => LOW
        } else if (value <= JOYSTICK_MEDIUM_THRESHOLD) {
            result = "M"; // M => MEDIUM
        } else if (value <= JOYSTICK_MAX_THRESHOLD) {
            result = "H"; // H => HIGH
        }
        return std::make_pair(1 , cmd_base + result);
    }

    return std::make_pair(-1 , "");
}

void JoystickObserver::update(Subject* subject)
{
    if (Joystick* j = dynamic_cast<Joystick*>(subject))
    {
        std::pair<int , std::string> cmd = joystickCommandFormatter(j->get_joystick());
        
        if(!cmd.second.empty()) { server->sendData(cmd.second.c_str() , 0 , cmd.first); }
    }
}
