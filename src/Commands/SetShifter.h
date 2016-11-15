#ifndef SetShifter_H
#define SetShifter_H

#include "Commands/Command.h"
#include "../Subsystems/Chassis.h"
#include "../Robot.h"

class SetShifter: public Command
{
public:
	SetShifter(Chassis::ShifterValue shifterValue);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Chassis::ShifterValue mShifterValue;
};

#endif
