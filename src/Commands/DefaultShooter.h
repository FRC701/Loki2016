#ifndef DefaultShooter_H
#define DefaultShooter_H

#include "../Robot.h"
#include "WPILib.h"

class DefaultShooter: public Command
{
public:
	DefaultShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
