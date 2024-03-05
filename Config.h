#ifndef CONFIG_H
#define CONFIG_H

//--------------------- SERVER ----------------------

#define SERVER_CAM_PORT 1025
#define SERVER_COM_PORT 1026
#define SERVER_SET_PORT 1027

#define MAX_BUFFER_SIZE 65000
#define MAX_CLIENTS_QUEUE 5

#define TURRET_1_IP "192.168.2.2"
#define TURRET_PORT 1028

//---------------------------------------------------

//--------------------- ADCPI -----------------------

#define I2C_ADDRESS_1 0x68
#define I2C_ADDRESS_2 0x69
#define ADCPI_BITRATE 12
#define ADCPI_PGA 1 //Programmable Gain Amplifier => resolution

//---------------------------------------------------

//-------------------- JOYSTICK ---------------------

#define JOYSTICK_VRX_PIN 1
#define JOYSTICK_VRY_PIN 2

#define LOWER_THRESHOLD 2
#define HIGHER_THRESHOLD 3

//---------------------------------------------------


#endif //CONFIG_H