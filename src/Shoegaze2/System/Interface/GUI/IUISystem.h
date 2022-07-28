//
// Created by user on 27.07.2022.
//

#ifndef SHOEGAZE2_IUISYSTEM_H
#define SHOEGAZE2_IUISYSTEM_H

#include "IDisplayDevice.h"
#include <Shoegaze2/System/Interface/Input/IMouse.h>

namespace Shoegaze2 {
    class IUISystem {
    public:
        Event<Position> OnClick;

        virtual void Update() = 0;
        virtual void Render() = 0;

        virtual ~IUISystem() = default;
    };
}

#endif //SHOEGAZE2_IUISYSTEM_H
