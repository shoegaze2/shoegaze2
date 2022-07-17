//
// Created by iashi on 02.03.2022.
//

#include "IAudioDevice.h"
#include "IAudioDescriptor.h"

using namespace Shoegaze2;

IAudioDevice::~IAudioDevice() {

    for (auto &descriptor: descriptors) {
        descriptor->status = IAudioDescriptor::INVALID;
    }
}