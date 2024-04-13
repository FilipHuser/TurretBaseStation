#include "Subject.h"
#include "Observer.h"

void Subject::attach(std::shared_ptr<Observer> o)
{ 
    if (this->observers.size() == 0) 
    { 
        o->id = 0;
    } else {
        int observerCount = this->observers.size();
        o->id = this->observers[observerCount-1]->id + 1;
    }


    this->observers.push_back(o); 
}

void Subject::notify() {
    for (std::shared_ptr<Observer>& observer : observers) {
        observer->update(this);
    }
};

void Subject::notify(int observerId) {
    for (const auto& observer : observers) {
        if (observer->id == observerId) {
            observer->update(this);
            break;
        }
    }
}
    