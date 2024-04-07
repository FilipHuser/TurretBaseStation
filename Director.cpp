#include "Director.h"

void Director::buildMinimalBaseStation()
{
    this->builder->produceThreadsManager();
    this->builder->produceServer();
    this->builder->produceJoystick();
    this->builder->produceDisplay();
    this->builder->attachObservers();
}