//
// Created by iashi on 14.04.2022.
//

#ifndef SHOEGAZE2_VIEW_H
#define SHOEGAZE2_VIEW_H

#include "Primitives/Position.h"
#include "Primitives/Size.h"

#include "Drawing/Canvas.h"
#include "Drawing/Paint.h"
#include "Drawing/Path.h"
#include "Drawing/Brush.h"

#include "Container.h"

namespace Shoegaze2 {
    class View : public Container {
    private:
    public:
        View() = default;

        void OnResize(Size newSize) override = 0;
        void OnDraw(Canvas canvas) override = 0;

    };
}
#endif //SHOEGAZE2_VIEW_H
