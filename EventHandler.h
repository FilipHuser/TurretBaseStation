#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <iostream>
#include <vector>

class EventHandler {
public:
    EventHandler() = default;

    void handle(std::vector<char> buffer);

private:

};

#endif //EVENT_HANDLER_H