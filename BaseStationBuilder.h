#ifndef BASE_STATION_BUILDER_H
#define BASE_STATION_BUILDER_H

#include <memory>

#include "Builder.h"
#include "BaseStation.h"
#include "Server.h"
#include "Display.h"
#include "Joystick.h"
#include "ThreadsManager.h"
#include "Config.h"
#include "ServerObserver.h"
#include "JoystickObserver.h"
#include "DisplayObserver.h"

class BaseStationBuilder : public Builder{
public:
//CONSTRUCTOR
    BaseStationBuilder();

//METHODS
    void produceServer() override;
    void produceDisplay() override;
    void produceJoystick() override;
    void produceThreadsManager() override;
    void attachObservers() override;
    void reset();

//GETTERS   
    std::unique_ptr<BaseStation> getProduct() { return std::move(this->baseStation); }

private:
    std::unique_ptr<BaseStation> baseStation;
};

#endif //BASE_STATION_BUILDER_H