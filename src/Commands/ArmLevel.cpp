#include "ArmLevel.h"

ArmLevel::ArmLevel(Arms::ArmLevelPosition position)
: mPosition(position),
  count(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ArmLevel::Initialize()
{
	Robot::arms->ArmLevelSetUp();
	count = 0;
}

// Called repeatedly when this Command is scheduled to run
void ArmLevel::Execute()
{
	Robot::arms->SetArmLevel(mPosition);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmLevel::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmLevel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmLevel::Interrupted()
{

}
