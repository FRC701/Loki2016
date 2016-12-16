#include "Chassis.h"

#include "../RobotMap.h"
#include "../Commands/TankDrive.h"
#include "CANTalon.h"

Chassis::Chassis()
: Subsystem("Chassis") {
	left1Wheel = RobotMap::chassisLeft1Wheel;
    left2Wheel = RobotMap::chassisLeft2Wheel;
    left3Wheel = RobotMap::chassisLeft3Wheel;
    right1Wheel = RobotMap::chassisRight1Wheel;
    right2Wheel = RobotMap::chassisRight2Wheel;
    right3Wheel = RobotMap::chassisRight3Wheel;

    //InitialSetUp();

    shifter = RobotMap::chassisShifter;
}

void Chassis::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::InitialSetUp() {
	SetShifter(kHigh);

	left1Wheel->SetInverted(false);
	left1Wheel->ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);

	right1Wheel->SetInverted(true);
	right1Wheel->ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);

	left2Wheel->SetControlMode(CANTalon::kFollower);
	left2Wheel->Set(RobotMap::kLeft1ID);

	left3Wheel->SetControlMode(CANTalon::kFollower);
	left3Wheel->Set(RobotMap::kLeft1ID);

	right1Wheel->SelectProfileSlot(VOL_PROFILE);
	right1Wheel->SetControlMode(CANTalon::kPercentVbus);

	right2Wheel->SetControlMode(CANTalon::kFollower);
	right2Wheel->Set(RobotMap::kRight1ID);

	right3Wheel->SetControlMode(CANTalon::kFollower);
	right3Wheel->Set(RobotMap::kRight1ID);

	SetMode(Chassis::kCoast);
}

//...........................SetUps.................................

void Chassis::AutoSetUp(){
	//TODO Change auto-talon setup mode

}

void Chassis::TeleopSetUp() {
	//TODO Implement
}

//.................................................Talon Commands.................................................
void Chassis::SetTankDrive(double left, double right){
	if(!isTankDrive) {
		left1Wheel->SelectProfileSlot(VOL_PROFILE);
		left1Wheel->SetControlMode(CANTalon::kPercentVbus);

		right1Wheel->SelectProfileSlot(VOL_PROFILE);
		right1Wheel->SetControlMode(CANTalon::kPercentVbus);

		isTankDrive = true;
	}

	left1Wheel->Set(left);
	right1Wheel->Set(right);
}

void Chassis::setPosition(double leftTarget, double rightTarget) {
	if(isTankDrive){
		left1Wheel->SelectProfileSlot(POS_PROFILE);
		left1Wheel->SetControlMode(CANTalon::kPosition);

		right1Wheel->SelectProfileSlot(POS_PROFILE);
		right1Wheel->SetControlMode(CANTalon::kPosition);

		isTankDrive = false;
	}

	left1Wheel->Set(leftTarget);
	right1Wheel->Set(rightTarget);
}

void Chassis::setLeftPID(double p, double i, double d){
	left1Wheel->SetPID(p, i, d);
}

void Chassis::setRightPID(double p, double i, double d){
	right1Wheel->SetPID(p, i, d);
}

void Chassis::enablePID() {
	left1Wheel->EnableControl();
	right1Wheel->EnableControl();
}

void Chassis::disablePID() {
	left1Wheel->Disable();
	right1Wheel->Disable();
}

void Chassis::SetMode(TalonMode mode){
	left1Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
	left2Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
	left3Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));

	right1Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
	right2Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
	right3Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
}

bool Chassis::IsBrakeOn(){
	return right1Wheel->GetBrakeEnableDuringNeutral() == static_cast<CANTalon::NeutralMode>(kBrake);
}

//........................................Solenoid Commands.............................................

void Chassis::SetShifter(ShifterValue value){
	shifter->Set(static_cast<DoubleSolenoid::Value>(value));

}

bool Chassis::IsShifterHigh(){
	return shifter->Get() == static_cast<DoubleSolenoid::Value>(kHigh);
}
