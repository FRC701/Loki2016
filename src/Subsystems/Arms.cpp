#include "Arms.h"
#include "../RobotMap.h"

Arms::Arms() :
		Subsystem("ExampleSubsystem")
{
	 Armleft = RobotMap::armLeft;
     Armright = RobotMap::armRight;
}

void Arms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
