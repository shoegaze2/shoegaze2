//
// Created by iashi on 07.06.2022.
//

#ifndef SHOEGAZE2_APPLICATION_H
#define SHOEGAZE2_APPLICATION_H

#include <Shoegaze2/GUI/Drawing/Canvas.h>
#include <Shoegaze2/GUI/Container.h>

namespace Shoegaze2 {
    class Application {
    private:
        Container *content = nullptr;
        Canvas canvas;
        Canvas contentCanvas;
    protected:
        void SetContent(Container *contentView) {
            this->content = contentView;
            contentCanvas->Resize(contentView->GetSize());
            contentCanvas->SetPosition(contentView->GetPosition());
        }
    public:
        Application() : canvas(Position(0, 0), Size(IRenderingContext::Get()->GetWidth(), IRenderingContext::Get()->GetHeight())),
                        contentCanvas(Position(0, 0), Size(0, 0), canvas) {

        }

        virtual void Start() {};
        void Exit() {};

        void Update() {
            if (content != nullptr) {
                content->Update();
            }
        }

        void Draw() {
            content->OnDraw(contentCanvas);
        }

        void OnTouchEvent(float x, float y) {
            if (content != nullptr)
                content->OnTouchEvent(x, y);
        }

        virtual void AudioHandler() {};
    };
}

#endif //SHOEGAZE2_APPLICATION_H
