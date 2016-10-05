#include "ArmOn.h"

ArmOn::ArmOn(double speed)
{
mspeed == speed;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arms.get());
}

// Called just before this Command runs the first time
void ArmOn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmOn::Execute()
{
 Robot::arms->ArmsOn(mspeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmOn::IsFinished()
{

	return false;
}

// Called once after isFinished returns true
void ArmOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmOn::Interrupted()
{

}
