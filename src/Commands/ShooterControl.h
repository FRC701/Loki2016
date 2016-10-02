#ifndef ShooterControl_H
#define ShooterControl_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterControl: public Command
{
public:
	ShooterControl(double mSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double speed;

};

#endif
