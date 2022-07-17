//
// Created by iashi on 06.01.2022.
//

#ifndef SHOEGAZE2_ENCODING_H
#define SHOEGAZE2_ENCODING_H

#include <stdint.h>
#include <vector>

namespace Shoegaze2 {
    class String;

    class Encoding {
    public:
        enum class Encodings {
            UTF8,
            Default
        };

        static const Encoding& UTF8;

        static const Encoding& GetEncoding(Encodings e) {
            switch (e) {
                case Encodings::UTF8:
                    return UTF8;
                case Encodings::Default:
                    return UTF8;
                default:
                    return UTF8;
            }
        }

        virtual uint32_t DecodeChar(const char* chr) const = 0;
        virtual String GetString(const char* str) const = 0;
        virtual std::vector<uint32_t> DecodeBytes(const char* bytes) const = 0;
    };
}

#endif //SHOEGAZE2_ENCODING_H
