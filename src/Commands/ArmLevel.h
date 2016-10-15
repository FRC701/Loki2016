#ifndef ArmLevel_H
#define ArmLevel_H

#include "../Robot.h"
#include "WPILib.h"

class ArmLevel: public Command
{
public:
	ArmLevel(Arms::ArmLevelPosition position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
		Arms::ArmLevelPosition mPosition;
		int count;
};

#endif
