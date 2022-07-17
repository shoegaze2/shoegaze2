#pragma once

#include <Shoegaze2/System/Interface/GUI/IBrush.h>
#include <memory>
#include <Shoegaze2/GUI/Drawing/Brush.h>


namespace Shoegaze2
{
    class IPath
    {
        public:
            virtual void MoveTo(float x, float y) = 0;
            virtual void LineTo(float x, float y) = 0;
            virtual void QuadTo(float cx, float cy, float x, float y) = 0;
            virtual void CubicTo(float cx1, float cy1, float cx2, float cy2, float x, float y) = 0;

            virtual void AppendLine(float x0, float y0, float x1, float y1) = 0;
            virtual void AppendRect(float x, float y, float w, float h) = 0;
            virtual void AppendRoundRect(float x, float y, float w, float h, float r) = 0;
            virtual void AppendArc(float x, float y, float w, float h, float startAngle, float angleExt, int arcType) = 0;

            virtual void Close() = 0;

            virtual void Draw(const Brush &brush, float tx, float ty, float sx, float sy) = 0;
            virtual std::shared_ptr<IPath> Scale(float x, float y) { return Transform(0, 0, x, y); };
            virtual std::shared_ptr<IPath> Scale(float scale) { return Scale(scale, scale); }
            virtual std::shared_ptr<IPath> Translate(float x, float y) { return Transform(x, y, 1, 1); };
            virtual std::shared_ptr<IPath> Transform(float tx, float ty, float sx, float sy) = 0;

            virtual std::shared_ptr<IPath> Copy() = 0;
            virtual void Clear() = 0;

            virtual ~IPath() {};
    };
}