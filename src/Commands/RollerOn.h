#ifndef RollerOn_H
#define RollerOn_H

#include "Commands/Command.h"

class RollerOn: public Command
{
public:
  RollerOn(double speed);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();

private:
  double mSpeed;
};

#endif
