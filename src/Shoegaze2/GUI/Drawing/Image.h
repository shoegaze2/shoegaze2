//
// Created by iashi on 29.07.2022.
//

#ifndef SHOEGAZE2_IMAGE_H
#define SHOEGAZE2_IMAGE_H

#include <Shoegaze2/System/Utils/SharedPtrWrapper.h>
#include <Shoegaze2/System/Interface/GUI/IImage.h>

namespace Shoegaze2 {
    class Image : public SharedPtrWrapper<IImage> {
    public:
        Image(int width, int height) : SharedPtrWrapper<IImage>(IRenderingContext::Get()->CreateImage(width, height)) {

        }
    };
};



#endif //SHOEGAZE2_IMAGE_H
