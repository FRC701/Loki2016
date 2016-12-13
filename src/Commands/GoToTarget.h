#ifndef GoToTarget_H
#define GoToTarget_H

#include "Commands/Command.h"

class GoToTarget: public Command
{

private:
	double mTarget;

public:
	GoToTarget(double target = 0.0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
