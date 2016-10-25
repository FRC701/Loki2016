#ifndef ShooterIntake_H
#define ShooterIntake_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShooterIntake: public Command
{
public:
	ShooterIntake(double shooterSpeed, double rollerSpeed);
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
