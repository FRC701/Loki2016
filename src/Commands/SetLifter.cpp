#include "SetLifter.h"

SetLifter::SetLifter(Shooter::LifterValue value)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	mValue = value;

	Requires(Robot::shooter.get());

}

// Called just before this Command runs the first time
void SetLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetLifter::Execute()
{
	mValue == Shooter::kUp ? Robot::shooter->SetLifter(Shooter::kUp) : Robot::shooter->SetLifter(Shooter::kDown);

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
