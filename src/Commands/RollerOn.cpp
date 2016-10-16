#include "RollerOn.h"

RollerOn::RollerOn(double speed)
: mSpeed(speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void RollerOn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RollerOn::Execute()
{
	Robot::shooter->SetRoller(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool RollerOn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RollerOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerOn::Interrupted()
{

}
