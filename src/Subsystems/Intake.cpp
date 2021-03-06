#include "Intake.h"
#include "../RobotMap.h"
#include "../Commands/IntakeOn.h"
#include "../Robot.h"

Intake::Intake() : Subsystem("Intake"),
  mecanumWheels(RobotMap::intakeMecanumWheels),
  arms(RobotMap::intakeArms)
{
  SetArms(kUp);
}

void Intake::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  //SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new IntakeOn(0.0));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Intake::SetIntake(double speed)
{
  mecanumWheels->Set(speed);
}

void Intake::SetArms(ArmsValue value)
{
  arms->Set(static_cast<DoubleSolenoid::Value>(value));
}

bool Intake::IsArmUp() const
{
  return arms->Get() == static_cast<DoubleSolenoid::Value>(kUp);
}
