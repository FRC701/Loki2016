#include "Intake.h"
#include "../RobotMap.h"
#include "../Commands/IntakeOn.h"
#include "../Commands/DefaultIntake.h"
#include "../Robot.h"
Intake::Intake() : Subsystem("Intake"){

}

void Intake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
