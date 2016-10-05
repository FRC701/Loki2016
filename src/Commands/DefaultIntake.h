#ifndef DefaultIntake_H
#define DefaultIntake_H

#include "../Robot.h"

class DefaultIntake: public Command
{
public:
	DefaultIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
