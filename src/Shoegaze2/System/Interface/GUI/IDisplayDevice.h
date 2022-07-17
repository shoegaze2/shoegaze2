#pragma once

#include <Shoegaze2/System/Interface/Device.h>
#include <Shoegaze2/System/Interface/GUI/IRenderingContext.h>

namespace Shoegaze2 
{
    class IDisplayDevice : public Device
    {
    protected:
        IRenderingContext *renderingContext;

        virtual IRenderingContext *CreateRenderingContext() { return nullptr; }
    public:
        virtual bool Initialize() { return false; }

        virtual IRenderingContext *GetRenderingContext()
        {
            return renderingContext;
        }
    };
}