#include "BaseStationBuilder.h"

BaseStationBuilder::BaseStationBuilder()
{
    this->reset();
}

void BaseStationBuilder::reset()
{
    this->baseStation = std::make_unique<BaseStation>();
}

void BaseStationBuilder::produceServer()
{
    this->baseStation->setServer(std::make_unique<Server>());
}

void BaseStationBuilder::produceDisplay()
{
    this->baseStation->setDisplay(std::make_unique<Display>());
}

void BaseStationBuilder::produceJoystick()
{
    this->baseStation->setJoystick(std::make_unique<Joystick>());
}

void BaseStationBuilder::produceThreadsManager()
{
    this->baseStation->setThreadsManager(std::make_unique<ThreadsManager>());
}

void BaseStationBuilder::attachObservers()
{
    std::shared_ptr<Observer> sO = std::make_shared<ServerObserver>(this->baseStation->getDisplay()); //Display observer
    std::shared_ptr<Observer> jO = std::make_shared<JoystickObserver>(this->baseStation->getServer()); //Joystick observer

    this->baseStation->getServer()->attach(sO);
    this->baseStation->getJoystick()->attach(jO);
}