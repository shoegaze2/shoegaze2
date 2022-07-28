//
// Created by iashi on 07.06.2022.
//

#ifndef SHOEGAZE2_SYSTEM_H
#define SHOEGAZE2_SYSTEM_H

#include <vector>
#include <Shoegaze2/System/Interface/GUI/IUISystem.h>
#include <Shoegaze2/Apps/Application.h>

namespace Shoegaze2 {
    class System {
    private:
        IUISystem* ui;
        std::vector<Application*> apps;
        Application *currentApplication;
    public:
        System(IUISystem* ui) : ui(ui) {
            ui->OnClick = [&](Position p) { OnClickEvent(p.x, p.y); };
        }

        template<class AppClass>
        void LaunchApp() {
            auto *app = (Application*)new AppClass();
            apps.emplace_back(app);
            currentApplication = app;
        }

        void Update() {
            if (currentApplication != nullptr)
                currentApplication->Update();
        }

        void Render() {
            if (currentApplication != nullptr) {
                currentApplication->Draw();
            }
        }

        void OnClickEvent(float x, float y) {
            if (currentApplication != nullptr) {
                currentApplication->OnClickEvent(x, y);
            }
        }
    };
}

#endif //SHOEGAZE2_SYSTEM_H
