#ifndef ShooterControl_H
#define ShooterControl_H

#include "Commands/Command.h"
#include "../Robot.h"

class ShooterControl: public Command
{
public:
	ShooterControl(double flyWheelSpeed, double rollerSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mFlyWheelSpeed;
	double mRollerSpeed;

};

#endif
