#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <iostream>

#include "Subject.h"
#include "Include/ABE_ADCPi.h"
#include "Config.h"
#include "unistd.h"

class Joystick : public Subject {
public:
    Joystick();

    static void* getInputStatic(void* context);
    void* getInput();

    double getX() { return this->x; }
    double getY() { return this->y; }

    void dismiss() { this->loop = 0; }

private:
    ABElectronics_CPP_Libraries::ADCPi adc;
    double x;
    double y;
    bool loop;
};

#endif //JOYSTICK_H