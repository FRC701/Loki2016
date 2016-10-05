#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem
{
private:
	std::shared_ptr<CANTalon> leftFlywheel;
	std::shared_ptr<CANTalon> rightFlywheel;
	std::shared_ptr<CANTalon> roller;

	std::shared_ptr<DoubleSolenoid> lifter;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Shooter();
	void InitDefaultCommand();

	enum LifterValue {kUp = DoubleSolenoid::kForward, kDown = DoubleSolenoid::kReverse };

	void SetLifter(LifterValue value);

	bool IsLifterUp() const;

	void SetShooter(double speed);

	void SetRoller(double speed);




};

#endif
