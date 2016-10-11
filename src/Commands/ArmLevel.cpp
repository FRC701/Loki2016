#include "ArmLevel.h"

ArmLevel::ArmLevel(ArmLevelPosition position)
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

	switch(mPosition) {
		case Intake:
			RobotMap::intakeintakeMotor3->SelectProfileSlot(0);
			RobotMap::intakeintakeMotor4->SelectProfileSlot(0);
			RobotMap::intakeintakeMotor3->Set(0.0);
			RobotMap::intakeintakeMotor4->Set(0.0);
			break;
		case Portculis:
			RobotMap::intakeintakeMotor3->SelectProfileSlot(1);
			RobotMap::intakeintakeMotor4->SelectProfileSlot(1);
			RobotMap::intakeintakeMotor3->Set(-0.026);
			RobotMap::intakeintakeMotor4->Set(0.022);
			break;
		case Scale:
			RobotMap::intakeintakeMotor3->SelectProfileSlot(0);
			RobotMap::intakeintakeMotor4->SelectProfileSlot(0);

			RobotMap::intakeintakeMotor3->Set(0.150);
			RobotMap::intakeintakeMotor4->Set(-0.150);
			break;
		case LowGoal:
			RobotMap::intakeintakeMotor3->SelectProfileSlot(0);
			RobotMap::intakeintakeMotor4->SelectProfileSlot(0);

			RobotMap::intakeintakeMotor3->Set(0.151);
			RobotMap::intakeintakeMotor4->Set(-0.153);
			break;
		case Moat:
			RobotMap::intakeintakeMotor3->SelectProfileSlot(0);
			RobotMap::intakeintakeMotor4->SelectProfileSlot(0);

			RobotMap::intakeintakeMotor3->Set(0.08);
			RobotMap::intakeintakeMotor4->Set(-0.08);
			break;
		case Cheval:
			RobotMap::intakeintakeMotor3->SelectProfileSlot(0);
			RobotMap::intakeintakeMotor4->SelectProfileSlot(0);

			RobotMap::intakeintakeMotor3->Set(0.0);
			RobotMap::intakeintakeMotor4->Set(0.0);
				break;
	}
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
