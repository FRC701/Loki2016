#include "Cancel.h"
#include "IntakeOn.h"
#include "ShooterControl.h"
#include "RollerOn.h"

Cancel::Cancel()
{
  AddSequential(new IntakeOn(0.0));
  AddParallel(new ShooterControl(0.0));
  AddParallel(new RollerOn(0.0));
}
