// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/TankDrive.h"
#include "Commands/ToggleKickstand.h"
#include "Commands/ToggleShifter.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driverStick.reset(new Joystick(0));
    
    dA.reset(new JoystickButton(driverStick.get(), 1));
    dA->WhenReleased(new ToggleKickstand());

    dB.reset(new JoystickButton(driverStick.get(), 2));
    dB->WhenReleased(new ToggleShifter());

    // SmartDashboard Buttons
    SmartDashboard::PutData("TankDrive", new TankDrive());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::GetDriverStick() {
   return driverStick;
}

std::shared_ptr<Joystick> OI::GetDriverWheel() {
   return driverWheel;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

double OI::GetDriverStickAxis() const {
	return this->driverStick->GetRawAxis(1);
}

double OI::GetDriverWheelAxis() const {
	return driverWheel->GetRawAxis(5);
}
