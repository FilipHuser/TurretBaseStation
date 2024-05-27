#ifndef CONFIG_H
#define CONFIG_H

//--------------------- SERVER ----------------------

#define SERVER_CAM_PORT 1025
#define SERVER_COM_PORT 1026
#define SERVER_SET_PORT 1027

#define CLIENT_CAM_PORT 1025
#define CLIENT_COM_PORT 1026
#define CLIENT_SET_PORT 1027

#define MAX_BUFFER_SIZE 65000
#define MAX_CLIENTS_QUEUE 5

#define TURRET_1_IP "10.0.0.2"

//---------------------------------------------------

//-------------------- DISPLAY ----------------------

#define DISPLAY_WINDOW_W 800
#define DISPLAY_WINDOW_H  480
#define CHANNELS_COUNT 3
#define DISPLAY_WINDOW_NAME "Turret vision"

//---------------------------------------------------

//-------------------- JOYSTICK ---------------------

#define JOYSTICK_DEADZONE 5000
#define JOYSTICK_LOW_THRESHOLD 10000
#define JOYSTICK_MEDIUM_THRESHOLD 25383
#define JOYSTICK_MAX_THRESHOLD 32768

//---------------------------------------------------


#endif //CONFIG_H
