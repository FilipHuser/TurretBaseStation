#include "Subject.h"
#include "Observer.h"

void Subject::attach(std::shared_ptr<Observer> o)
{ 
    this->observers.push_back(o); 
}

void Subject::notify() {
    for (std::shared_ptr<Observer>& observer : observers) {
        observer->update(this);
    }
};
    