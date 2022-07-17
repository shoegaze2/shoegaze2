//
// Created by iashi on 04.03.2022.
//

#ifndef SHOEGAZE2_AUDIOQUEUE_H
#define SHOEGAZE2_AUDIOQUEUE_H

#include <cstring>
#include <iostream>

namespace Shoegaze2 {
    class AudioQueue {
    public:
        float *queue;
        size_t writeIndex = 0, readIndex = 0;
        size_t size;
    public:
        explicit AudioQueue(size_t size) : size(size) {
            queue = new float[size];
        }

        size_t Free()
        {
            if (readIndex <= writeIndex)
                return (int)size + readIndex - writeIndex;
            return readIndex - writeIndex;
        }

        size_t Available()
        {
            if (writeIndex < readIndex)
                return (int)size + writeIndex - readIndex;
            return writeIndex-readIndex;
        }

        void Write(const float *buffer, size_t count) {
            if (count == 0)
                return;

            int f = Free();
            if (f <= 0)
                return;

            int length = f < count ? f : (int)count;

            int i = 0;
            int length_i = length;
            while (length_i-- > 0)
            {
                queue[writeIndex] = buffer[i++];
                if (++writeIndex == size)
                    writeIndex = 0;
            }
        }

        int Read(float *buffer, size_t count)
        {
            if (count == 0)
                return 0;
            int a = Available();
            if (a <= 0)
                return 0;

            int length = a < count ? a : (int)count;
            int i = 0;
            int length_i = length;
            while (length_i-- > 0)
            {
                buffer[i++] = queue[readIndex];
                if (++readIndex == size)
                    readIndex = 0;
            }
            return length;
        }

        void Resize(size_t newSize)
        {
            queue = (float*)realloc(queue, newSize*sizeof(float));
            this->size = newSize;
        }

        size_t GetSize() const { return size; }

        ~AudioQueue()
        {
            delete [] queue;
        }
    };
}


#endif //SHOEGAZE2_AUDIOQUEUE_H
