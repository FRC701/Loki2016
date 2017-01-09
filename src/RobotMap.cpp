#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


//..........chassis..........

std::shared_ptr<CANTalon> RobotMap::chassisLeft1Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisLeft2Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisLeft3Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight1Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight2Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight3Wheel;

std::shared_ptr<DoubleSolenoid> RobotMap::chassisShifter;
std::shared_ptr<DoubleSolenoid> RobotMap::chassisKickstand;

//.........intake..........

std::shared_ptr<CANTalon> RobotMap::intakeMecanumWheels;
std::shared_ptr<DoubleSolenoid> RobotMap::intakeArms;

//..........shooter..........

std::shared_ptr<CANTalon> RobotMap::shooterLeftFlywheel;
std::shared_ptr<CANTalon> RobotMap::shooterRightFlywheel;
std::shared_ptr<CANTalon> RobotMap::shooterRoller;

std::shared_ptr<DoubleSolenoid> RobotMap::shooterLifter;

//..........lights..........

std::shared_ptr<Relay> RobotMap::lightsFeature;
std::shared_ptr<Relay> RobotMap::lightsShooter;

void RobotMap::init() {

    LiveWindow *lw = LiveWindow::GetInstance();


    //..........chassis..........

    chassisLeft1Wheel.reset(new CANTalon(kLeft1ID));
    lw->AddActuator("Chassis", "Left1Wheel", chassisLeft1Wheel);

    chassisLeft2Wheel.reset(new CANTalon(kLeft2ID));
    lw->AddActuator("Chassis", "Left2Wheel", chassisLeft2Wheel);

    chassisLeft3Wheel.reset(new CANTalon(kLeft3ID));
    lw->AddActuator("Chassis", "Left3Wheel", chassisLeft3Wheel);

    chassisRight1Wheel.reset(new CANTalon(kRight1ID));
    lw->AddActuator("Chassis", "Right1Wheel", chassisRight1Wheel);

    chassisRight2Wheel.reset(new CANTalon(kRight2ID));
    lw->AddActuator("Chassis", "Right2Wheel", chassisRight2Wheel);

    chassisRight3Wheel.reset(new CANTalon(kRight3ID));
    lw->AddActuator("Chassis", "Right3Wheel", chassisRight3Wheel);

    chassisShifter.reset(new DoubleSolenoid(kShifterF,kShifterR));
    lw->AddActuator("Chassis", "Shifter", chassisShifter);

    //..........intake.......

    intakeMecanumWheels.reset(new CANTalon(kMecanumWheelsID));
    lw->AddActuator("Intake", "MecanumWheels", intakeMecanumWheels);

    intakeArms.reset(new DoubleSolenoid(kArmsF, kArmsR));
    lw->AddActuator("Intake", "Arms", intakeArms);

    //..........shooter..........

    shooterLeftFlywheel.reset(new CANTalon(kLeftFlywheelID));
    lw->AddActuator("Shooter", "LeftFlywheel", shooterLeftFlywheel);

    shooterRightFlywheel.reset(new CANTalon(kRightFlywheelID));
    lw->AddActuator("Shooter", "RightFlywheel", shooterRightFlywheel);

    shooterRoller.reset(new CANTalon(kRollerID));
    lw->AddActuator("Shooter", "Roller", shooterRoller);

    shooterLifter.reset(new DoubleSolenoid(kLifterF, kLifterR));
    lw->AddActuator("Shooter", "Lifter", shooterLifter);

    //..........lights..........

    lightsFeature.reset(new Relay(kFeatureLightsID));
    lw->AddActuator("Lights", "Feature", lightsFeature);

    lightsShooter.reset(new Relay(kShooterLightsID));
    lw->AddActuator("Lights", "Shooter", lightsShooter);
}
