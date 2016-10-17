#include "AutoTurn.h"

static int getDirection(AutoTurn::Direction direction) {
	int posdirection = 0;

	switch (direction) {
	case AutoTurn::turnLeft:
		posdirection = -1;
		break;
	case AutoTurn::turnRight:
		posdirection = 1;
		break;
	}

	return posdirection;
}

AutoTurn::AutoTurn(Direction direction, int position)
: mdirection(direction),
  mposition(position),
  tolerance(10)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());

}

// Called just before this Command runs the first time
void AutoTurn::Initialize()
{
	Robot::chassis->AutoSetUp();
	tolerance = 10;

}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute()
{
	mposition *= getDirection(mdirection);
	Robot::chassis->SetTankDrive(mposition, mposition);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished()
{
	return Chassis::positionRight <= mposition + tolerance
				&& Chassis::positionRight >= mposition - tolerance;

	// -5 -10 => -5 <= -10 + 10 <= 0
	// -5 -10 => -5 >= -10 - 10 >= -20

	// 5 10 => 5 <= 10 + 10 <= 20
	// 5 10 => 5 >= 10 - 10 >= 0

}

// Called once after isFinished returns true
void AutoTurn::End()
{
	Robot::chassis->GeneralSetUp();
	Robot::chassis->SetTankDrive(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted()
{
	AutoTurn::End();

}
