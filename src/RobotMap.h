#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

class RobotMap {
public:

	static void init();

//.........................Talons...............................
	static std::shared_ptr<CANTalon> chassisLeft1Wheel;
	static std::shared_ptr<CANTalon> chassisLeft2Wheel;
	static std::shared_ptr<CANTalon> chassisLeft3Wheel;
	static std::shared_ptr<CANTalon> chassisRight1Wheel;
	static std::shared_ptr<CANTalon> chassisRight2Wheel;
	static std::shared_ptr<CANTalon> chassisRight3Wheel;

 //.........................Solenoids............................
	static std::shared_ptr<DoubleSolenoid> chassisShifter;
	static std::shared_ptr<DoubleSolenoid> chassisKickstand;

//..............................IDs..............................
	//.........Chassis..........
	static const int kLeft1ID = 1;
	static const int kLeft2ID = 2;
	static const int kLeft3ID = 3;
	static const int kRight1ID = 4;
	static const int kRight2ID = 5;
	static const int kRight3ID = 6;

	//.........Solenoids........
	static const int kShifterF = 0;
	static const int kShifterR = 3;

};
#endif
