//
// Created by iashi on 07.06.2022.
//

#ifndef SHOEGAZE2_CONTAINER_H
#define SHOEGAZE2_CONTAINER_H

#include <Shoegaze2/System/Events/Event.h>
#include "Primitives/Point.h"
#include "Primitives/Position.h"
#include "Drawing/Canvas.h"

namespace Shoegaze2 {
    class Container {
    protected:
        Position position {0, 0};
        Size size {0, 0};
    public:
        Event<Position> onClickEvent;

        virtual void OnDraw(const Canvas &canvas) {};
        virtual void OnResize(Size newSize) { size = newSize; };

        Size GetSize() { return size; }
        void SetSize(Size s) { size = s;}
        Position GetPosition() { return position; }
        void SetPosition(Position p) { position = p; }

        virtual void OnClickEvent(float x, float y) {
            onClickEvent.Invoke({position.x, position.y});
        }

        virtual void Update() {};
    };
}

#endif //SHOEGAZE2_CONTAINER_H
