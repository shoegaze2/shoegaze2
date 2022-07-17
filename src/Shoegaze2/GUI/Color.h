#pragma once

#include <stdint.h>

namespace Shoegaze2
{
    class Color
    {
    private:
        static float clamp(float value)
        {
            if (value < 0.0f)
                value = 0.0f;
            else if (value > 1.0f)
                value = 1.0f;
            return value;
        }
    public:
        float r = 0, g = 0, b = 0, a = 0;

        static Color FromRGBAf(float r, float g, float b, float a)
        {
            Color c{};
            c.r = clamp(r);
            c.g = clamp(g);
            c.b = clamp(b);
            c.a = clamp(a);
            return c;
        }

        static Color FromRGBf(float r, float g, float b)
        {
            return Color::FromRGBAf(r, g, b, 1.0f);
        }

        static Color FromRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        {
            return Color::FromRGBAf(r/255.0f, g/255.0f, b/255.0f, a/255.0f);
        }

        static Color FromRGB(uint8_t r, uint8_t g, uint8_t b)
        {
            return Color::FromRGBA(r, g, b, 255);
        }
    };
}