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
            b->SetSize({200, 150});
            b->SetText(text);
            b->SetBackgroundColor(Color::FromRGBAf(0.75, 0, 0, 1));
            b->onClickEvent = handler;
            return b;
        }
    public:
        LinearLayout mainLayout = LinearLayout(LinearLayout::VERTICAL);
        LinearLayout layout = LinearLayout(LinearLayout::VERTICAL);

        Button *labelButton;
        Button *delayButton, *boostButton;
        bool delay = false;
        bool boost = false;

        DemoApp() {
            labelButton = new Button();
            labelButton->SetText("Demo Application");
            labelButton->SetSize({0, 200});

            delayButton = CreateButton("Delay", [&](Position p) {
                delay = !delay;
                if (delay) {
                    delayButton->SetBackgroundColor(Color::FromRGBAf(0, 0.75, 0, 1));
                } else {
                    delayButton->SetBackgroundColor(Color::FromRGBAf(0.75, 0, 0, 1));
                }
            });

            boostButton = CreateButton("Boost", [&](Position p) {
                boost = !boost;
                if (boost) {
                    boostButton->SetBackgroundColor(Color::FromRGBAf(0, 0.75, 0, 1));
                } else {
                    boostButton->SetBackgroundColor(Color::FromRGBAf(0.75, 0, 0, 1));
                }
            });

            layout.Add(delayButton);
            layout.Add(boostButton);

            mainLayout.Add(labelButton);
            mainLayout.Add(&layout);

            SetContent(&mainLayout);
        }
    };
}
#endif //SHOEGAZE2_DEMOAPP_H
