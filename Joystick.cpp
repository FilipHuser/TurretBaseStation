#include "Joystick.h"

Joystic::Joystic() : adc(I2C_ADDRESS_1, I2C_ADDRESS_2, ADCPI_BITRATE) , x(-1) , y(-1) , loop(1)
{
	adc.set_pga(ADCPI_PGA);
	adc.set_conversion_mode(0);
}

void Joystic::get_input()
{
    this->x = this->adc.read_voltage(JOYSTICK_VRX_PIN);
    this->y = this->adc.read_voltage(JOYSTICK_VRY_PIN);
}