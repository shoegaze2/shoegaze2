//
// Created by iashi on 02.03.2022.
//

#ifndef SHOEGAZE2_IAUDIODEVICE_H
#define SHOEGAZE2_IAUDIODEVICE_H

#include <Shoegaze2/System/Text/String.h>

#include <utility>
#include "AudioBuffer.h"
#include "AudioMixer.h"
#include "AudioQueue.h"

#include <iostream>

namespace Shoegaze2 {

    class IAudioDescriptor;

    class IAudioDevice {
    public:
        enum DeviceStatus {
            READY,
            RUNNING,
            STOPPED,
            ERROR
        };

        enum DeviceType {
            INPUT,
            OUTPUT
        };
    protected:
        String name;
        DeviceType type;
        DeviceStatus status;
        unsigned int channels;
        unsigned int framesPerBuffer;

        bool firstCallback = true;


        AudioMixer **mixers = nullptr;

        std::vector<IAudioDescriptor*> descriptors;
    public:
        AudioQueue *queue;
        IAudioDevice(const String &name, DeviceType type, unsigned int channels, unsigned int framesPerBuffer) : name(name), type(type), status(READY), channels(channels), framesPerBuffer(framesPerBuffer)
        {
            queue = new AudioQueue(framesPerBuffer*channels*32);
            //std::cout << (type == INPUT ? "IN " : "OUT ") << "R:" << queue->readPtr << " W:" << queue->writePtr << std::endl;
            if (type == OUTPUT) {
                mixers = new AudioMixer*[channels];
                for (size_t i = 0; i < channels; i++)
                    mixers[i] = new AudioMixer(framesPerBuffer);
            }
        }

        virtual void Start() { status = RUNNING; };
        virtual void Stop() { status = STOPPED; };

        void Write(const float *data, size_t count)
        {
            if (status == RUNNING)
                queue->Write(data, count);
        }

        int Read(float *buffer, size_t count) const
        {
            if (status == RUNNING)
                return queue->Read(buffer, count);
            return 0;
        }

        size_t Available() const { return queue->Available(); }


        virtual ~IAudioDevice();
        friend class IAudioDescriptor;
    };
}

#endif //SHOEGAZE2_IAUDIODEVICE_H
