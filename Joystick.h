#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <iostream>

#include "Subject.h"
#include "Include/ABE_ADCPi.h"
#include "Config.h"

class Joystic : public Subject {
public:
    Joystic();

    void get_input();

//private:
    ABElectronics_CPP_Libraries::ADCPi adc;
    double x;
    double y;
    bool loop;
};

#endif //JOYSTICK_H