#include "ToggleKickstand.h"

ToggleKickstand::ToggleKickstand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleKickstand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToggleKickstand::Execute()
{
	Chassis::KickstandValue value
		= Robot::chassis->IsKickstandIn() ? Chassis::kOut : Chassis::kIn;
	Robot::chassis->SetKickstand(value);

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleKickstand::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleKickstand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleKickstand::Interrupted()
{

}
