// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


//..........chassis..........

std::shared_ptr<CANTalon> RobotMap::chassisLeft1Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisLeft2Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisLeft3Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight1Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight2Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight3Wheel;

std::shared_ptr<DoubleSolenoid> RobotMap::chassisShifter;
std::shared_ptr<DoubleSolenoid> RobotMap::chassisKickstand;

//.........intake..........

std::shared_ptr<CANTalon> RobotMap::intakeMecanumWheels;
std::shared_ptr<DoubleSolenoid> RobotMap::intakeArms;

//..........shooter..........

std::shared_ptr<CANTalon> RobotMap::shooterLeftFlywheel;
std::shared_ptr<CANTalon> RobotMap::shooterRightFlywheel;
std::shared_ptr<CANTalon> RobotMap::shooterRoller;

std::shared_ptr<DoubleSolenoid> RobotMap::shooterLifter;

//..........arms..........

std::shared_ptr<CANTalon> RobotMap::armsLeftBrazo;
std::shared_ptr<CANTalon> RobotMap::armsRightBrazo;

void RobotMap::init() {

    LiveWindow *lw = LiveWindow::GetInstance();


    //..........chassis..........

    chassisLeft1Wheel.reset(new CANTalon(kLeft1ID));
    lw->AddActuator("Chassis", "Left1Wheel", chassisLeft1Wheel);

    chassisLeft2Wheel.reset(new CANTalon(kLeft2ID));
    lw->AddActuator("Chassis", "Left2Wheel", chassisLeft2Wheel);

    chassisLeft3Wheel.reset(new CANTalon(kLeft3ID));
    lw->AddActuator("Chassis", "Left3Wheel", chassisLeft3Wheel);

    chassisRight1Wheel.reset(new CANTalon(kRight1ID));
    lw->AddActuator("Chassis", "Right1Wheel", chassisRight1Wheel);

    chassisRight2Wheel.reset(new CANTalon(kRight2ID));
    lw->AddActuator("Chassis", "Right2Wheel", chassisRight2Wheel);

    chassisRight3Wheel.reset(new CANTalon(kRight3ID));
    lw->AddActuator("Chassis", "Right3Wheel", chassisRight3Wheel);

    chassisShifter.reset(new DoubleSolenoid(kShifterF,kShifterR));
    lw->AddActuator("Chassis", "Shifter", chassisShifter);

    //..........intake.......

    intakeMecanumWheels.reset(new CANTalon(kMecanumWheelsID));
    lw->AddActuator("Intake", "MecanumWheels", intakeMecanumWheels);

    intakeArms.reset(new DoubleSolenoid(kArmsF, kArmsR));
    lw->AddActuator("Intake", "Arms", intakeArms);
    //..........shooter..........

    shooterLeftFlywheel.reset(new CANTalon(kLeftFlywheelID));
    lw->AddActuator("Shooter", "LeftFlywheel", shooterLeftFlywheel);

    shooterRightFlywheel.reset(new CANTalon(kRightFlywheelID));
    lw->AddActuator("Shooter", "RightFlywheel", shooterRightFlywheel);

    shooterRoller.reset(new CANTalon(kRollerID));
    lw->AddActuator("Shooter", "Roller", shooterRoller);

    shooterLifter.reset(new DoubleSolenoid(kLifterF, kLifterR));
    lw->AddActuator("Shooter", "Lifter", shooterLifter);

    //..........arms..........

    armsLeftBrazo.reset(new CANTalon (kLeftBrazo));
    lw->AddActuator("Arms", "LeftBrazo", armsLeftBrazo);

    armsRightBrazo.reset(new CANTalon (kRightBrazo));
    lw->AddActuator("Arms", "RightBrazo", armsRightBrazo);
}
