#pragma once

#include <Shoegaze2/GUI/Color.h>

// TODO: Linear and Radial gradients
namespace Shoegaze2
{
    class IPaint
    {
    protected:
        Color color;
    public:
        IPaint()
        {
        }
        IPaint(const Color &color)
        {
            SetColor(color);
        }

        virtual void SetColor(const Color &color) { this->color = color; }
        Color GetColor() { return color; }

        //virtual void SetCurrent() {}

        virtual ~IPaint() { }
    };
}