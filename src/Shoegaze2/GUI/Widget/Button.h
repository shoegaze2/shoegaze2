//
// Created by iashi on 17.04.2022.
//

#ifndef SHOEGAZE2_BUTTON_H
#define SHOEGAZE2_BUTTON_H

#include "Shoegaze2/GUI/View.h"
#include "Shoegaze2/System/Text/String.h"

namespace Shoegaze2 {
    class Button : public View {
    private:
        String text;
        Paint backgroundPaint;
        Brush backgroundBrush;

        Paint textPaint;
        Brush textBrush;
        Path rect;
    public:
        Button()
        {
            backgroundPaint->SetColor(Color::FromRGBf(0.75f, 0, 0.75f));
            textPaint->SetColor(Color::FromRGBf(1, 1, 1));
            backgroundBrush->SetPaint(backgroundPaint);
            textBrush->SetPaint(textPaint);
            textBrush->SetPaintMode(PaintMode::Fill);

            rect->AppendRect(0, 0, GetSize().width, GetSize().height);
        }

        void OnResize(Size newSize) override
        {
            size = newSize;
            rect->Clear();
            rect->AppendRect(0, 0, GetSize().width, GetSize().height);
        }

        void Update() {
            float tw = Font::DEFAULT->GetTextWidth(text, size.height/2) + 20;
            if (tw > size.width) {
                size.width = tw;
                rect->Clear();
                rect->AppendRect(0, 0, GetSize().width, GetSize().height);
            }
        }

        void OnDraw(Canvas canvas)
        {
            canvas.DrawPath(rect, backgroundBrush);
            float fontHeight = size.height/2;
            canvas.DrawText(text, Position(10, GetSize().height/2 + fontHeight/2), fontHeight, textBrush, Font::DEFAULT);
        }

        void SetText(const String &str)
        {
            text = str;
        }

        void SetBackgroundColor(const Color &color)
        {
            backgroundPaint->SetColor(color);
        }

        void SetTextColor(const Color &color)
        {
            textPaint->SetColor(color);
        }
    };
}

#endif //SHOEGAZE2_BUTTON_H
