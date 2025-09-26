#pragma once

#include "Screen.h"
#include "DashboardScreen/DashboardScreen.h"
#include "TestScreen/TestScreen.h"
#include "TerminalScreen/TerminalScreen.h"

#include <map>

DashboardScreen dashboardScreen;
TestScreen testScreen;

class ScreenRegistries {
public:
    std::map<uint16_t, Screen*> screens={
        {-1, nullptr},
        {0, &dashboardScreen},
        {1, &testScreen},
        {2, new TerminalScreen()}
    };

    Screen* getScreen(uint16_t id) {
        if (screens.find(id) != screens.end()) {
            return screens[id];
        }
        return nullptr;
    }
};