#ifndef ToggleLifter_H
#define ToggleLifter_H

#include "Commands/Command.h"

class ToggleLifter: public Command
{
public:
  ToggleLifter();
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
};

#endif
