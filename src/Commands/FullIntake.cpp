#include "FullIntake.h"
#include "SetArms.h"
#include "IntakeOn.h"
#include "ShooterControl.h"

FullIntake::FullIntake(double speed)
: mSpeed(speed)
{
  AddSequential(new SetArms(Intake::kDown));
  AddParallel(new IntakeOn(mSpeed));
  AddSequential(new ShooterControl(mSpeed, mSpeed));
}
