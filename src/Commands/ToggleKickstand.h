#ifndef ToggleKickstand_H
#define ToggleKickstand_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ToggleKickstand: public Command
{
public:
	ToggleKickstand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
