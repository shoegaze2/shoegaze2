//
// Created by iashi on 02.03.2022.
//

#include "IAudioSystem.h"
#include "IAudioDescriptor.h"
#include "IAudioDevice.h"

using namespace Shoegaze2;

IAudioSystem* IAudioSystem::handle = nullptr;

IAudioDevice *IAudioSystem::GetDevice(const IAudioDescriptor &descriptor) {
    if (devices.find(descriptor.deviceId) != devices.end())
        return devices[descriptor.deviceId];
    return nullptr;
}
