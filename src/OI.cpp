#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/TankDrive.h"
#include "Commands/ToggleShifter.h"
#include "Commands/IntakeOn.h"
#include "Commands/ToggleLifter.h"
#include "Commands/PrepShooter.h"
#include "Commands/ToggleArms.h"

OI::OI() {
    // Process operator interface input here.
    driver.reset(new Joystick(0));

    dA.reset(new JoystickButton(driver.get(), kButtonA_ID));
    dA->WhenPressed(new PrepShooter(1.0));

    dB.reset(new JoystickButton(driver.get(), kButtonB_ID));
    dB->WhenPressed(new ToggleShifter());

    dX.reset(new JoystickButton(driver.get(), kButtonX_ID));
    dX->WhenPressed(new IntakeOn(1.0));

    dY.reset(new JoystickButton(driver.get(), kButtonY_ID));
    dY->WhenPressed(new IntakeOn(-1.0));

    dLB.reset(new JoystickButton(driver.get(), kButtonLB_ID));
    dLB->WhenPressed(new AutonomousCommand());

    dRB.reset(new JoystickButton(driver.get(), kButtonRB_ID));
    dRB->WhenPressed(new AutonomousCommand());

    dBack.reset(new JoystickButton(driver.get(), kButtonBack_ID));
    dBack->WhenPressed(new AutonomousCommand());

    dStart.reset(new JoystickButton(driver.get(), kButtonStart_ID));
    dStart->WhenPressed(new AutonomousCommand());

    dL3.reset(new JoystickButton(driver.get(), kButtonL3_ID));
    dL3->WhenPressed(new AutonomousCommand());

    dR3.reset(new JoystickButton(driver.get(), kButtonR3_ID));
    dR3->WhenPressed(new AutonomousCommand());


    // SmartDashboard Buttons
    SmartDashboard::PutData("TankDrive", new TankDrive());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    SmartDashboard::PutData("ToggleShifter", new ToggleShifter());
    SmartDashboard::PutData("ToggleLifter", new ToggleLifter());
    SmartDashboard::PutData("ToggleArms", new ToggleArms());

}

std::shared_ptr<Joystick> OI::getDriver() {
   return driver;
}

double OI::getDriverLeftAxis() const {
	return driver->GetRawAxis(1);
}

double OI::getDriverRightAxis() const {
	return driver->GetRawAxis(5);
}
