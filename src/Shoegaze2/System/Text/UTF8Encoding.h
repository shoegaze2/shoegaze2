//
// Created by iashi on 06.01.2022.
//

#ifndef SHOEGAZE2_UTF8ENCODING_H
#define SHOEGAZE2_UTF8ENCODING_H

#include "Encoding.h"
#include "String.h"

#include <cstring>

namespace Shoegaze2 {
    class UTF8Encoding : public Encoding {
    private:
        static inline bool checkOctet(char octet) {
            return (octet & 0xC0) == 0x80;
        }

        static int getCharLength(const char *bytes) {
            if (bytes[0] != '\0') {
                uint8_t first = bytes[0];
                if ((first & 0x80) == 0x00)
                    return 1;
                else if ((first & 0xE0) == 0xC0)
                    return 2;
                else if ((first & 0xF0) == 0xE0)
                    return 3;
                else if ((first & 0xF8) == 0xF0)
                    return 4;
            }
            return 0;
        }

        static uint32_t decodeChar(const char *bytes, int *length, bool *correct) {
            int l = 0;
            int c = false;
            uint32_t code = 0;
            uint8_t first = bytes[0];
            int chrLen = getCharLength(bytes);
            if (chrLen == 1) {
                c = true;
                l = 1;
                code = first;
            } else if (chrLen == 2) {
                c = checkOctet(bytes[1]);
                l = 2;
                code = ((first & 0x1F) << 6) | (bytes[1] & 0x3F);
            } else if (chrLen == 3) {
                c = checkOctet(bytes[1]) && checkOctet(bytes[2]);
                l = 3;
                code = ((first & 0x0F) << 12) | ((bytes[1] & 0x3F) << 6) | (bytes[2] & 0x3F);
            } else if (chrLen == 4) {
                c = checkOctet(bytes[1]) && checkOctet(bytes[2]) && checkOctet(bytes[3]);
                l = 4;
                code = ((first & 0x07) << 18) | ((bytes[1] & 0x3F) << 12) | ((bytes[2] & 0x3F) << 6) |
                       (bytes[3] & 0x3F);
            }


            if (correct != nullptr)
                *correct = c;
            if (length != nullptr)
                *length = l;
            return code;
        }

        static std::vector<uint32_t> decodeCharStream(const char *chr) {
            size_t len = strlen(chr);
            int i = 0;
            int charCount = 0;
            while (i < len) {
                int chrLen = getCharLength(chr + i);
                if (chrLen == 0)
                    break;
                i += chrLen;
                charCount++;
            }
            std::vector<uint32_t> codes;
            codes.reserve(charCount);
            int pos = 0;
            while (pos < i) {
                int chrLen = 0;
                bool correct = false;
                uint32_t code = decodeChar(chr + pos, &chrLen, &correct);
                if (correct) {
                    codes.emplace_back(code);
                }
                pos += chrLen;
            }
            return codes;
        }

    public:

        uint32_t DecodeChar(const char *chr) const {
            return decodeChar(chr, nullptr, nullptr);
        }

        String GetString(const char *bytes) const {
            return String(decodeCharStream(bytes));
        }

        std::vector<uint32_t> DecodeBytes(const char* bytes) const {
            return decodeCharStream(bytes);
        }
    };
}

#endif //SHOEGAZE2_UTF8ENCODING_H
