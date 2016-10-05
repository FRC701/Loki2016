#ifndef ArmUp_H
#define ArmUp_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class ArmUp: public Command
{
public:
	ArmUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
