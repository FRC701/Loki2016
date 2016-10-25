#include "AutoDrive.h"


static
int getPosition(AutoDrive::Distance distance) {
	int position = 0;
	switch (distance) {
	case AutoDrive::Reach:
		position = 12819;
		break;
	case AutoDrive::Cross:
		position = 44867;
		break;
	case AutoDrive::Shoot:
		position = 44867;
		break;
	case AutoDrive::LowBar:
		position = -44867;
		break;
	case AutoDrive::Cheval_Cross:
		position = (44867 - 12819);
		break;
	case AutoDrive::DoNothing:
		break;
	default:
		position = 0;
		break;
	}
	return position;
}

AutoDrive::AutoDrive(Distance distance)
: mdistance(distance),
  mposition(getPosition(distance)),
  counter(0),
  tolerance(10)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoDrive::Initialize()
{
	Robot::chassis->AutoSetUp();
	counter = 0;
	tolerance = 10;
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute()
{
	Robot::chassis->SetTankDrive(mposition, mposition);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished()
{


	if( abs(speedLeft) < 1.0)
		counter++;
	else
		counter = 0;
	if(counter == 10)
		return true;

	if (	(abs(encPositionLeft) > abs(encPositionRight) + 500) ||
			(abs(encPositionRight) > abs(encPositionLeft) + 500)	)
		return true;

	return positionRight <= mposition + tolerance
			&& positionRight >= mposition - tolerance;
}

// Called once after isFinished returns true
void AutoDrive::End()
{
	Robot::chassis->GeneralSetUp();
	Robot::chassis->SetTankDrive(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted()
{
	Robot::chassis->GeneralSetUp();
	Robot::chassis->SetTankDrive(0.0,0.0);

	AutoDrive::End();
}
