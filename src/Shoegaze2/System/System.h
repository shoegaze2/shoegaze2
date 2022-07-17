//
// Created by iashi on 07.06.2022.
//

#ifndef SHOEGAZE2_SYSTEM_H
#define SHOEGAZE2_SYSTEM_H

#include <vector>
#include <Shoegaze2/Apps/Application.h>

namespace Shoegaze2 {
    class System {
    public:
        std::vector<Application*> apps;
        Application *currentApplication;

        template<class AppClass>
        void LaunchApp() {
            Application *app = (Application*)new AppClass();
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

        void OnTouchEvent(float x, float y) {
            if (currentApplication != nullptr) {
                currentApplication->OnTouchEvent(x, y);
            }
        }

        void OnAudio() {

        }
    };
}

#endif //SHOEGAZE2_SYSTEM_H
