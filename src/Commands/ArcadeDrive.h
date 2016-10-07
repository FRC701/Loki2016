#ifndef ArcadeDrive_H
#define ArcadeDrive_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ArcadeDrive: public Command
{
public:
	ArcadeDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
