#ifndef BASE_STATION_H
#define BASE_STATION_H

#include <memory>

#include "Server.h"
#include "ThreadsManager.h"
#include "Joystick.h"
#include "Display.h"
#include "Dismissable.h"

class BaseStation : public Dismissable {
public:
//CONSTRUCTOR
    BaseStation() = default;

//METHODS
    void run();
    //void handleSettings(std::string cmd)

//SETTERS
    void setServer(std::unique_ptr<Server> server) { this->server = std::move(server); }
    void setDisplay(std::unique_ptr<Display> display) { this->display = std::move(display); }
    void setJoystick(std::unique_ptr<Joystick> joystick) { this->joystick = std::move(joystick); }
    void setThreadsManager(std::unique_ptr<ThreadsManager> manager) { this->tManager = std::move(manager); }

//GETTERS
    Server* getServer() { return this->server.get(); }
    Display* getDisplay() { return this->display.get(); }
    Joystick* getJoystick() { return this->joystick.get(); }

//DESTRUCTOR
    ~BaseStation();

private:
    std::unique_ptr<Server> server;
    std::unique_ptr<Display> display;
    std::unique_ptr<Joystick> joystick;
    std::unique_ptr<ThreadsManager> tManager;
};

#endif //BASE_STATION_H