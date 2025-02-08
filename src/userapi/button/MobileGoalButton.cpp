#include "user/button/MobileGoalButton.hpp"
#include "pros/rtos.hpp"
#include "user/Devices.hpp"
#include <iostream>

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

ToggleMobileGoal::ToggleMobileGoal(pros::controller_digital_e_t button, bool setDebug): BaseButton(button, setDebug) {}

void ToggleMobileGoal::onPress() {
    pros::Task toggleMobileGoal = pros::Task{ [] {
        if (0 < mobileGoal.get_position()) {
            mobileGoal.move(-127);
            pros::delay(50);
            while (true) {
                std::cout << "Position: " << mobileGoal.get_position() << ", Velocity: " << mobileGoal.get_actual_velocity() << std::endl;
                if (std::abs(mobileGoal.get_actual_velocity()) == 0) {
                    mobileGoal.brake();
                    break;
                }
                pros::delay(10);
            }
        } else {
            mobileGoal.move_absolute(160, 127);
        }
    }};
    toggleMobileGoal.notify();
}

void ToggleMobileGoal::onRelease() {}