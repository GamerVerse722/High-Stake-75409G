#pragma once

#include "../BaseButton.hpp"

using namespace button;

class EnterIntake: public BaseButton {
    public:
        EnterIntake(pros::controller_digital_e_t button, bool setDebug = false);
        void onPress() override;
        void onRelease() override;
};

class ExitIntake: public BaseButton {
    public:
        ExitIntake(pros::controller_digital_e_t button, bool setDebug = false);
        void onPress() override;
        void onRelease() override;
};

class ToggleIntakeEnter: public BaseButton {
    public:
        ToggleIntakeEnter(pros::controller_digital_e_t button, bool setDebug = false);
        void onPress() override;
        void onRelease() override;
};

class ToggleIntakeExit: public BaseButton {
    public:
        ToggleIntakeExit(pros::controller_digital_e_t button, bool setDebug = false);
        void onPress() override;
        void onRelease() override;
};