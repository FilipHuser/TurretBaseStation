#include "JoystickObserver.h"

std::string joystickCommandFormatter(double x , double y)
{
    std::string cmd_base = "M:";

    if (x > HIGHER_THRESHOLD) { return cmd_base += "SE:CCW"; }
    if (x < LOWER_THRESHOLD) { return cmd_base +="SE:CW"; }

//---------------------------------------------------------------------

    if (y > HIGHER_THRESHOLD) { return cmd_base +="ST:CCW";  }
    if (y < LOWER_THRESHOLD) { return cmd_base +="ST:CW"; }

    return "";
}

void JoystickObserver::update(Subject* subject)
{
    if (Joystick* j = dynamic_cast<Joystick*>(subject))
    {
        std::string cmd = joystickCommandFormatter(j->getX() , j->getY());

        if (!cmd.empty()) { server->sendData(cmd.c_str() , 0); }
    }
}