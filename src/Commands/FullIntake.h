#ifndef FullIntake_H
#define FullIntake_H

#include "Commands/CommandGroup.h"

class FullIntake: public CommandGroup
{
public:
  FullIntake(double speed);

private:
  double mSpeed;
};

#endif
