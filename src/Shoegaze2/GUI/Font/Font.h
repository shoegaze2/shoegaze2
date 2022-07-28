//
// Created by iashi on 06.01.2022.
//

#ifndef SHOEGAZE2_FONT_H
#define SHOEGAZE2_FONT_H


#include <utility>
#include <vector>
#include <iostream>
#include <cstring>
#include <Shoegaze2/System/Interface/GUI/IPath.h>
#include <Shoegaze2/System/Interface/GUI/IBrush.h>
#include <Shoegaze2/System/Interface/GUI/ICanvas.h>
#include <Shoegaze2/System/Interface/GUI/IRenderingContext.h>
#include <Shoegaze2/System/Text/String.h>

class Vector2
{
public:
    Vector2() {}
    Vector2(float px, float py)
    {
        x = px;
        y = py;
    }

    float x;
    float y;

    Vector2 operator+(const Vector2 &b) { return Vector2(x + b.x, y + b.y); }
    Vector2 operator*(float b) { return Vector2(x * b, y * b); }
};





namespace Shoegaze2 {
    class Glyph {
    public:
        struct GlyphBox {
            float xMin = 0.0f, xMax = 0.0f, yMin = 0.0f, yMax = 0.0f;
        };
        bool started = false;
        std::shared_ptr<IPath> path;
        std::shared_ptr<IPath> outline;
        GlyphBox box;
        float advance;
        Glyph() {
            // TODO: create something more clever, потому что в случае с nanoVG отдельные контексты для отдельных окон
            path = IRenderingContext::Get()->CreatePath();
        }
    };


    class Font {
    private:
        unsigned int characterMap[1200];
        std::vector <Glyph> glyphs;
        int glyphsCount = 0;
        float fontHeight;

        void LoadGlyph(void* face, int code);
    public:
        static Font* DEFAULT;

        Font(const char *path);

        Font(const uint8_t *mem, size_t size);


        Vector2 ConvertPoint(const Vector2 &v, float x, float y, float size) {
            return Vector2(v.x * size + x, -v.y * size + y);
        }

        void DrawGlyph(uint32_t code, float x, float y, float size, const Brush &brush) {
            //cout << "DRAW GLYPH" << endl;
            int glyphIndex = characterMap[code];

            if (glyphIndex != -1) {
                auto g = glyphs[glyphIndex];
                //auto path = g.path->Transform(x, y, size, size);
                //std::cout << "Font::DrawGlyph, code=" << code << " | x=" << x << ",y=" << y << std::endl;
                g.path->Draw(brush, x, y, size, size);
            }
        }

        void DrawString(String &string, float x, float y, float size, const Brush &brush) {
            float cx = x;
            for (size_t i = 0; i < string.Length(); i++) {
                if (string[i] == '\n') {
                    y += size * fontHeight;
                    cx = x;
                }
                else {
                    int glyphIndex = characterMap[string[i]];
                    if (glyphIndex != -1) {
                        auto g = glyphs[glyphIndex];
                        DrawGlyph(string[i], cx, y, size, brush);
                        cx += g.advance * size;
                    }
                }
            }
        }


        float GetTextWidth(String &str, float size) {
            float width = 0.0f;
            for (size_t i = 0; i < str.Length(); i++) {
                int glyph = characterMap[(int) str[i]];
                if (glyph != -1) {
                    width += glyphs[glyph].advance * size;
                }
            }
            return width;
        }
    };
}

#endif //SHOEGAZE2_FONT_H
