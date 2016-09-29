// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

/**
 *
 *
 * @author ExampleAuthor
 */
class Chassis: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<CANTalon> left1Wheel;
	std::shared_ptr<CANTalon> left2Wheel;
	std::shared_ptr<CANTalon> left3Wheel;
	std::shared_ptr<CANTalon> right1Wheel;
	std::shared_ptr<CANTalon> right2Wheel;
	std::shared_ptr<CANTalon> right3Wheel;

	std::shared_ptr<DoubleSolenoid> shifter;
	std::shared_ptr<DoubleSolenoid> kickstand;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	Chassis();
	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	// Drive the robot left and right
	void SetTankDrive(double left, double right);

	void SetShifter(char gear);

	bool IsShifterHigh();

	void SetKickstand(char position);

	bool IsKickstandIn();

};

#endif
