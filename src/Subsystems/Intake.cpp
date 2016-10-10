#include "Intake.h"
#include "../RobotMap.h"
#include "../Commands/IntakeOn.h"
#include "../Robot.h"
Intake::Intake() : Subsystem("Intake"){

horizontalBands = RobotMap::intakeHorizontalBands;
verticalBands = RobotMap::intakeVerticalBands;

}

void Intake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new IntakeOn(0.0,0.0));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Intake::SetIntake(double horiSpeed, double vertiSpeed)
{
	Robot::intake->horizontalBands->Set(horiSpeed);
	Robot::intake->verticalBands->Set(vertiSpeed);
}
