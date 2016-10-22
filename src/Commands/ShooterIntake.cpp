#include "ShooterIntake.h"

ShooterIntake::ShooterIntake(double shooterSpeed, double rollerSpeed)
: mShooterSpeed(shooterSpeed), mRollerSpeed(rollerSpeed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void ShooterIntake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterIntake::Execute()
{
	Robot::shooter->SetRoller(mRollerSpeed);
	Robot::shooter->SetShooter(mShooterSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterIntake::IsFinished()
{
	if(mShooterSpeed > 0)
		return Robot::shooter->IsRollerClosed();
	else if(mShooterSpeed < 0)
		return ! Robot::shooter->IsRollerClosed();

	return false;
}

// Called once after isFinished returns true
void ShooterIntake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterIntake::Interrupted()
{

}
