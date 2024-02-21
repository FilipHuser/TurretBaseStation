#include "Subject.h"
#include "Observer.h"

void Subject::attach(Observer* o)
{ 
    this->observers.push_back(o); 
}

void Subject::notify() {
    for (Observer* observer : observers) {
        observer->update(this);
    }
};
    