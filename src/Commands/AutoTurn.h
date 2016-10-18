#ifndef AutoTurn_H
#define AutoTurn_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoTurn: public Command
{
public:
	enum Direction {
			turnRight = 0,
			turnLeft
		};
	AutoTurn(Direction direction, int position);
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

	Direction mdirection;
	int mposition;
	int tolerance;
};

#endif
