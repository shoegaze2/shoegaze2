//
// Created by iashi on 07.06.2022.
//

#ifndef SHOEGAZE2_LAYOUT_H
#define SHOEGAZE2_LAYOUT_H

#include <Shoegaze2/GUI/Container.h>
#include <vector>


namespace Shoegaze2 {
    class Layout : public Container {
    protected:
        struct Child {
            Container* container;
            Canvas canvas;
        };
        std::vector<Child> children;
    public:
        void PostUpdate() {
            float maxX = 0, maxY = 0;
            for (auto &c : children) {
                auto cPos = c.container->GetPosition();
                auto cSize = c.container->GetSize();
                c.canvas.SetPosition(cPos);
                c.canvas.Resize(cSize);

                if (cPos.x + cSize.width > maxX) {
                    maxX = cPos.x + cSize.width;
                }

                if (cPos.y + cSize.height > maxY) {
                    maxY = cPos.y + cSize.height;
                }
            }

            SetSize({maxX, maxY});
        }
        virtual void Update() override {
            for (auto &c : children) {
                c.container->Update();
            }
        };

        void OnDraw(const Canvas &canvas) override {
            for (auto &c : children) {
                c.canvas.SetParent(canvas);
                c.container->OnDraw(c.canvas);
            }
        }

        void Add(Container *c) {
            Canvas canvas(c->GetPosition(), c->GetSize());
            children.emplace_back(Child{c, canvas});
        }

        void OnClickEvent(float x, float y) override {
            Container::OnClickEvent(x, y);
            for (auto &c : children) {
                auto cSize = c.container->GetSize();
                auto cPos = c.container->GetPosition();
                if (cPos.x <= x && cPos.x + cSize.width >= x && cPos.y <= y && cPos.y + cSize.height >= y) {
                    c.container->OnClickEvent(x - cPos.x, y - cPos.y);
                }
            }
        }
    };
}

#endif //SHOEGAZE2_LAYOUT_H
