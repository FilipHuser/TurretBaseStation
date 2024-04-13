#include "BaseStation.h"

void BaseStation::run()
{
    std::pair<int , Server*> CAMargs;
    CAMargs.first = 0; //port
    CAMargs.second = this->server.get();

    std::pair<int , Server*> COMargs;
    COMargs.first = 1; //port
    COMargs.second = this->server.get();

    std::pair<int , Server*> SETargs;
    SETargs.first = 2; //port
    SETargs.second = this->server.get();

    this->tManager->createThread(this->server->receiveDataStatic , &CAMargs);
    this->tManager->createThread(this->server->receiveDataStatic , &COMargs);
    this->tManager->createThread(this->server->receiveDataStatic , &SETargs);

    this->tManager->createThread(this->joystick->monitorJoystickStatic , this->joystick.get());

    while(1) { if(std::cin.get() == 'q'){ break; }}
}

BaseStation::~BaseStation()
{
    this->server->dismiss();
    this->joystick->dismiss();
    this->tManager->joinAllThreads();
}
