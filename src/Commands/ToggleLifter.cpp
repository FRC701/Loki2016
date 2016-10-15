#include "ToggleLifter.h"
#include "../Subsystems/Shooter.h"

ToggleLifter::ToggleLifter()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToggleLifter::Execute()
{
	Shooter::LifterValue value
		= Robot::shooter->IsLifterUp() ? Shooter::kDown : Shooter::kUp;

	Robot::shooter->SetLifter(value);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleLifter::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleLifter::Interrupted()
{

}
