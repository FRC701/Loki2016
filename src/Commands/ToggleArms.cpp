#include "ToggleArms.h"

ToggleArms::ToggleArms()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void ToggleArms::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToggleArms::Execute()
{
Intake::ArmsValue value
	= Robot::intake->IsArmUp() ? Intake::kDown: Intake::kUp;
Robot::intake->SetArms(value);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleArms::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ToggleArms::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleArms::Interrupted()
{

}
