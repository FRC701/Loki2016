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
	Direction mdirection;
	int mposition;
	int tolerance;
};

#endif
