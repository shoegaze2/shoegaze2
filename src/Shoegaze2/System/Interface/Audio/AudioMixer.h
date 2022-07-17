//
// Created by iashi on 03.03.2022.
//

#ifndef SHOEGAZE2_AUDIOMIXER_H
#define SHOEGAZE2_AUDIOMIXER_H

#include "AudioBuffer.h"
#include <algorithm>

namespace Shoegaze2 {
    class AudioMixer {
    private:
        double *data;
        size_t size;
    public:
        explicit AudioMixer(size_t size)
        {
            this->size = size;
            data = new double[size];
            for (size_t i = 0; i < size; i++)
                data[i] = 0.0;
        }

        void AppendBuffer(const AudioBuffer &buffer, double gain = 1.0)
        {
            float *bufferData = buffer.buffer;
            size_t minSize = std::min(buffer.size, size);
            for (size_t i = 0; i < minSize; i++)
                data[i] += gain * bufferData[i];
        }

        void GetResult(AudioBuffer& buffer, bool clip = true)
        {
            /*double RMS = 0.0;
            for (size_t i = 0; i < size; i++)
                RMS += data[i]*data[i];
            RMS /= (double)size;
            RMS = sqrt(RMS);
            double gain = 1.0 / (sqrt(2)*RMS);*/
            double gain = 1.0;

            size_t minSize = std::min(buffer.size, size);
            for (size_t i = 0; i < minSize; i++) {
                buffer[i] = (float)(gain * data[i]);
                if (clip) {
                    if (buffer[i] > 1.0f)
                        buffer[i] = 1.0f;
                    else if (buffer[i] < -1.0f)
                        buffer[i] = -1.0f;
                }
            }
        }

        void Clear()
        {
            for (size_t i = 0; i < size; i++)
                data[i] = 0.0;
        }
    };
}

#endif //SHOEGAZE2_AUDIOMIXER_H
