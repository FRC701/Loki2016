#include "SetArms.h"

SetArms::SetArms(Intake::ArmsValue armsValue)
: mArmsValue(armsValue)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void SetArms::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetArms::Execute()
{
	Robot::intake->SetArms(mArmsValue);
}

// Make this return true when this Command no longer needs to run execute()
bool SetArms::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetArms::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetArms::Interrupted()
{

}
