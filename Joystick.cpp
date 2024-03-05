#include "Joystick.h"

Joystick::Joystick() : adc(I2C_ADDRESS_1, I2C_ADDRESS_2, ADCPI_BITRATE) , x(-1) , y(-1) , loop(1)
{
	adc.set_pga(ADCPI_PGA);
	adc.set_conversion_mode(0);
}

void* Joystick::getInputStatic(void* context)
{
    return ((Joystick*)(context))->getInput();
}

void* Joystick::getInput()
{
    while(this->loop)
    {
        this->x = this->adc.read_voltage(JOYSTICK_VRX_PIN);
        this->y = this->adc.read_voltage(JOYSTICK_VRY_PIN);

        if (x > HIGHER_THRESHOLD || x < LOWER_THRESHOLD || y > HIGHER_THRESHOLD || y < LOWER_THRESHOLD)
        {
            notify();
        }

    }

    pthread_exit(nullptr);
}