#include "TankDrive.h"


TankDrive::TankDrive(): Command() {
    // Use requires() here to declare subsystem dependencies
	Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void TankDrive::Initialize() {
	Robot::chassis->TeleopSetUp();
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {

	Robot::chassis->SetTankDrive(Robot::oi->getDriverLeftAxis(), Robot::oi->getDriverRightAxis());
	//Robot::chassis->SetTankDrive(0.0, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void TankDrive::End() {
	Robot::chassis->SetTankDrive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {
	Robot::chassis->SetTankDrive(0.0, 0.0);
}
