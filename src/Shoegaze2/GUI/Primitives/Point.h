#pragma once

namespace Shoegaze2
{
    class Point
    {
    public:
        float x, y;

        Point(float x, float y) : x(x), y(y)
        {

        }

        Point operator+(const Point &rhs) const {
            return {x + rhs.x, y + rhs.y};
        }
    };
}