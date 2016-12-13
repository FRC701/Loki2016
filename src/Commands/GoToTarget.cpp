#include "GoToTarget.h"
#include "../Robot.h"

GoToTarget::GoToTarget(double target)
:	mTarget(target)
{
	Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void GoToTarget::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GoToTarget::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool GoToTarget::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GoToTarget::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoToTarget::Interrupted()
{

}
