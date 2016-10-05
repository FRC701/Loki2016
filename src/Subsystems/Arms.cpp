#include "Arms.h"
#include "../RobotMap.h"

Arms::Arms() :
		Subsystem("ExampleSubsystem")
{
	 armleft = RobotMap::armLeft;
     armright = RobotMap::armRight;
     armright->SetInverted(true);


}

void Arms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Arms::ArmsOn(double speed){

	armleft->Set(speed);
	armright->Set(speed);
}

