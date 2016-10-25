#ifndef LightsOn_H
#define LightsOn_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class LightsOn: public Command
{
public:
	LightsOn(Relay::Value shooterLightValue, Relay::Value featureLightValue);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Relay::Value mShooterLightValue;
	Relay::Value mFeatureLightValue;
};

#endif
