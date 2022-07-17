//
// Created by iashi on 12.02.2022.
//

#ifndef SHOEGAZE2_IIMAGE_H
#define SHOEGAZE2_IIMAGE_H

#include <Shoegaze2/System/Interface/GUI/IRenderingContext.h>

namespace Shoegaze2
{
    class IImage
    {
    protected:
        int width;
        int height;
    public:
        IImage(int width, int height) : width(width), height(height)
        {

        }

        int GetWidth() const { return width; }
        int GetHeight() const { return height; }

        virtual void Clear(const Color &clearColor) = 0;
        virtual void ReadData() = 0;
        virtual void WriteData() = 0;

        virtual ~IImage() = default;
    protected:
        virtual void SetCurrent(IRenderingContext *ctx) = 0;
    };
}

#endif //SHOEGAZE2_IIMAGE_H
