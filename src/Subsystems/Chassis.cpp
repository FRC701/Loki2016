#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"
#include <CANTalon.h>

Chassis::Chassis() : Subsystem("Chassis"),
  left1Wheel(RobotMap::chassisLeft1Wheel),
  left2Wheel(RobotMap::chassisLeft2Wheel),
  left3Wheel(RobotMap::chassisLeft3Wheel),
  right1Wheel(RobotMap::chassisRight1Wheel),
  right2Wheel(RobotMap::chassisRight2Wheel),
  right3Wheel(RobotMap::chassisRight3Wheel),
  shifter(RobotMap::chassisShifter),
  kickstand(RobotMap::chassisKickstand)
{
    right1Wheel->SetInverted(true);

    left2Wheel->SetControlMode(CANTalon::kFollower);
    left2Wheel->Set(RobotMap::kLeft1ID);

    left3Wheel->SetControlMode(CANTalon::kFollower);
    left3Wheel->Set(RobotMap::kLeft1ID);

    right2Wheel->SetControlMode(CANTalon::kFollower);
    right2Wheel->Set(RobotMap::kRight1ID);

    right3Wheel->SetControlMode(CANTalon::kFollower);
    right3Wheel->Set(RobotMap::kRight1ID);

    SetShifter(kLow);
}

void Chassis::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new TankDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::SetTankDrive(double left, double right)
{
  left1Wheel->Set(left);
  right1Wheel->Set(right);
}

void Chassis::SetShifter(ShifterValue value)
{
  shifter->Set(static_cast<DoubleSolenoid::Value>(value));

}

bool Chassis::IsShifterHigh() const
{
  return shifter->Get() == static_cast<DoubleSolenoid::Value>(kHigh);
}

void Chassis::SetMode(TalonMode mode)
{
  left1Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
  left2Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
  left3Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
  right1Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
  right2Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
  right3Wheel->ConfigNeutralMode(static_cast<CANTalon::NeutralMode>(mode));
}

bool Chassis::IsBrakeOn() const
{
  return right1Wheel->GetBrakeEnableDuringNeutral() == static_cast<CANTalon::NeutralMode>(kBrake);
}
