#include "user/Devices.hpp"

namespace devices {
    /*
    Left Drivetrain Motors:
        Front: 9
        Back: 10

    Right Drivetrain Motors:
        Front: 1
        Back: 2
    */

    pros::MotorGroup leftMotors({9, 10}, pros::MotorGearset::green);
    pros::MotorGroup rightMotors({1, 2}, pros::MotorGearset::green);

    pros::Imu imu(8);

    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                                &rightMotors, // right motor group
                                12.5, // 10 inch track width
                                lemlib::Omniwheel::OLD_4, // using new 4" omnis
                                360 / 1.4, // drivetrain rpm is 360
                                8 // horizontal drift is 2. If we had traction wheels, it would have been 8
    );

    // lateral motion controller
    lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                                0, // integral gain (kI)
                                                3, // derivative gain (kD)
                                                3, // anti windup
                                                1, // small error range, in inches
                                                100, // small error range timeout, in milliseconds
                                                3, // large error range, in inches
                                                500, // large error range timeout, in milliseconds
                                                20 // maximum acceleration (slew)
    );

    // angular motion controller
    lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                                0, // integral gain (kI)
                                                10, // derivative gain (kD)
                                                3, // anti windup
                                                1, // small error range, in degrees
                                                100, // small error range timeout, in milliseconds
                                                3, // large error range, in degrees
                                                500, // large error range timeout, in milliseconds
                                                0 // maximum acceleration (slew)
    );

    // sensors for odometry
    lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel
                                nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                                nullptr, // horizontal tracking wheel
                                nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                                &imu // inertial sensor
    );

    // input curve for throttle input during driver control
    lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                        10, // minimum output where drivetrain will move out of 127
                                        1.019 // expo curve gain
    );

    // input curve for steer input during driver control
    lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                    10, // minimum output where drivetrain will move out of 127
                                    1.019 // expo curve gain
    );

    // create the chassis
    lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);

    pros::MotorGroup mobileGoal({7, -6}, pros::MotorGearset::green);

    pros::Motor intake(12);
    pros::Motor lift(-11);
}