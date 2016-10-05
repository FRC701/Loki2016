#include "Arms.h"
#include "../RobotMap.h"

Arms::Arms() :
		Subsystem("ExampleSubsystem")
{
	 armleft = RobotMap::armLeft;
     armright = RobotMap::armRight;
}

void Arms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Arms::ArmsUp(){

	armleft->Set(1.0);
	armright->Set(1.0);
}

void Arms::ArmDown(){

	armleft->Set(-1.0);
	armright->Set(-1.0);
}
