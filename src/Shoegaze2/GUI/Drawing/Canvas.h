//
// Created by iashi on 14.04.2022.
//

#ifndef SHOEGAZE2_CANVAS_H
#define SHOEGAZE2_CANVAS_H

#include <Shoegaze2/System/Interface/GUI/IRenderingContext.h>
#include <Shoegaze2/GUI/Font/Font.h>
#include "Path.h"
#include "Brush.h"

namespace Shoegaze2
{
    class Canvas
    {
    private:
        const Canvas* parent = nullptr;
        IRenderingContext* context = nullptr;
        Position position;
        Size size;
        Matrix matrix;

        Position GetTranslatePosition() const {
            if (parent != nullptr) {
                return position + parent->GetTranslatePosition();
            } else {
                return position;
            }
        }

        void MakeCurrent(bool setThis = true) const {
            if (parent != nullptr)
                parent->MakeCurrent(false);
            else
                context->SetDrawingSurface(nullptr);

            if (setThis) {
                context->Reset();
                auto tp = GetTranslatePosition();
                auto tm = matrix;
                tm = tm.Translate(tp.x, tp.y);
                context->SetMatrix(tm);
            }
        }
    public:
        Canvas(Position pos, Size size) : position(pos), size(size)
        {
            context = IRenderingContext::Get();
        }

        Canvas(Position pos, Size size, const Canvas& parent) : position(pos), size(size), parent(&parent)
        {

        }

        void SetParent(const Canvas &canvas) {
            parent = &canvas;
        }

        Size GetSize() { return size; }
        void Resize(Size newSize) { size = newSize; }

        Position GetPosition() { return position; }
        void SetPosition(Position newPosition) { position = newPosition; }

        void DrawPath(const Path& path, const Brush& brush) const {
            MakeCurrent();
            path->Draw(brush, 0, 0, 1, 1);
        }

        void DrawText(String &text, Position pos, float size, const Brush& brush, Font* font) const {
            MakeCurrent();
            font->DrawString(text, pos.x, pos.y, size, brush);
        }
    };
}

#endif //SHOEGAZE2_CANVAS_H
