//
// Created by iashi on 14.04.2022.
//

#ifndef SHOEGAZE2_PAINT_H
#define SHOEGAZE2_PAINT_H

#include <Shoegaze2/System/Interface/GUI/IRenderingContext.h>
#include <Shoegaze2/System/Interface/GUI/IPaint.h>
#include <Shoegaze2/System/Utils/SharedPtrWrapper.h>

namespace Shoegaze2
{
    class Paint : public SharedPtrWrapper<IPaint>
    {
    public:
        Paint() : SharedPtrWrapper<IPaint>(IRenderingContext::Get()->CreatePaint())
        {

        }

        Paint(std::shared_ptr<IPaint> sharedPtr) : SharedPtrWrapper<IPaint>(std::move(sharedPtr)) {

        }

        Paint(const Color &color) : Paint()
        {
            SharedPtrWrapper<IPaint>::operator->()->SetColor(color);
        }
    };
}
#endif //SHOEGAZE2_PAINT_H
