#include "FullIntake.h"
#include "SetArms.h"
#include "IntakeOn.h"
#include "ShooterControl.h"
#include "RollerOn.h"

FullIntake::FullIntake(double speed)
: mSpeed(speed)
{
  AddSequential(new SetArms(Intake::kDown));
  AddParallel(new IntakeOn(mSpeed));
  AddParallel(new ShooterControl(mSpeed));
  AddParallel(new RollerOn(mSpeed));
}
