//
// Created by iashi on 11.03.2022.
//

#ifndef SHOEGAZE2_EVENT_H
#define SHOEGAZE2_EVENT_H

#include <functional>

template<typename ...Args>
class Event {
private:
    using EventHandler = std::function<void(Args...)>;
    EventHandler handler;
public:
    Event &operator=(EventHandler h) {
        handler = h;
        return *this;
    }

    void Invoke(Args... args) {
        if (handler != nullptr) {
            handler(args...);
        }
    }
};


#endif //SHOEGAZE2_EVENT_H
