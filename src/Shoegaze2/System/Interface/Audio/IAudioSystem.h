//
// Created by iashi on 02.03.2022.
//

#ifndef SHOEGAZE2_IAUDIOSYSTEM_H
#define SHOEGAZE2_IAUDIOSYSTEM_H

#include <unordered_map>

namespace Shoegaze2 {

    class IAudioDevice;
    class IAudioDescriptor;

    class IAudioSystem {
    private:
        static IAudioSystem *handle;
    protected:
        std::unordered_map<int, IAudioDevice*> devices;
    public:
        IAudioSystem() { handle = this; }

        virtual bool Initialize() = 0;
        virtual void Refresh() = 0;

        IAudioDevice* GetDevice(const IAudioDescriptor& descriptor);

        static IAudioSystem *Get() { return handle; }

        virtual ~IAudioSystem() = default;
    };
}

#endif //SHOEGAZE2_IAUDIOSYSTEM_H
