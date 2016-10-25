#ifndef ToggleBrake_H
#define ToggleBrake_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ToggleBrake: public Command
{
public:
	ToggleBrake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
