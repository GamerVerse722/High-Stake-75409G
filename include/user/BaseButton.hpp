#pragma once

#include "pros/misc.h"
#include <vector>

namespace button{
    extern bool tgEnterIntake;
    extern bool tgExitIntake;

    class BaseButton {
        private:
            static std::vector<BaseButton*> buttonActions;
            pros::controller_digital_e_t button;
            static bool wasPressed;

        public:
            BaseButton(pros::controller_digital_e_t button);
            virtual ~BaseButton() = default;

            static void run();
            void update();

            virtual void onPress() {}
            virtual void onRelease() {}
    };

}