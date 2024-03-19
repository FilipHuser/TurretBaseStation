#ifndef CONFIG_H
#define CONFIG_H

//--------------------- SERVER ----------------------

#define SERVER_CAM_PORT 1025
#define SERVER_COM_PORT 1026
#define SERVER_SET_PORT 1027

#define MAX_BUFFER_SIZE 65000
#define MAX_CLIENTS_QUEUE 5

#define TURRET_1_IP "10.42.0.175"
#define TURRET_PORT 1028

//---------------------------------------------------

//-------------------- DISPLAY ----------------------

#define DISPLAY_WINDOW_W 640
#define DISPLAY_WINDOW_H  480
#define DISPLAY_WINDOW_NAME "Turret vision"

//---------------------------------------------------

//--------------------- ADCPI -----------------------

#define I2C_ADDRESS_1 0x68
#define I2C_ADDRESS_2 0x69
#define ADCPI_BITRATE 12
#define ADCPI_PGA 1 //Programmable Gain Amplifier => resolution

//---------------------------------------------------

//-------------------- JOYSTICK ---------------------

#define JOYSTICK_LOW_THRESHOLD 5000
#define JOYSTICK_MEDIUM_THRESHOLD 15383
#define JOYSTICK_MAX_THRESHOLD 32767

//---------------------------------------------------


#endif //CONFIG_H
