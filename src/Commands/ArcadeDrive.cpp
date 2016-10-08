#include "ArcadeDrive.h"
#include "../OI.h"
#include "../Subsystems/Chassis.h"

ArcadeDrive::ArcadeDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ArcadeDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArcadeDrive::Execute()
{
		double throttle = Robot::oi->GetDriverStick();
		double leftSpeed = throttle;	double rightSpeed = throttle;
		double wheel = Robot::oi->GetDriverWheel();
		if(wheel > 0)
		{
			leftSpeed = throttle * (1/wheel);	rightSpeed = throttle * (1/wheel);
		}
		else if(wheel < 0)
		{
			leftSpeed = throttle * wheel;	rightSpeed = throttle * wheel;
		}

	Robot::chassis->GetLeftSpeed(); 	Robot::chassis->GetRightSpeed();
	Robot::chassis->SetDrive(leftSpeed, rightSpeed);

	//Robot::chassis->GetLeftSpeed(Robot::oi->GetDriverStick());

//	Robot::chassis->SetArcadeDrive(Robot::oi->GetDriverStick(),
	//								Robot::oi->GetDriverWheel());

}

// Make this return true when this Command no longer needs to run execute()
bool ArcadeDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArcadeDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArcadeDrive::Interrupted()
{

}
