#ifndef SetArms_H
#define SetArms_H

#include "Commands/Command.h"
#include "../Subsystems/Intake.h"
#include "../Robot.h"

class SetArms: public Command
{
public:
	SetArms(Intake::ArmsValue armsValue);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Intake::ArmsValue mArmsValue;
};

#endif
