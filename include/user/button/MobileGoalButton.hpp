#pragma once

#include "user/BaseButton.hpp"
using namespace button;

class MobileGoalIn: public BaseButton {
    public:
        MobileGoalIn(pros::controller_digital_e_t button);
        void onPress() override;
        void onRelease() override;
};

class MobileGoalOut: public BaseButton {
    public:
        MobileGoalOut(pros::controller_digital_e_t button);
        void onPress() override;
        void onRelease() override;
};