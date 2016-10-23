#ifndef AutoStealTankDrive_H
#define AutoStealTankDrive_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "Time.h"

class AutoStealTankDrive: public Command
{
public:
	AutoStealTankDrive(double leftSpeed, double rightSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mLeftSpeed;
	double mRightSpeed;

	Timer timer;

	int forwardCount = 0;
	int reverseCount = 0;
	bool equal;
};

#endif
