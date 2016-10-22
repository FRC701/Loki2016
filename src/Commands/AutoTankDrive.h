#ifndef AutoTankDrive_H
#define AutoTankDrive_H

#include "Commands/Command.h"
#include "WPILib.h"
#include "../Robot.h"

class AutoTankDrive: public Command
{
public:
  AutoTankDrive(double time, double leftSpeed, double rightSpeed);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();

private:
  double mTime;
  Timer timer;

  double mLeftSpeed;
  double mRightSpeed;
};

#endif
