//
// Created by iashi on 02.03.2022.
//

#ifndef SHOEGAZE2_AUDIODESCRIPTOR_H
#define SHOEGAZE2_AUDIODESCRIPTOR_H

#include <Shoegaze2/System/Interface/Audio/IAudioDevice.h>
#include <Shoegaze2/System/Interface/Audio/IAudioSystem.h>
#include <Shoegaze2/System/Interface/Audio/AudioBuffer.h>

namespace Shoegaze2
{
    class IAudioDescriptor
    {
    public:
        enum DescriptorStatus
        {
            OK,
            INVALID
        };
    protected:
        int deviceId;
        int channel;
        DescriptorStatus status;

        IAudioDevice* GetDevice();
    public:
        DescriptorStatus GetStatus() { return status; }

        friend class IAudioSystem;
        friend class IAudioDevice;
    };

    class AudioOutput : public IAudioDescriptor
    {
    public:
        void Write(const AudioBuffer& buffer)
        {
            /*auto dev = GetDevice();
            if (dev != nullptr)
                dev->Write(channel, buffer);
            else
                status = INVALID;*/
        }
    };

    class AudioInput : public IAudioDescriptor
    {
    public:
        AudioBuffer* Read()
        {
            /*auto dev = GetDevice();
            if (dev != nullptr)
                return dev->Read(channel);
            else
                status = INVALID;*/
            return nullptr;
        }
    };
}


#endif //SHOEGAZE2_AUDIODESCRIPTOR_H
