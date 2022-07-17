//
// Created by iashi on 02.03.2022.
//

#ifndef SHOEGAZE2_AUDIOBUFFER_H
#define SHOEGAZE2_AUDIOBUFFER_H

#include <cstring>

namespace Shoegaze2
{
    class AudioBuffer
    {
    protected:
        float *buffer = nullptr;
        size_t size = 0;
    public:
        explicit AudioBuffer(size_t size)
        {
            this->size = size;
            buffer = new float[size];
        }

        AudioBuffer(const AudioBuffer& buffer)
        {
            this->size = buffer.size;
            this->buffer = new float[this->size];
            memcpy(this->buffer, buffer.buffer, this->size*sizeof(float));
        }

        AudioBuffer& operator=(const AudioBuffer& buffer)
        {
            if (this->buffer != nullptr)
                delete [] this->buffer;

            this->size = buffer.size;
            this->buffer = new float[this->size];
            memcpy(this->buffer, buffer.buffer, this->size*sizeof(float));
        }

        inline float & operator[](int index)
        {
            // TODO: maybe check bounds
            return buffer[index];
        }

        inline float & operator[](size_t index)
        {
            // TODO: maybe check bounds
            return buffer[index];
        }

        inline size_t GetSize() const { return size; }

        void Clear()
        {
            for (size_t i = 0; i < size; i++)
                buffer[i] = 0.0f;
        }

        // TODO: use copy constructor or assignment
        /*AudioBuffer Copy() const
        {
            return AudioBuffer(*this);
        }*/

        ~AudioBuffer()
        {
            delete [] buffer;
        }

        friend class AudioMixer;
        friend class IAudioDevice;
    };
}

#endif //SHOEGAZE2_AUDIOBUFFER_H
