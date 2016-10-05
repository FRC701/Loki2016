#ifndef ArmDown_H
#define ArmDown_H

#include "../Robot.h"
#include "WPILib.h"

class ArmDown: public Command
{
public:
	ArmDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
