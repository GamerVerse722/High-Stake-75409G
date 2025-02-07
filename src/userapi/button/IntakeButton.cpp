#include "user/button/IntakeButton.hpp"
#include "user/Devices.hpp"

using namespace button;
using namespace devices;

EnterIntake::EnterIntake(pros::controller_digital_e_t button, bool setDebug): BaseButton(button, setDebug) {}

void EnterIntake::onPress() {
    lift.move(127);
    intake.move(127);
}

void EnterIntake::onRelease() {
    lift.move(0);
    intake.move(0);
}

ExitIntake::ExitIntake(pros::controller_digital_e_t button, bool setDebug): BaseButton(button, setDebug) {}

void ExitIntake::onPress() {
    lift.move(-127);
    intake.move(-127);
}

void ExitIntake::onRelease() {
    lift.move(0);
    intake.move(0);
}

ToggleIntakeEnter::ToggleIntakeEnter(pros::controller_digital_e_t button, bool setDebug): BaseButton(button, setDebug) {}

void ToggleIntakeEnter::onPress() {
    if (tgEnterIntake) {
        lift.move(0);
        intake.move(0);

        tgEnterIntake = false;
        tgExitIntake = false;

    } else {
        lift.move(127);
        intake.move(127);

        tgEnterIntake = true;
        tgExitIntake = false;
    }
}

void ToggleIntakeEnter::onRelease() {}

ToggleIntakeExit::ToggleIntakeExit(pros::controller_digital_e_t button, bool setDebug): BaseButton(button, setDebug) {}

void ToggleIntakeExit::onPress() {
    if (tgExitIntake) {
        lift.move(0);
        intake.move(0);

        tgEnterIntake = false;
        tgExitIntake = false;

    } else {
        lift.move(-127);
        intake.move(-127);

        tgEnterIntake = false;
        tgExitIntake = true;
    }
    
}

void ToggleIntakeExit::onRelease() {}