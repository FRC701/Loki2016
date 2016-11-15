#include "ShooterControl.h"

ShooterControl::ShooterControl(double speed)
: mSpeed(speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void ShooterControl::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterControl::Execute()
{
	Robot::shooter->SetShooter(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterControl::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterControl::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterControl::Interrupted()
{

}
