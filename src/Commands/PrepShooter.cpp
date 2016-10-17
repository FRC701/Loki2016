#include "PrepShooter.h"
#include "SetLifter.h"
#include "ShooterControl.h"
#include "SetArms.h"

PrepShooter::PrepShooter(double speed)
: mSpeed(speed)
{
  AddSequential(new SetArms(Intake::kDown));
  AddParallel(new SetLifter(Shooter::kUp));
  AddParallel(new ShooterControl(mSpeed, 0.0));
}
