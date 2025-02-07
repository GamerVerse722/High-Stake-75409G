#include "user/button/MobileGoalButton.hpp"
#include "user/Devices.hpp"

using namespace button;
using namespace devices;

MobileGoalIn::MobileGoalIn(pros::controller_digital_e_t button, bool setDebug): BaseButton(button, setDebug) {}

void MobileGoalIn::onPress() {
    mobileGoal.move(127);
}

void MobileGoalIn::onRelease() {
    mobileGoal.brake();
}

MobileGoalOut::MobileGoalOut(pros::controller_digital_e_t button, bool setDebug): BaseButton(button, setDebug) {}

void MobileGoalOut::onPress() {
    mobileGoal.move(-127);
}

void MobileGoalOut::onRelease() {
    mobileGoal.brake();
}