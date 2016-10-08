#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> horizontalBands;
	std::shared_ptr<CANTalon> verticalBands;

public:
	Intake();

	void SetIntake(double horiSpeed, double vertiSpeed);

	void InitDefaultCommand();
};

#endif
