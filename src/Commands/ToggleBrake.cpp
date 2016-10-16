#include "ToggleBrake.h"
#include "../Robot.h"

ToggleBrake::ToggleBrake()
{
  Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleBrake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToggleBrake::Execute()
{
  Chassis::TalonMode mode
    = Robot::chassis->IsBrakeOn() ? Chassis::kCoast : Chassis::kBrake;
  Robot::chassis->SetMode(mode);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleBrake::IsFinished()
{
  return true;
}

// Called once after isFinished returns true
void ToggleBrake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleBrake::Interrupted()
{

}
