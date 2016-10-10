// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:

	//..........chassis..........

	static std::shared_ptr<CANTalon> chassisLeft1Wheel;
	static std::shared_ptr<CANTalon> chassisLeft2Wheel;
	static std::shared_ptr<CANTalon> chassisLeft3Wheel;
	static std::shared_ptr<CANTalon> chassisRight1Wheel;
	static std::shared_ptr<CANTalon> chassisRight2Wheel;
	static std::shared_ptr<CANTalon> chassisRight3Wheel;

	static std::shared_ptr<DoubleSolenoid> chassisShifter;
	static std::shared_ptr<DoubleSolenoid> chassisKickstand;

	//..........arms..........

	static std::shared_ptr<CANTalon> armsLeftBrazo;
	static std::shared_ptr<CANTalon> armsRightBrazo;



	//..........chassis..........

	static const int kLeft1ID = 1;
	static const int kLeft2ID = 2;
	static const int kLeft3ID = 3;
	static const int kRight1ID = 4;
	static const int kRight2ID = 5;
	static const int kRight3ID = 6;

	static const int kShifterF = 0;
	static const int kShifterR = 3;
	static const int kKickstandF = 4;
	static const int kKickstandR = 5;

	//..........arms..........

	static const int kArmLeft  = 20;
	static const int kArmRight = 21;


	//.........Buttons.....
	static void init();




};
#endif
