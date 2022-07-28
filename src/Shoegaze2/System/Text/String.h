//
// Created by iashi on 06.01.2022.
//

#ifndef SHOEGAZE2_STRING_H
#define SHOEGAZE2_STRING_H

#include <cstdint>
#include <utility>
#include <vector>
#include "Encoding.h"

namespace Shoegaze2 {

    class String {
    protected:
        Encoding::Encodings encoding = Encoding::Encodings::Default;
        std::vector<uint32_t> codes;
    public:
        struct CharCode {
        private:
            String &string;
            int index;
        public:
            CharCode(String &string, int index) : string(string), index(index)
            {

            }

            operator uint32_t() const {
                return string.codes[index];
            }

            uint32_t& operator=(const uint32_t& other) const {
                return string.codes[index] = other;
            }

            uint32_t& operator=(const char* other) const {
                return string.codes[index] = Encoding::GetEncoding(Encoding::Encodings::Default).DecodeChar(other);
            }
        };

        String() {}

        String(const char* str) {
            codes = Encoding::GetEncoding(encoding).DecodeBytes(str);
        }

        String(std::vector<uint32_t> codes) : codes(std::move(codes)) {

        }

        String &operator+=(const String &str) {
            codes.reserve(str.codes.size());
            for (auto &c : str.codes) {
                codes.emplace_back(c);
            }
            return *this;
        }

        void RemoveAt(int index) {
            if (!codes.empty() && index < codes.size()) {
                auto del = codes.begin() + index;
                if (del < codes.end()) {
                    codes.erase(del);
                }
            }
        }

        void Substring(int start, int end) {
            std::vector<uint32_t> substr;
        }

        const CharCode operator[](int index) {
            return CharCode(*this, index);
        }

        size_t Length() const {
            return codes.size();
        }

        const Encoding& GetEncoding() {
            return Encoding::GetEncoding(encoding);
        }

        friend struct CharCode;
    };
}

#endif //SHOEGAZE2_STRING_H
