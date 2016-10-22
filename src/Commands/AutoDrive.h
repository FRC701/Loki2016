#ifndef AutoDrive_H
#define AutoDrive_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoDrive: public Command
{
public:
  enum Distance {
    DoNothing = 0,
    Cross,
    Shoot,
    LowBar,
    Reach,
    Cheval_Cross
  };
  AutoDrive(Distance distance);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
private:
  double speedLeft = Robot::chassis->GetSpeedLeft();
  double speedRight = Robot::chassis->GetSpeedRight();

  double encPositionLeft = Robot::chassis->GetEncPositionLeft();
  double encPositionRight = Robot::chassis->GetEncPositionRight();

  double positionLeft = Robot::chassis->GetPositionLeft();
  double positionRight = Robot::chassis->GetPositionRight();

  Distance mdistance;
  int mposition;
  int counter;
  int tolerance;
};

#endif
