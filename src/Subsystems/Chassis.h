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

	int POS_PROFILE = 0;
	int VOL_PROFILE = 0;

	bool isTankDrive = true;

public:
	Chassis();
	void InitDefaultCommand();

	enum TalonMode {kBrake = CANTalon::kNeutralMode_Brake, kCoast = CANTalon::kNeutralMode_Coast};
	enum ShifterValue {kHigh = DoubleSolenoid::kReverse, kLow = DoubleSolenoid::kForward };

	//.............SetUp..............
	void InitialSetUp();
	void AutoSetUp();
	void TeleopSetUp();

	//.....................Sets................
	void SetMode(TalonMode mode);
	bool IsBrakeOn();

	void SetTankDrive(double left, double right);

	//........Will be removed and implemented in positionSetUp();
	void setLeftPID(double p, double i = 0, double d = 0);
	void setRightPID(double p, double i = 0, double d = 0);

	void setPosition(double leftTarget, double rightTarget);

	void enablePID();
	void disablePID();

	//..................Solenoids.................
	void SetShifter(ShifterValue value);
	bool IsShifterHigh();

};

#endif
