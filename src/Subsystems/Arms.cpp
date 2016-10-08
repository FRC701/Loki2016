#include "Arms.h"
#include "../RobotMap.h"
#include "../Commands/ArmOn.h"

Arms::Arms() :
		Subsystem("Arms")
{
	 leftBrazo = RobotMap::armsLeftBrazo;
     rightBrazo = RobotMap::armsRightBrazo;

     rightBrazo->SetInverted(true);
}

void Arms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArmOn(0.0));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Arms::ArmsOn(double speed){
	leftBrazo->Set(speed);
	rightBrazo->Set(speed);
}

