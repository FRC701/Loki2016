#ifndef AutoDrive_H
#define AutoDrive_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoDrive: public Command
{
public:
	enum Distance {
		DoNothing = 0,
		Cross,
		Shoot,
		LowBar,
		Reach,
		Cheval_Cross
	};
	AutoDrive(Distance distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double speedLeft = Robot::chassis->GetSpeed("left");
	double speedRight = Robot::chassis->GetSpeed("right");
	double encPositionLeft = Robot::chassis->GetEncPosition("left");
	double encPositionRight = Robot::chassis->GetEncPosition("right");
	double positionLeft = Robot::chassis->GetPosition("left");
	double positionRight = Robot::chassis->GetPosition("right");

	Distance mdistance;
	int mposition;
	int counter;
	int tolerance;
};

#endif
