#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "BaseStationBuilder.h"
#include "Director.h"

#include "Display.h"

int main(int argc , char* argv[])
{
	uid_t uid = getuid();
	char xdg_runtime_dir[128];
	snprintf(xdg_runtime_dir , sizeof(xdg_runtime_dir) ,"/run/user/%d" , uid); 

	setenv("XDG_RUNTIME_DIR" , xdg_runtime_dir , 1);

    Director d;
    std::unique_ptr<BaseStationBuilder> bsb = std::make_unique<BaseStationBuilder>();

    d.setBuilder(bsb.get());

    d.buildMinimalBaseStation();

    bsb->getProduct()->run();


    return 0;
}

/*

Server s;

    Display d(640 , 480 , "Turret vision");
    Joystick j;

    Observer* dO = new ServerObserver(&d);
    Observer* jO = new JoystickObserver(&s);

    //j.attach(jO);
    //s.attach(dO);

    ThreadsManager tm;


    std::pair<int , Server*> CAMargs;

    CAMargs.first = 0;
    CAMargs.second = &s;

    std::pair<int , Server*> COMargs;

    COMargs.first = 1;
    COMargs.second = &s;

    tm.createThread(&s.receiveDataStatic , &CAMargs);
    tm.createThread(&s.receiveDataStatic , &COMargs);
    tm.createThread(&j.monitorJoystickStatic , &j);


*/