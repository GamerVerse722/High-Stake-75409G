#include "user/button/MobileGoalButton.hpp"
#include "user/Devices.hpp"

using namespace button;
using namespace devices;

MobileGoalIn::MobileGoalIn(pros::controller_digital_e_t button): BaseButton(button) {}

void MobileGoalIn::onPress() {
    mobileGoal.move(127);
}

void MobileGoalIn::onRelease() {
    mobileGoal.brake();
}

MobileGoalOut::MobileGoalOut(pros::controller_digital_e_t button): BaseButton(button) {}

void MobileGoalOut::onPress() {
    mobileGoal.move(-127);
}

void MobileGoalOut::onRelease() {
    mobileGoal.brake();
}