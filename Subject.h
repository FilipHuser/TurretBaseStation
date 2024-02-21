#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;

class Subject {
public:
    virtual void attach(Observer* o);
    virtual void notify();
    
private:
    std::vector<Observer*> observers;
};

#endif //SUBJECT_H