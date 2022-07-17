//
// Created by iashi on 07.06.2022.
//

#ifndef SHOEGAZE2_DEMOAPP_H
#define SHOEGAZE2_DEMOAPP_H

#include <Shoegaze2/Apps/Application.h>
#include <Shoegaze2/GUI/Widget/Button.h>
#include <Shoegaze2/GUI/Layout/LinearLayout.h>

namespace Shoegaze2 {
    class DemoApp : public Application {
    private:
        Button *CreateButton(String text, std::function<void(Position)> handler) {
            Button *b = new Button();
            b->SetSize({100, 150});
            b->SetText(text);
            b->SetBackgroundColor(Color::FromRGBAf(1, 0, 0, 1));
            b->onClickEvent = handler;
            return b;
        }
    public:
        LinearLayout layout = LinearLayout(LinearLayout::LinearLayoutType::HORIZONTAL);

        Button *delayButton, *boostButton;
        bool delay = false;
        bool boost = false;

        DemoApp() {
            delayButton = CreateButton("Задержка", [&](Position p) {
                delay = !delay;
                if (delay) {
                    delayButton->SetBackgroundColor(Color::FromRGBAf(0, 1, 0, 1));
                } else {
                    delayButton->SetBackgroundColor(Color::FromRGBAf(1, 0, 0, 1));
                }
            });

            boostButton = CreateButton("Усиление", [&](Position p) {
                boost = !boost;
                if (boost) {
                    boostButton->SetBackgroundColor(Color::FromRGBAf(0, 1, 0, 1));
                } else {
                    boostButton->SetBackgroundColor(Color::FromRGBAf(1, 0, 0, 1));
                }
            });

            layout.Add(delayButton);
            layout.Add(boostButton);

            SetContent(&layout);
        }

        void AudioHandler() override {

        }
    };
}
#endif //SHOEGAZE2_DEMOAPP_H
