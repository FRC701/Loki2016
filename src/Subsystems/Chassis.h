#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

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

	double kPLeft = 0;
	double kPRight = 0;

	double kILeft = 0;
	double kIRight = 0;

	double kDLeft = 0;
	double kDRight = 0;

public:
	Chassis();
	void InitDefaultCommand();

	enum TalonMode {kBrake = CANTalon::kNeutralMode_Brake, kCoast = CANTalon::kNeutralMode_Coast};
	enum ShifterValue {kHigh = DoubleSolenoid::kReverse, kLow = DoubleSolenoid::kForward };

	void AutoSetUp();
	void GeneralSetUp();

	//...................Talons..................
	// Drive the robot left and right
	void SetTankDrive(double left, double right);
	void SetMode(TalonMode mode);
	bool IsBrakeOn();

	double GetSpeedLeft();
	double GetPositionLeft();
	double GetEncPositionLeft();

	double GetSpeedRight();
	double GetPositionRight();
	double GetEncPositionRight();

	//..................Solenoids.................
	void SetShifter(ShifterValue value);
	bool IsShifterHigh();

};

#endif
