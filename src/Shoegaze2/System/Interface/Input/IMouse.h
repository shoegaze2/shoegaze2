//
// Created by user on 27.07.2022.
//

#ifndef SHOEGAZE2_IMOUSE_H
#define SHOEGAZE2_IMOUSE_H

#include <Shoegaze2/System/Events/Event.h>

namespace Shoegaze2 {
    class IMouse {
    public:
        enum MouseEventType {
            Press,
            Release,
            Move,
            Scroll
        };

        enum MouseButton {
            Left,
            Middle,
            Right,
            None
        };

        struct MouseEventArgs {
            float x;
            float y;
            float scrollX;
            float scrollY;
            MouseEventType eventType;
            MouseButton button;
        };

        Event<MouseEventArgs> OnEvent;
    };
}

#endif //SHOEGAZE2_IMOUSE_H
