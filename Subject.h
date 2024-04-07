#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>

class Observer;

class Subject {
public:
    virtual void attach(std::shared_ptr<Observer> o);
    virtual void notify();
    
private:
    std::vector<std::shared_ptr<Observer>> observers;
};

#endif //SUBJECT_H