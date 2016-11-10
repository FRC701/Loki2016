#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	std::shared_ptr<Joystick> driver;

//	std::shared_ptr<JoystickButton> dA;
//	std::shared_ptr<JoystickButton> dB;
//	std::shared_ptr<JoystickButton> dX;
//	std::shared_ptr<JoystickButton> dY;
//	std::shared_ptr<JoystickButton> dLB;
//	std::shared_ptr<JoystickButton> dRB;
//	std::shared_ptr<JoystickButton> dL3;
//	std::shared_ptr<JoystickButton> dR3;
//	std::shared_ptr<JoystickButton> dStart;
//	std::shared_ptr<JoystickButton> dBack;
//
//	std::shared_ptr<Joystick> coDriver;
//
//	std::shared_ptr<JoystickButton> coA;
//	std::shared_ptr<JoystickButton> coB;
//	std::shared_ptr<JoystickButton> coX;
//	std::shared_ptr<JoystickButton> coY;
//	std::shared_ptr<JoystickButton> coLB;
//	std::shared_ptr<JoystickButton> coRB;
//	std::shared_ptr<JoystickButton> coL3;
//	std::shared_ptr<JoystickButton> coR3;
//	std::shared_ptr<JoystickButton> coStart;
//	std::shared_ptr<JoystickButton> coBack;
//
//	const int kButtonA_ID = 1;
//	const int kButtonX_ID = 3;
//	const int kButtonB_ID = 2;
//	const int kButtonY_ID = 4;
//	const int kButtonLB_ID = 5;
//	const int kButtonRB_ID = 6;
//	const int kButtonBack_ID = 7;
//	const int kButtonStart_ID = 8;
//	const int kButtonL3_ID = 9;
//	const int kButtonR3_ID = 10;

public:
	OI();
	std::shared_ptr<Joystick> getDriver();
	double getDriverLeftAxis() const;
	double getDriverRightAxis() const;
};

#endif
