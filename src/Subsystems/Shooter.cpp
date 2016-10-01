#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
		Subsystem("Shooter")
{
	leftFlywheel = RobotMap::shooterLeftFlywheel;
	rightFlywheel = RobotMap::shooterRightFlywheel;
	roller = RobotMap::shooterRoller;

	lifter = RobotMap::shooterLifter;

	rightFlywheel->SetInverted(true);
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DefaultShooter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.



void Shooter::SetLifter(LifterValue value)
{
	lifter->Set(static_cast<DoubleSolenoid::Value>(value));
}

bool Shooter::IsLifterHigh()
{
	return lifter->Get() == DoubleSolenoid::kForward;
}

void Shooter::SetShooter(double speed)
{
	leftFlywheel->Set(speed);
	rightFlywheel->Set(speed);
}

void Shooter::SetRoller(double speed)
{
	roller->Set(speed);
}

