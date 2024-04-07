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

//-------------------- DISPLAY ----------------------

#define DISPLAY_WINDOW_W 640
#define DISPLAY_WINDOW_H  480
#define CHANNELS_COUNT 1
#define DISPLAY_WINDOW_NAME "Turret vision"

//---------------------------------------------------

//-------------------- JOYSTICK ---------------------

#define JOYSTICK_DEADZONE 5000
#define JOYSTICK_LOW_THRESHOLD 10000
#define JOYSTICK_MEDIUM_THRESHOLD 25383
#define JOYSTICK_MAX_THRESHOLD 32768

//---------------------------------------------------


#endif //CONFIG_H
