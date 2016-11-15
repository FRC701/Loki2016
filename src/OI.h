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
	std::shared_ptr<JoystickButton> dRB;
	std::shared_ptr<JoystickButton> dL3;
	std::shared_ptr<JoystickButton> dR3;
	std::shared_ptr<JoystickButton> dStart;
	std::shared_ptr<JoystickButton> dBack;


	public:
	OI();

	std::shared_ptr<Joystick> getDriver();

	double getDriverLeftAxis() const;
	double getDriverRightAxis() const;

	static const int kButtonA_ID = 1;
	static const int kButtonB_ID = 2;
	static const int kButtonX_ID = 3;
	static const int kButtonY_ID = 4;
	static const int kButtonLB_ID = 5;
	static const int kButtonRB_ID = 6;
	static const int kButtonBack_ID = 7;
	static const int kButtonStart_ID = 8;
	static const int kButtonL3_ID = 9;
	static const int kButtonR3_ID = 10;
};

#endif
