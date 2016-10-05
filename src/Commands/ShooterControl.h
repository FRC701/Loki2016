#ifndef ShooterControl_H
#define ShooterControl_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShooterControl: public Command
{
public:
	ShooterControl(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mSpeed;

};

#endif
