#pragma once

#include <Shoegaze2/System/Interface/GUI/IPaint.h>
#include <Shoegaze2/System/Interface/GUI/IBrush.h>
#include <Shoegaze2/System/Interface/GUI/IPath.h>
#include <Shoegaze2/System/Interface/GUI/IImage.h>

#include <Shoegaze2/GUI/Primitives/Position.h>
#include <Shoegaze2/GUI/Primitives/Size.h>
#include <Shoegaze2/GUI/Drawing/Matrix.h>

#include <memory>
#include <utility>

namespace Shoegaze2
{
    class ICanvas
    {
    protected:
        std::shared_ptr<ICanvas> parent;
        std::shared_ptr<IImage> image;
        IRenderingContext *context = nullptr;
        Position position;
        Size size;
        Matrix matrix;
    public:
        ICanvas(IRenderingContext* ctx, Position pos, Size size, std::shared_ptr<ICanvas> parent = nullptr) : context(ctx), position(pos), size(size), parent(std::move(parent))
        {

        }

        void SetParent(std::shared_ptr<ICanvas> p) {
            parent = std::move(p);
        }

        Position GetPosition() { return position; }
        void SetPosition(Position p) { position = p; }
        Size GetSize() { return size; }
        virtual void Resize(Size newSize) {
            size = newSize;
        }

        virtual std::shared_ptr<IPath> CreatePath() = 0;
        virtual std::shared_ptr<IBrush> CreateBrush() = 0;
        virtual std::shared_ptr<IPaint> CreatePaint() = 0;

        virtual void StartDraw() = 0;
        virtual void EndDraw() = 0;

        virtual Position TranslatePosition() {
            if (image != nullptr) {
                return {0, 0};
            } else {
                if (parent == nullptr)
                    return position;
                else
                    return position + parent->position;
            }
        }

        virtual void MakeCurrent()
        {
            if (image != nullptr)
            {
                context->SetDrawingSurface(image);
            }
            else
            {
                if (parent != nullptr)
                    parent->MakeCurrent();
                else
                    context->SetDrawingSurface(nullptr);
            }
            auto tp = TranslatePosition();
            auto tm = matrix;
            tm = tm.Translate(tp.x, tp.y);
            context->SetMatrix(tm);
        }

        //void DrawRect();
    };
}