#ifndef SetLifter_H
#define SetLifter_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class SetLifter: public Command
{
public:
	SetLifter(Shooter::LifterValue value);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Shooter::LifterValue mValue;
};

#endif
