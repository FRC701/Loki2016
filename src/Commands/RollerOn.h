#ifndef RollerOn_H
#define RollerOn_H

#include "Commands/Command.h"
#include "../Subsystems/Shooter.h"
#include "../Robot.h"

class RollerOn: public Command
{
public:
	RollerOn(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mSpeed;
};

#endif
