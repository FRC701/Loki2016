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


    right1Wheel->SetInverted(true);

    left2Wheel->SetControlMode(CANTalon::kFollower);
    left2Wheel->Set(RobotMap::kLeft1ID);

    left3Wheel->SetControlMode(CANTalon::kFollower);
    left3Wheel->Set(RobotMap::kLeft1ID);

    right2Wheel->SetControlMode(CANTalon::kFollower);
    right2Wheel->Set(RobotMap::kRight1ID);

    right3Wheel->SetControlMode(CANTalon::kFollower);
    right3Wheel->Set(RobotMap::kRight1ID);

    SetShifter(kLow);
    SetKickstand(kIn);


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
	left1Wheel->Set(left);
	right1Wheel->Set(right);
}

void Chassis::SetShifter(ShifterValue value)
{
	//shifter->Set(static_cast<DoubleSolenoid::Value>(value));

	switch(value){
		case kLow:
			shifter->Set(DoubleSolenoid::kReverse);
			break;
		case kHigh:
			shifter->Set(DoubleSolenoid::kForward);
			break;
	}

}

bool Chassis::IsShifterHigh()
{
	return shifter->Get() == DoubleSolenoid::kForward;
}

void Chassis::SetKickstand(KickstandValue value)
{
	kickstand->Set(static_cast<DoubleSolenoid::Value>(value));
}

bool Chassis::IsKickstandIn()
{
	return kickstand->Get() == DoubleSolenoid::kForward;
}
