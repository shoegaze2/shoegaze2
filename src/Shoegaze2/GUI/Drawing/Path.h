//
// Created by iashi on 29.03.2022.
//

#ifndef SHOEGAZE2_PATH_H
#define SHOEGAZE2_PATH_H

#include <Shoegaze2/System/Interface/GUI/IRenderingContext.h>
#include <Shoegaze2/System/Interface/GUI/IPath.h>
#include <Shoegaze2/System/Utils/SharedPtrWrapper.h>

namespace Shoegaze2
{
    class Path : public SharedPtrWrapper<IPath>
    {
    public:
        Path() : SharedPtrWrapper<IPath>(IRenderingContext::Get()->CreatePath())
        {

        }

        Path(std::shared_ptr<IPath> sharedPtr) : SharedPtrWrapper<IPath>(std::move(sharedPtr)) {

        }
    };
}

#endif //SHOEGAZE2_PATH_H
