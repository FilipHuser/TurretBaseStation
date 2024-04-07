#ifndef DISMISSABLE_H
#define DISMISSABLE_H

#include <mutex>

class Dismissable {
public:
    explicit Dismissable() : loop(true) {}
    virtual void dismiss() {
        std::lock_guard<std::mutex> lock(mutex);
        loop = false;
    }
    bool shouldContinue() const {
        std::lock_guard<std::mutex> lock(mutex);
        return loop;
    }

    bool loop;
    mutable std::mutex mutex;
};

#endif //DISMISSABLE_H