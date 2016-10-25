#ifndef SetBrake_H
#define SetBrake_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class SetBrake: public Command
{
public:
	SetBrake(Chassis::TalonMode mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Chassis::TalonMode mMode;
};

#endif
