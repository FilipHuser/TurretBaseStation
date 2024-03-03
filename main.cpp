#include <iostream>
#include <vector>
#include <fstream>

#include "Server.h"
#include "ThreadsManager.h"

#include "DisplayObserver.h"
#include "JoystickObserver.h"


#include "Display.h"

int main(int argc , char* argv[])
{
    Server server;

    Display d(640 , 480 , "Turret vision");

    Observer* dO = new DisplayObserver(&d);

    //server.attach(dO);

    ThreadsManager tm;


    std::pair<int , Server*> CAMargs;

    CAMargs.first = 0;
    CAMargs.second = &server;

    std::pair<int , Server*> COMargs;

    COMargs.first = 1;
    COMargs.second = &server;



    tm.createThread(&server.receiveDataStatic , &CAMargs);
    tm.createThread(&server.receiveDataStatic , &COMargs);

    while(1)
    {
        server.sendData("Ahooj z basky" , 0);
    }

}

/*

#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <unistd.h>

#include "Joystick.h"

int main(int argc , char* argv[])
{
    Joystic j;

    ABElectronics_CPP_Libraries::ADCPi adc(0x68, 0x69, 12);
	adc.set_pga(1);
	adc.set_conversion_mode(0);

    while (1){

		double x = adc.read_voltage(1);
		double y =adc.read_voltage(2);

		if (x > 3) { std::cout << "left" << std::endl; }

		if (x < 2) { std::cout << "right" << std::endl; }

		if (y > 3) { std::cout << "down" << std::endl; }

		if (y < 2) { std::cout << "up" << std::endl; }

		usleep(200000); // sleep 0.2 seconds
	}

}


*/