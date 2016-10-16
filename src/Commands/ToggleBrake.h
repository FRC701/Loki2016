#ifndef ToggleBrake_H
#define ToggleBrake_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleBrake: public CommandBase
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
