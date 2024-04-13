#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"

class Subject;

class Observer {
public:
    virtual void update(Subject* subject) = 0;
    int id;
};

#endif //OBSERVER_H