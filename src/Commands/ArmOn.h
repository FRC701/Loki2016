#ifndef ArmOn_H
#define ArmOn_H

#include "../Robot.h"
#include "WPILib.h"

class ArmOn: public Command
{
public:
	ArmOn(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mspeed;
};

#endif
