#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

class Chassis: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<CANTalon> left1Wheel;
	std::shared_ptr<CANTalon> left2Wheel;
	std::shared_ptr<CANTalon> left3Wheel;
	std::shared_ptr<CANTalon> right1Wheel;
	std::shared_ptr<CANTalon> right2Wheel;
	std::shared_ptr<CANTalon> right3Wheel;

	std::shared_ptr<DoubleSolenoid> shifter;
	std::shared_ptr<DoubleSolenoid> kickstand;

public:
	Chassis();
	void InitDefaultCommand();

	enum KickstandValue {kOut = DoubleSolenoid::kForward, kIn = DoubleSolenoid::kReverse };
	enum ShifterValue {kLow = DoubleSolenoid::kReverse, kHigh = DoubleSolenoid::kForward };

	// Drive the robot left and right
	void SetTankDrive(double left, double right);

	void SetShifter(ShifterValue value);

	bool IsShifterHigh();

};

#endif
