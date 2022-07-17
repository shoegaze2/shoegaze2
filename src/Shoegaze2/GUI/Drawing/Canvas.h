//
// Created by iashi on 14.04.2022.
//

#ifndef SHOEGAZE2_CANVAS_H
#define SHOEGAZE2_CANVAS_H

#include <Shoegaze2/System/Interface/GUI/IRenderingContext.h>
#include <Shoegaze2/System/Interface/GUI/ICanvas.h>
#include <Shoegaze2/System/Utils/SharedPtrWrapper.h>
#include <Shoegaze2/GUI/Font/Font.h>
#include "Path.h"
#include "Brush.h"

namespace Shoegaze2
{
    class Canvas : public SharedPtrWrapper<ICanvas>
    {
    private:
        void MakeCurrent() { Get()->MakeCurrent(); }
    public:
        Canvas(Position pos, Size size) : SharedPtrWrapper<ICanvas>(IRenderingContext::Get()->CreateCanvas(pos, size))
        {

        }

        Canvas(Position pos, Size size, const Canvas& parent) : SharedPtrWrapper<ICanvas>(IRenderingContext::Get()->CreateCanvas(pos, size, parent.ptr))
        {

        }


        Canvas(std::shared_ptr<ICanvas> sharedPtr) : SharedPtrWrapper<ICanvas>(std::move(sharedPtr)) {

        }

        Size GetSize() { return Get()->GetSize(); }
        Position GetPosition() { return Get()->GetPosition(); }

        void DrawPath(const Path& path, const Brush& brush) {
            MakeCurrent();
            path->Draw(brush, 0, 0, 1, 1);
        }

        void DrawText(String &text, Position pos, float size, const Brush& brush, Font* font) {
            MakeCurrent();
            font->DrawString(text, pos.x, pos.y, size, brush);
        }
    };
}

#endif //SHOEGAZE2_CANVAS_H
