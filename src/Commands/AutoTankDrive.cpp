#include "AutoTankDrive.h"

AutoTankDrive::AutoTankDrive(double time, double leftSpeed, double rightSpeed)
: mTime(time), mLeftSpeed(leftSpeed), mRightSpeed(rightSpeed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoTankDrive::Initialize()
{
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoTankDrive::Execute()
{
	Robot::chassis->SetTankDrive(-mLeftSpeed, -mRightSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTankDrive::IsFinished()
{
	return timer.HasPeriodPassed(mTime);
}

// Called once after isFinished returns true
void AutoTankDrive::End()
{
	timer.Stop();
	timer.Reset();
	Robot::chassis->SetTankDrive(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTankDrive::Interrupted()
{
	timer.Stop();
	timer.Reset();
	Robot::chassis->SetTankDrive(0.0,0.0);
}
