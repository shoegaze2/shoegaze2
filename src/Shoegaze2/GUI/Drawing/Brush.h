//
// Created by iashi on 14.04.2022.
//

#ifndef SHOEGAZE2_BRUSH_H
#define SHOEGAZE2_BRUSH_H


#include <Shoegaze2/System/Interface/GUI/IRenderingContext.h>
#include <Shoegaze2/System/Interface/GUI/IBrush.h>
#include <Shoegaze2/System/Utils/SharedPtrWrapper.h>

#include <utility>
#include "Paint.h"

namespace Shoegaze2
{
    class Brush : public SharedPtrWrapper<IBrush>
    {
    public:
        Brush() : SharedPtrWrapper<IBrush>(IRenderingContext::Get()->CreateBrush()) {

        }

        Brush(std::shared_ptr<IBrush> sharedPtr) : SharedPtrWrapper<IBrush>(std::move(sharedPtr)) {

        }

        Brush(const Paint& paint) : Brush()
        {
            SharedPtrWrapper<IBrush>::operator->()->SetPaint(paint);
        }
    };
}


#endif //SHOEGAZE2_BRUSH_H
