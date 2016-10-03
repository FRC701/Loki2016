#ifndef ArmDown_H
#define ArmDown_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArmDown: public CommandBase
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
