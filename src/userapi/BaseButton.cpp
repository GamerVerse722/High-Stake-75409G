#include "user/BaseButton.hpp"
#include "user/Devices.hpp"

namespace button {
    bool tgEnterIntake = false;
    bool tgExitIntake = false;

    std::vector<BaseButton*> BaseButton::buttonActions;
    bool BaseButton::wasPressed;

    BaseButton::BaseButton(pros::controller_digital_e_t button) : button(button) {
        buttonActions.push_back(this);
    }

    void BaseButton::run() {

        for (BaseButton* action : buttonActions) {
            action->update();
            pros::delay(10);
        }
    }

    void BaseButton::update() {
        bool isPressed = devices::controller.get_digital(button);

        if (isPressed && !wasPressed) {
            onPress();
        } else if (!isPressed && wasPressed) {
            onRelease();
        }

        wasPressed = isPressed;
        std::cout << isPressed << ", " << wasPressed << std::endl;
    }
}