#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "user/button/IntakeButton.hpp"
#include "user/button/MobileGoalButton.hpp"

namespace devices {
    extern pros::MotorGroup leftMotors;
    extern pros::MotorGroup rightMotors;

    extern pros::Imu imu;
    extern pros::Controller controller;

    extern lemlib::Drivetrain drivetrain;

    extern lemlib::ControllerSettings linearController;
    extern lemlib::ControllerSettings angularController;
    extern lemlib::OdomSensors sensors;
    extern lemlib::ExpoDriveCurve throttleCurve;
    extern lemlib::ExpoDriveCurve steerCurve;
    extern lemlib::Chassis chassis;

    extern pros::MotorGroup mobileGoal;
    extern pros::Motor intake;
    extern pros::Motor lift;
}

namespace configuredButtons{
    extern EnterIntake intakeButton;
    extern ExitIntake exitIntakeButton;
    extern ToggleIntakeEnter toggleIntakeEnterButton;
    extern ToggleIntakeExit toggleIntakeExitButton;

    extern MobileGoalIn mobileGoalInButton;
    extern MobileGoalOut mobileGoalOutButton;
    extern ToggleMobileGoal toggleMobileGoalButton;
}