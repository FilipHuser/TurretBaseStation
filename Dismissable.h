#ifndef DISMISSABLE_H
#define DISMISSABLE_H

class Dismissable {
public:
    explicit Dismissable() : loop(1) {}
    virtual void dismiss() { this->loop = 0; }
    bool loop;
};

#endif //DISMISSABLE_H