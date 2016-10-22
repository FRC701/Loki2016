#include "IntakeOn.h"

IntakeOn::IntakeOn(double speed)
: mSpeed(speed)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(chassis);
  Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void IntakeOn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeOn::Execute()
{
  Robot::intake->SetIntake(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOn::IsFinished()
{
  // todo: refactor to be a logical return
	if (mSpeed > 0)
		return ! Robot::shooter->IsRollerClosed();
	else if (mSpeed < 0)
		return Robot::shooter->IsRollerClosed();

  return false;
}

// Called once after isFinished returns true
void IntakeOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOn::Interrupted()
{

}
