#ifndef Delay_H
#define Delay_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "Time.h"

class Delay: public Command
{
public:
  Delay(double time);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();

private:
  double mTime;
  Timer timer;
};

#endif
