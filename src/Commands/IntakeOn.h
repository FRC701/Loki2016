#ifndef IntakeOn_H
#define IntakeOn_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class IntakeOn: public Command
{
public:
	IntakeOn(double horizontalSpeed, double verticalSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mHorizontalSpeed, mVerticalSpeed;
};

#endif
