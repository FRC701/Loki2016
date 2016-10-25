#ifndef ToggleArms_H
#define ToggleArms_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ToggleArms: public Command
{
public:
	ToggleArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
