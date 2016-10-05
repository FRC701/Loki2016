#include "ArmDown.h"


ArmDown::ArmDown()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arms.get());
}

// Called just before this Command runs the first time
void ArmDown::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmDown::Execute()
{
 Robot::arms->ArmDown();
}

// Make this return true when this Command no longer needs to run execute()
bool ArmDown::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmDown::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmDown::Interrupted()
{

}
