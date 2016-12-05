#include "Cancel.h"
#include "IntakeOn.h"
#include "ShooterControl.h"

Cancel::Cancel()
{
  AddSequential(new IntakeOn(0.0));
  // Todo: Sequential after
  AddParallel(new ShooterControl(0.0, 0.0));
}
