#include "Chassis.h"

#include "../RobotMap.h"
#include "../Commands/TankDrive.h" //swoosh

Chassis::Chassis() : Subsystem("Chassis") {

	left1Wheel = RobotMap::chassisLeft1Wheel;
    left2Wheel = RobotMap::chassisLeft2Wheel;
    left3Wheel = RobotMap::chassisLeft3Wheel;
    right1Wheel = RobotMap::chassisRight1Wheel;
    right2Wheel = RobotMap::chassisRight2Wheel;
    right3Wheel = RobotMap::chassisRight3Wheel;

    shifter = RobotMap::chassisShifter;
    kickstand = RobotMap::chassisKickstand;

    GeneralSetUp();
}

void Chassis::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::AutoSetUp()
{
	//TODO Change auto-talon setup mode

	left1Wheel->SetControlMode(CANTalon::kPosition);
	left1Wheel->SetEncPosition(0.0);
	left1Wheel->SelectProfileSlot(0.0);
	left1Wheel->SetPID(kPLeft, kILeft, kDLeft);


	right1Wheel->SetControlMode(CANTalon::kPosition);
	right1Wheel->SetEncPosition(0.0);
	right1Wheel->SelectProfileSlot(0.0);
	right1Wheel->SetPID(kPRight, kIRight, kDRight);

}

void Chassis::GeneralSetUp()
{
	//TODO How general are we making this? Should we have a general for talon settings, then general of robot setup? Look at tank drive t_o_d_o

	left1Wheel->SetControlMode(CANTalon::kPercentVbus);
	right1Wheel->SetControlMode(CANTalon::kPercentVbus);

	right1Wheel->SetInverted(true);

	left2Wheel->SetControlMode(CANTalon::kFollower);
	left2Wheel->Set(RobotMap::kLeft1ID);

	left3Wheel->SetControlMode(CANTalon::kFollower);
	left3Wheel->Set(RobotMap::kLeft1ID);

	right2Wheel->SetControlMode(CANTalon::kFollower);
	right2Wheel->Set(RobotMap::kRight1ID);

	right3Wheel->SetControlMode(CANTalon::kFollower);
	right3Wheel->Set(RobotMap::kRight1ID);

	SetShifter(kHigh);

	SetMode(Chassis::kCoast);
}

//.................................................Talon Commands.................................................
void Chassis::SetTankDrive(double left, double right)
{
	left1Wheel->Set(left);
	right1Wheel->Set(right);
}

void Chassis::SetMode(TalonMode mode)
{
	left1Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
	left2Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
	left3Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
	right1Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
	right2Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
	right3Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
}

bool Chassis::IsBrakeOn()
{
	return right1Wheel->GetBrakeEnableDuringNeutral() == static_cast<CANTalon::NeutralMode>(kBrake);
}

double Chassis::GetSpeedLeft()
{
	return left1Wheel->GetSpeed();
}

double Chassis::GetPositionLeft()
{
	return left1Wheel->GetPosition();
}

double Chassis::GetEncPositionLeft()
{
	return left1Wheel->GetEncPosition();
}

double Chassis::GetSpeedRight()
{
	return right1Wheel->GetSpeed();
}

double Chassis::GetPositionRight()
{
	return right1Wheel->GetPosition();
}

double Chassis::GetEncPositionRight()
{
	return right1Wheel->GetEncPosition();
}

//........................................Solenoid Commands.............................................

void Chassis::SetShifter(ShifterValue value)
{
	shifter->Set(static_cast<DoubleSolenoid::Value>(value));

}

bool Chassis::IsShifterHigh()
{
	return shifter->Get() == static_cast<DoubleSolenoid::Value>(kHigh);
}
