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
#include "DisplayObserver.h"
#include "JoystickObserver.h"

class BaseStationBuilder : public Builder{
public:
    BaseStationBuilder();

    void produceServer() override;
    void produceDisplay() override;
    void produceJoystick() override;
    void produceThreadsManager() override;
    void attachObservers() override;

    void reset();

private:
    std::unique_ptr<BaseStation> baseStation;
};

#endif //BASE_STATION_BUILDER_H