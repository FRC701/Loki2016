#ifndef SetLifter_H
#define SetLifter_H

#include "Commands/Command.h"
#include "../Subsystems/Shooter.h"
#include "../Robot.h"

class SetLifter: public Command
{
public:
	SetLifter(Shooter::LifterValue lifterValue);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Shooter::LifterValue mLifterValue;
};


#endif
