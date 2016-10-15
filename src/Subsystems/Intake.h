#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<CANTalon> mecanumWheels;

public:
	Intake();

	void SetIntake(double speed);

	void InitDefaultCommand();
};

#endif
