#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/TankDrive.h"
#include "Commands/GoToTarget.h"


OI::OI() {
    // Process operator interface input here.
	driver.reset(new Joystick(0));

	SmartDashboard::PutData("Go to Target", new GoToTarget(14));

}

std::shared_ptr<Joystick> OI::getDriver() {
   return driver;
}

double OI::getDriverLeftAxis() const {		//TODO Change name to better fit returning data, i.e. Left-Y-Axis
	return this->driver->GetRawAxis(1);
}

double OI::getDriverRightAxis() const {
	return driver->GetRawAxis(5);
}
