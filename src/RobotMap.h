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

private:

//..............................IDs..............................
	//.........Chassis..........
	const int kLeft1ID = 1;
	const int kLeft2ID = 2;
	const int kLeft3ID = 3;
	const int kRight1ID = 4;
	const int kRight2ID = 5;
	const int kRight3ID = 6;

	//.........Solenoids........
	const int kShifterF = 0;
	const int kShifterR = 3;

};
#endif
