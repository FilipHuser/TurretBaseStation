#include "BaseStationBuilder.h"

BaseStationBuilder::BaseStationBuilder()
{
    this->reset();
}

void BaseStationBuilder::reset()
{
    this->baseStation = std::make_unique<BaseStation>();
}

void BaseStationBuilder::produceServer() // 2
{
}

void BaseStationBuilder::produceDisplay() // 4
{
    
}

void BaseStationBuilder::produceJoystick() // 3
{
    
}

void BaseStationBuilder::produceThreadsManager() // 1
{
    this->baseStation->setThreadsManager(std::make_unique<ThreadsManager>());
}

void BaseStationBuilder::attachObservers()
{
    
}