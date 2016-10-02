#ifndef ToggleLifter_H
#define ToggleLifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ToggleLifter: public Command
{
public:
	ToggleLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
