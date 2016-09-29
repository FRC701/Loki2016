// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Chassis::Chassis() : Subsystem("Chassis") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    left1Wheel = RobotMap::chassisLeft1Wheel;
    left2Wheel = RobotMap::chassisLeft2Wheel;
    left3Wheel = RobotMap::chassisLeft3Wheel;
    right1Wheel = RobotMap::chassisRight1Wheel;
    right2Wheel = RobotMap::chassisRight2Wheel;
    right3Wheel = RobotMap::chassisRight3Wheel;

    shifter = RobotMap::chassisShifter;
    kickstand = RobotMap::chassisKickstand;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    // TODO: Setup follower for left and right based on Left1Wheel and Right1Wheel

    right1Wheel->SetInverted(true);

    left2Wheel->SetControlMode(CANTalon::kFollower);
    //left2Wheel->Set(kLeft1Talon)

    left3Wheel->SetControlMode(CANTalon::kFollower);
    //left3Wheel->Set(kLeft1Talon)

    right2Wheel->SetControlMode(CANTalon::kFollower);
    //right2Wheel->Set(kRight1Talon)

    right3Wheel->SetControlMode(CANTalon::kFollower);
    //right3Wheel->Set(kRight1Talon)


}

void Chassis::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::SetTankDrive(double left, double right)
{
	Robot::chassis->left1Wheel->Set(left);
	Robot::chassis->right1Wheel->Set(right);
}

void Chassis::SetShifter(char gear)
{
	if(gear == 'h')
		Robot::chassis->shifter->Set(DoubleSolenoid::kForward);

	else if(gear == 'l')
		Robot::chassis->shifter->Set(DoubleSolenoid::kReverse);
}

void bool Chassis::IsShifterHigh()
{
	bool status;
	if(Robot::chassis->shifter->Get() == DoubleSolenoid::kForward)
		status = true;
	else if(Robot::chassis->shifter->Get() == DoubleSolenoid::kReverse)
		status = false;

	return status;

}

void Chassis::SetKickstand(char position)
{
	if(position == 'o')
		Robot::chassis->shifter->Set(DoubleSolenoid::kForward);

	else if(position == 'i')
		Robot::chassis->shifter->Set(DoubleSolenoid::kReverse);
}

void bool Chassis::IsKickstandIn()
{
	bool status;
	if(Robot::chassis->kickstand->Get() == DoubleSolenoid::kForward)
		status = false;
	else if(Robot::chassis->kickstand->Get() == DoubleSolenoid::kReverse)
		status = true;

	return status;
}
