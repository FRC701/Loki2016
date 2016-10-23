#include "AutoStealTankDrive.h"

AutoStealTankDrive::AutoStealTankDrive(double leftSpeed, double rightSpeed)
: mLeftSpeed(leftSpeed), mRightSpeed(rightSpeed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoStealTankDrive::Initialize()
{
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoStealTankDrive::Execute()
{
	if( ! Robot::shooter->IsRollerClosed())
	{
		Robot::chassis->SetTankDrive(mLeftSpeed,mRightSpeed);
		forwardCount++;
	}

	else if (Robot::shooter->IsRollerClosed())
	{
		reverseCount++;
		Robot::chassis->SetTankDrive(-mLeftSpeed,-mRightSpeed);
	}


	if (reverseCount == forwardCount)
		equal = 1;
	else
		equal = 0;


}

// Make this return true when this Command no longer needs to run execute()
bool AutoStealTankDrive::IsFinished()
{
	return equal || timer.HasPeriodPassed(0.25);
}

// Called once after isFinished returns true
void AutoStealTankDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoStealTankDrive::Interrupted()
{

}
