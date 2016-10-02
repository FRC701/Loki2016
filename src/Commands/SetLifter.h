#ifndef SetLifter_H
#define SetLifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SetLifter: public Command
{
public:
	SetLifter(Shooter::LifterValue);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
