#include "IntakeOn.h"

IntakeOn::IntakeOn(double Speed)
{
	mSpeed = Speed;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void IntakeOn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeOn::Execute()
{
	Robot::intake->SetIntake(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOn::Interrupted()
{

}
