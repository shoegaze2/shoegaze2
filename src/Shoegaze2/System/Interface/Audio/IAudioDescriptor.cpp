//
// Created by iashi on 02.03.2022.
//

#include "IAudioDescriptor.h"
#include "IAudioSystem.h"

using namespace Shoegaze2;

IAudioDevice *IAudioDescriptor::GetDevice() { return IAudioSystem::Get()->GetDevice(*this); }