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
            for (auto &c : children) {
                c.canvas->SetPosition(c.container->GetPosition());
                c.canvas->Resize(c.container->GetSize());
            }
        }
        virtual void Update() override {
            for (auto &c : children) {
                c.container->Update();
            }
        };

        void OnDraw(Canvas canvas) override {
            for (auto &c : children) {
                c.canvas->SetParent(canvas.ptr);
                c.container->OnDraw(c.canvas);
            }
        }

        void Add(Container *c) {
            Canvas canvas(c->GetPosition(), c->GetSize());
            children.emplace_back(Child{c, canvas});
        }

        void OnTouchEvent(float x, float y) override {
            Container::OnTouchEvent(x, y);
            for (auto &c : children) {
                c.container->OnTouchEvent(x - position.x, y - position.y);
            }
        }
    };
}

#endif //SHOEGAZE2_LAYOUT_H
