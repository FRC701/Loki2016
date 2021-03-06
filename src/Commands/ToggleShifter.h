#ifndef ToggleShifter_H
#define ToggleShifter_H

#include "Commands/Command.h"
#include "../Robot.h"

class ToggleShifter: public Command
{
public:
	ToggleShifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
