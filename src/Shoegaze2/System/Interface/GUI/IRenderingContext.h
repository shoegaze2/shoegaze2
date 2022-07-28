#pragma once

#include <memory>
#include <Shoegaze2/GUI/Primitives/Position.h>
#include <Shoegaze2/GUI/Primitives/Size.h>
#include <Shoegaze2/GUI/Drawing/Matrix.h>

namespace Shoegaze2
{
    class IBrush;
    class IPaint;
    class IPath;
    class IImage;

    class IRenderingContext
    {
    private:
        // TODO: replace singleton with UISystem ctx
        inline static IRenderingContext *handle = nullptr;
    public:
        IRenderingContext() { handle = this; }
        static IRenderingContext *Get() { return handle; }

        virtual bool Initialize() = 0;
        virtual std::shared_ptr<IImage> CreateImage(int width, int height) = 0;
        virtual std::shared_ptr<IBrush> CreateBrush() = 0;
        virtual std::shared_ptr<IPaint> CreatePaint() = 0;
        virtual std::shared_ptr<IPath> CreatePath() = 0;

        virtual Matrix GetMatrix() = 0;
        virtual void SetMatrix(Matrix& matrix) = 0;

        virtual void Clear() = 0;
        virtual void SwapBuffers() = 0;

        virtual void StartFrame() = 0;
        virtual void EndFrame() = 0;

        virtual int GetWidth() = 0;
        virtual int GetHeight() = 0;

        virtual void Reset() = 0;

        virtual void SetDrawingSurface(std::shared_ptr<IImage> image) = 0;
    };
}