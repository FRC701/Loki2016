#include "Robot.h"

std::shared_ptr<Chassis> Robot::chassis;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Lights> Robot::lights;

void Robot::RobotInit() {
    RobotMap::init();

    chassis.reset(new Chassis());
    intake.reset(new Intake());
    shooter.reset(new Shooter());
    lights.reset(new Lights());

    // This MUST be here. If the OI creates Commands (which it very likely
    // will), constructing it during the construction of CommandBase (from
    // which commands extend), subsystems are not guaranteed to be
    // yet. Thus, their requires() statements may grab null pointers. Bad
    // news. Don't move it.
    oi.reset(new OI());

    // instantiate the command used for the autonomous period
    autonomousCommand.reset(new AutonomousCommand());
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
    Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
    if (autonomousCommand.get() != nullptr)
        autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
    Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // these lines or comment it out.
    if (autonomousCommand.get() != nullptr)
        autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
  Scheduler::GetInstance()->Run();

  // todo: Simplify this logic
  // todo: Make this a command
  if (Robot::shooter->IsRollerClosed())
    Robot::lights->SetShooterLights(Relay::kForward);
  else
    Robot::lights->SetShooterLights(Relay::kOff);
}

void Robot::TestPeriodic() {
    lw->Run();
}

START_ROBOT_CLASS(Robot);

