#pragma once

#include <memory>
#include <Shoegaze2/GUI/Color.h>
#include <Shoegaze2/System/Interface/GUI/IPaint.h>
#include <Shoegaze2/GUI/Drawing/Paint.h>

namespace Shoegaze2
{
    enum PaintMode
    {
        Fill,
        Stroke,
        FillStroke
    };

    class IBrush
    {
    protected:
        Paint paint;
        Paint strokePaint;
        PaintMode paintMode = PaintMode::FillStroke;
        float strokeWidth = 1.0f;

    public:
        void SetPaint(const Paint &paint)
        {
            this->paint = paint;
        }

        Paint GetPaint()
        {
            return paint;
        }

        void SetPaintMode(PaintMode paintMode)
        {
            this->paintMode = paintMode;
        }

        PaintMode GetPaintMode()
        {
            return paintMode;
        }

        void SetStrokeWidth(float strokeWidth)
        {
            this->strokeWidth = strokeWidth;
        }

        float GetStrokeWidth()
        {
            return strokeWidth;
        }

        virtual void SetCurrent() {}
    };
}