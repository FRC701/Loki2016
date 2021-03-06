#include "ToggleShifter.h"
#include "../Robot.h"

ToggleShifter::ToggleShifter()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(Robot::chassis.get());

}

// Called just before this Command runs the first time
void ToggleShifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToggleShifter::Execute()
{
	Chassis::ShifterValue value
			= Robot::chassis->IsShifterHigh() ? Chassis::kLow: Chassis::kHigh;
		Robot::chassis->SetShifter(value);
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
