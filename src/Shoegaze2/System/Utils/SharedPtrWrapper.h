//
// Created by iashi on 01.04.2022.
//

#ifndef SHOEGAZE2_SHAREDPTRWRAPPER_H
#define SHOEGAZE2_SHAREDPTRWRAPPER_H

#include <memory>

namespace Shoegaze2
{
    template<typename T>
    class SharedPtrWrapper
    {
    protected:
        T* Get() const { return ptr.get(); }
    public:
        std::shared_ptr<T> ptr;
        SharedPtrWrapper(std::shared_ptr<T> sharedPtr) : ptr(sharedPtr) {}

        T *operator->() const
        {
            return ptr.get();
        }
    };
}

#endif //SHOEGAZE2_SHAREDPTRWRAPPER_H
