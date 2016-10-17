#ifndef ShooterControl_H
#define ShooterControl_H

#include "Commands/Command.h"
#include "../Robot.h"

class ShooterControl: public Command
{
public:
	ShooterControl(double shooterSpeed, double rollerSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mShooterSpeed;
	double mRollerSpeed;

};

#endif
