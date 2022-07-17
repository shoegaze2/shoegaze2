//
// Created by iashi on 07.06.2022.
//

#ifndef SHOEGAZE2_LINEARLAYOUT_H
#define SHOEGAZE2_LINEARLAYOUT_H

#include <Shoegaze2/GUI/Layout.h>

namespace Shoegaze2 {
    class LinearLayout : public Layout {
    public:
        enum LinearLayoutType {
            VERTICAL,
            HORIZONTAL
        };
    private:
        LinearLayoutType type;
    public:


        LinearLayout(LinearLayoutType type) : type(type) {

        }

        void Update() override {
            Layout::Update();

            if (type == VERTICAL) {
                float y = 0;
                for (auto &c: children) {
                    c.container->SetPosition({0, y});
                    y += c.container->GetSize().height + 10;
                }
            } else if (type == HORIZONTAL) {
                float x = 0;
                for (auto &c: children) {
                    c.container->SetPosition({x, 0});
                    x += c.container->GetSize().width + 10;
                }
            }

            Layout::PostUpdate();
        }
    };
}

#endif //SHOEGAZE2_LINEARLAYOUT_H
