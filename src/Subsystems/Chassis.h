#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem {
private:
  // It's desirable that everything possible is private except
  // for methods that implement subsystem capabilities
  std::shared_ptr<CANTalon> left1Wheel;
  std::shared_ptr<CANTalon> left2Wheel;
  std::shared_ptr<CANTalon> left3Wheel;
  std::shared_ptr<CANTalon> right1Wheel;
  std::shared_ptr<CANTalon> right2Wheel;
  std::shared_ptr<CANTalon> right3Wheel;

  std::shared_ptr<DoubleSolenoid> shifter;
  std::shared_ptr<DoubleSolenoid> kickstand;

  double kPLeft;
  double kPRight;

  double kILeft;
  double kIRight;

  double kDLeft;
  double kDRight;

public:
  Chassis();
  void InitDefaultCommand();

  enum TalonMode {kBrake = CANTalon::kNeutralMode_Brake, kCoast = CANTalon::kNeutralMode_Coast};
  enum ShifterValue {kHigh = DoubleSolenoid::kReverse, kLow = DoubleSolenoid::kForward };

  // Drive the robot left and right
  void SetTankDrive(double left, double right);

  void SetShifter(ShifterValue value);

  bool IsShifterHigh() const;

  void SetMode(TalonMode mode);

  bool IsBrakeOn() const;

  void AutoSetUp();

  double GetSpeedLeft();

  double GetPositionLeft();

  double GetEncPositionLeft();

  void GeneralSetUp();

  double GetSpeedRight();

  double GetPositionRight();

  double GetEncPositionRight();


};

#endif
