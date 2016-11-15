#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

class RobotMap {
public:

//..........Talons and Solenoids..........

	//..........chassis..........

	static std::shared_ptr<CANTalon> chassisLeft1Wheel;
	static std::shared_ptr<CANTalon> chassisLeft2Wheel;
	static std::shared_ptr<CANTalon> chassisLeft3Wheel;
	static std::shared_ptr<CANTalon> chassisRight1Wheel;
	static std::shared_ptr<CANTalon> chassisRight2Wheel;
	static std::shared_ptr<CANTalon> chassisRight3Wheel;

	static std::shared_ptr<DoubleSolenoid> chassisShifter;
	static std::shared_ptr<DoubleSolenoid> chassisKickstand;


	//...........intake........

	static std::shared_ptr<CANTalon> intakeMecanumWheels;

	static std::shared_ptr<DoubleSolenoid> intakeArms;

	//..........shooter..........

	static std::shared_ptr<CANTalon> shooterLeftFlywheel;
	static std::shared_ptr<CANTalon> shooterRightFlywheel;
	static std::shared_ptr<CANTalon> shooterRoller;

	static std::shared_ptr<DoubleSolenoid> shooterLifter;

//..........IDs..........

	//..........chassis..........

	static const int kLeft1ID = 1;
	static const int kLeft2ID = 2;
	static const int kLeft3ID = 3;
	static const int kRight1ID = 4;
	static const int kRight2ID = 5;
	static const int kRight3ID = 6;

	static const int kShifterF = 0;
	static const int kShifterR = 3;

	//...........intake........

	static const int kMecanumWheelsID = 8;

	static const int kArmsF = 4;
	static const int kArmsR = 6;

	//..........shooter..........

	static const int kLeftFlywheelID = 11;
	static const int kRightFlywheelID = 12;
	static const int kRollerID = 13;
	static const int kLifterF = 1;
	static const int kLifterR = 2;


	static void init();




};
#endif
