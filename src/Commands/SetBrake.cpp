#include "SetBrake.h"
#include "../Robot.h"

SetBrake::SetBrake(Chassis::TalonMode mode)
: mMode(mode)
{
  // Use Requires() here to declare subsystem dependencies
  // eg.
  Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void SetBrake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetBrake::Execute()
{
  Robot::chassis->SetMode(mMode);
}

// Make this return true when this Command no longer needs to run execute()
bool SetBrake::IsFinished()
{
  return false;
}

// Called once after isFinished returns true
void SetBrake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetBrake::Interrupted()
{

}
