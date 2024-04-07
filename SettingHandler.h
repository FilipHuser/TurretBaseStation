#ifndef SETTINGS_HANDLER_H
#define SETTINGS_HANDLER_H

#include <string>

#include "Display.h"

class SettingHandler {
public:
// CONSTRUCTOR
    SettingHandler() = default;

// METHODS
    void handleDisplay(std::string cmd);

// SETTERS
    void setDisplay(Display* display) { this->display = display; }
    

private:
    Display* display;
};

#endif //SETTINGS_HANDLER_H