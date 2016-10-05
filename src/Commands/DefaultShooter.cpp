#include "DefaultShooter.h"

DefaultShooter::DefaultShooter()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void DefaultShooter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DefaultShooter::Execute()
{
	Robot::shooter->SetShooter(0.0);
	Robot::shooter->SetRoller(0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool DefaultShooter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DefaultShooter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefaultShooter::Interrupted()
{

}
