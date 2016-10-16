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

	std::shared_ptr<DoubleSolenoid> arms;

public:
	Intake();
	void InitDefaultCommand();

	enum ArmsValue {kUp = DoubleSolenoid::kForward, kDown = DoubleSolenoid::kReverse };

	void SetIntake(double speed);

	bool IsArmUp() const;

	void SetArms(ArmsValue value);


};

#endif
