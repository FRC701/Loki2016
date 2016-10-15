#include "ToggleShifter.h"
#include "../Subsystems/Chassis.h"

ToggleShifter::ToggleShifter()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleShifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToggleShifter::Execute()
{
	Robot::chassis->IsShifterHigh() ? Robot::chassis->SetShifter(Chassis::kLow) : Robot::chassis->SetShifter(Chassis::kHigh);
		//Robot::chassis->SetShifter(value);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleShifter::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleShifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleShifter::Interrupted()
{

}
