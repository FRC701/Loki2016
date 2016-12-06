#include "Delay.h"

Delay::Delay(double time)
: mTime(time)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Delay::Initialize()
{
  timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void Delay::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Delay::IsFinished()
{
  return timer.HasPeriodPassed(mTime);
}

// Called once after isFinished returns true
void Delay::End()
{
  timer.Stop();
  timer.Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Delay::Interrupted()
{
  timer.Stop();
  timer.Reset();
}
