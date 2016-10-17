#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/TankDrive.h"
#include "Commands/ToggleShifter.h"
#include "Commands/IntakeOn.h"
#include "Commands/ToggleLifter.h"
#include "Commands/PrepShooter.h"
#include "Commands/ToggleArms.h"
#include "Commands/RollerOn.h"
#include "Commands/ToggleBrake.h"
#include "Commands/FullIntake.h"
#include "Commands/Cancel.h"
#include "Commands/PrepShooter.h"
#include "Commands/LowGoalShoot.h"
#include "Commands/ShooterControl.h"

OI::OI() {
  // Process operator interface input here.
  driver.reset(new Joystick(0));

  dA.reset(new JoystickButton(driver.get(), kButtonA_ID));
  dA->WhenPressed(new AutonomousCommand());

  dB.reset(new JoystickButton(driver.get(), kButtonB_ID));
  dB->WhenPressed(new AutonomousCommand());

  dX.reset(new JoystickButton(driver.get(), kButtonX_ID));
  dX->WhenPressed(new AutonomousCommand());

  dY.reset(new JoystickButton(driver.get(), kButtonY_ID));
  dY->WhenPressed(new AutonomousCommand());

  dLB.reset(new JoystickButton(driver.get(), kButtonLB_ID));
  dLB->WhenPressed(new AutonomousCommand());

  dRB.reset(new JoystickButton(driver.get(), kButtonRB_ID));
  dRB->WhenPressed(new RollerOn(1.0));

  dBack.reset(new JoystickButton(driver.get(), kButtonBack_ID));
  dBack->WhenPressed(new AutonomousCommand());

  dStart.reset(new JoystickButton(driver.get(), kButtonStart_ID));
  dStart->WhenPressed(new AutonomousCommand());

  dL3.reset(new JoystickButton(driver.get(), kButtonL3_ID));
  dL3->WhenPressed(new ToggleBrake());

  dR3.reset(new JoystickButton(driver.get(), kButtonR3_ID));
  dR3->WhenPressed(new ToggleShifter());

  coDriver.reset(new Joystick(1));

  coA.reset(new JoystickButton(coDriver.get(), kButtonA_ID));
  coA->WhenPressed(new ToggleLifter());

  coB.reset(new JoystickButton(coDriver.get(), kButtonB_ID));
  coB->WhenPressed(new AutonomousCommand());

  coX.reset(new JoystickButton(coDriver.get(), kButtonX_ID));
  coX->WhenPressed(new FullIntake(-1.0));

  coY.reset(new JoystickButton(coDriver.get(), kButtonY_ID));
  coY->WhenPressed(new PrepShooter(1.0));

  coLB.reset(new JoystickButton(coDriver.get(), kButtonLB_ID));
  coLB->WhenPressed(new ToggleArms());

  coRB.reset(new JoystickButton(coDriver.get(), kButtonRB_ID));
  coRB->WhileHeld(new ShooterControl(0.0,1.0));

  coBack.reset(new JoystickButton(coDriver.get(), kButtonBack_ID));
  coBack->WhileHeld(new ShooterControl(0.0,1.0));

  coStart.reset(new JoystickButton(coDriver.get(), kButtonStart_ID));
  coStart->WhenPressed(new AutonomousCommand());

  coL3.reset(new JoystickButton(coDriver.get(), kButtonL3_ID));
  coL3->WhenPressed(new ToggleBrake());

  coR3.reset(new JoystickButton(coDriver.get(), kButtonR3_ID));
  coR3->WhenPressed(new LowGoalShoot());

  // SmartDashboard Buttons
  SmartDashboard::PutData("TankDrive", new TankDrive());
  SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
  SmartDashboard::PutData("ToggleShifter", new ToggleShifter());
  SmartDashboard::PutData("ToggleLifter", new ToggleLifter());
  SmartDashboard::PutData("ToggleArms", new ToggleArms());

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
