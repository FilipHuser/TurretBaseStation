#ifndef BUILDER_H
#define BUILDER_H

class Builder {
public:
    virtual void produceServer() = 0;
    virtual void produceDisplay() = 0;
    virtual void produceJoystick() = 0;
    virtual void produceThreadsManager() = 0;
    virtual void attachObservers() = 0;
};

#endif //BUILDER_H