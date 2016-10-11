#ifndef ArmLevel_H
#define ArmLevel_H

#include "../Robot.h"
#include "WPILib.h"

class ArmLevel: public Command
{
public:
		enum ArmLevelPosition
		{
			Intake = 0,
			Portculis,
			Scale,
			LowGoal,
			Moat,
			Cheval
		};
	ArmLevel(ArmLevelPosition position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
		ArmLevelPosition mPosition;
		int count;
};

#endif
