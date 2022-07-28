//
// Created by iashi on 06.01.2022.
//

#include "Font.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_OUTLINE_H
#include <freetype/ftstroke.h>

using namespace Shoegaze2;

Font* Font::DEFAULT = nullptr;

float convFTFixed(const FT_Pos &x)
{
    return (float)x / 4096.0f;
}

Vector2 convFTVector(const FT_Vector &v)
{
    return Vector2(convFTFixed(v.x), -convFTFixed(v.y));
}

int moveTo(const FT_Vector *to, void *user)
{
    auto glyph = static_cast<Glyph *>(user);

    if (glyph->started)
        glyph->path->Close();
    else
        glyph->started = true;

    auto p = convFTVector(*to);
    glyph->path->MoveTo(p.x, p.y);
    return 0;
}

int lineTo(const FT_Vector *to, void *user)
{
    auto glyph = static_cast<Glyph *>(user);
    auto p = convFTVector(*to);
    glyph->path->LineTo(p.x, p.y);
    return 0;
}

int conicTo(const FT_Vector *control, const FT_Vector *to, void *user)
{
    auto glyph = static_cast<Glyph *>(user);
    auto p = convFTVector(*to);
    auto c = convFTVector(*control);
    glyph->path->QuadTo(c.x, c.y, p.x, p.y);
    return 0;
}

int cubicTo(const FT_Vector *control1, const FT_Vector *control2, const FT_Vector *to, void *user)
{
    auto glyph = static_cast<Glyph *>(user);
    auto c1 = convFTVector(*control1);
    auto c2 = convFTVector(*control2);
    auto p = convFTVector(*to);
    glyph->path->CubicTo(c1.x, c1.y, c2.x, c2.y, p.x, p.y);
    return 0;
}

FT_Outline_Funcs outlineFuncs =
        {
                moveTo,
                lineTo,
                conicTo,
                cubicTo,
                0, // no shift
                0  // no delta
        };

void Font::LoadGlyph(void* facePtr, int code) {
    if (code < 32)
        return; //discard the first 32 characters
    auto face = (FT_Face)facePtr;
    int glyphIndex = FT_Get_Char_Index(face, code);

    if (!FT_Load_Glyph(face, glyphIndex,
                       FT_LOAD_NO_BITMAP | FT_LOAD_NO_HINTING | FT_LOAD_IGNORE_TRANSFORM)) {
        float advance = convFTFixed(face->glyph->advance.x);

        FT_Outline &outline = face->glyph->outline;


        Glyph g;
        g.advance = advance;

        Glyph::GlyphBox box;
        FT_BBox b;
        FT_Outline_Get_CBox(&outline, &b);
        box.xMin = convFTFixed(b.xMin);
        box.xMax = convFTFixed(b.xMax);
        box.yMin = convFTFixed(b.yMin);
        box.yMax = convFTFixed(b.yMax);
        g.box = box;

        FT_Outline_Decompose(&outline, &outlineFuncs, &g);


        this->glyphs.push_back(g);
        characterMap[code] = glyphsCount++;
    }
}

Shoegaze2::Font::Font(const char *path) {
    FT_Library library;
    FT_Face face;

    if (FT_Init_FreeType(&library)) {
        printf("couldn't initialize freetype\n");
        return;
    }

    int faceIndex = 0;
    if (FT_New_Face(library, path, faceIndex, &face)) {
        printf("couldn't load new face\n");
        return;
    }

    FT_Set_Char_Size(
            face,    /* handle to face object           */
            0,       /* char_width in 1/64th of points  */
            64 * 64, /* char_height in 1/64th of points */
            96,      /* horizontal device resolution    */
            96);     /* vertical device resolution      */

    int glyphs = 0;
    for (int cc = 0; cc < 1200; cc++) {
        LoadGlyph(face, cc);
    }
    fontHeight = convFTFixed(face->size->metrics.ascender - face->size->metrics.descender);
    std::cout << "Font height: " << fontHeight << std::endl;
    /*for (int cc = 1024; cc < 1280; cc++) {
        LoadGlyph(face, cc);
    }*/

    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

Shoegaze2::Font::Font(const uint8_t *mem, size_t size) {
    FT_Library library;
    FT_Face face;

    if (FT_Init_FreeType(&library)) {
        printf("couldn't initialize freetype\n");
        return;
    }

    int faceIndex = 0;
    if (FT_New_Memory_Face(library, mem, size, faceIndex, &face)) {
        printf("couldn't load new face\n");
        return;
    }

    FT_Set_Char_Size(
            face,    /* handle to face object           */
            0,       /* char_width in 1/64th of points  */
            64 * 64, /* char_height in 1/64th of points */
            96,      /* horizontal device resolution    */
            96);     /* vertical device resolution      */

    int glyphs = 0;
    for (int cc = 0; cc < 1200; cc++) {
        LoadGlyph(face, cc);
    }
    fontHeight = convFTFixed(face->size->metrics.ascender - face->size->metrics.descender);
    std::cout << "Font height: " << fontHeight << std::endl;
    /*for (int cc = 1024; cc < 1280; cc++) {
        LoadGlyph(face, cc);
    }*/

    FT_Done_Face(face);
    FT_Done_FreeType(library);
}
