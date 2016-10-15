#include "SetLifter.h"
#include "../Subsystems/Shooter.h"

SetLifter::SetLifter(Shooter::LifterValue lifterValue)
: mLifterValue(lifterValue)
{

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetLifter::Execute()
{
	Robot::shooter->SetLifter(mLifterValue);
}

// Make this return true when this Command no longer needs to run execute()
bool SetLifter::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLifter::Interrupted()
{

}
