#include "Cancel.h"
#include "IntakeOn.h"
#include "ShooterControl.h"

Cancel::Cancel()
{
  AddParallel(new IntakeOn(0.0));
  AddSequential(new ShooterControl(0.0, 0.0));
}
