// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	std::shared_ptr<Joystick> driver;

	std::shared_ptr<JoystickButton> dA;
	std::shared_ptr<JoystickButton> dB;
	std::shared_ptr<JoystickButton> dX;
	std::shared_ptr<JoystickButton> dY;
	std::shared_ptr<JoystickButton> dLB;
	std::shared_ptr<JoystickButton> dL3;
	public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<Joystick> getDriver();
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	double getDriverLeftAxis() const;
	double getDriverRightAxis() const;

};

#endif
