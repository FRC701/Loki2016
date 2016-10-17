#include "Shooter.h"
#include "../RobotMap.h"
#include "../Commands/ShooterControl.h"

Shooter::Shooter() :
  Subsystem("Shooter"),
  leftFlywheel(RobotMap::shooterLeftFlywheel),
  rightFlywheel(RobotMap::shooterRightFlywheel),
  roller(RobotMap::shooterRoller),
  lifter(RobotMap::shooterLifter)
{
  rightFlywheel->SetInverted(true);

  rightFlywheel->SetControlMode(CANTalon::kFollower);
  rightFlywheel->Set(RobotMap::kLeftFlywheelID);

  lifter->Set(DoubleSolenoid::kOff);

}

void Shooter::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterControl(0.0, 0.0));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.



void Shooter::SetLifter(LifterValue value)
{
	lifter->Set(static_cast<DoubleSolenoid::Value>(value));
}

bool Shooter::IsLifterUp() const
{
	return lifter->Get() == static_cast<DoubleSolenoid::Value>(kUp);
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

