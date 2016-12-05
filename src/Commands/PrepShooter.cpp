#include "PrepShooter.h"
#include "SetLifter.h"
#include "ShooterControl.h"
#include "SetArms.h"

// todo: remove mSpeed
PrepShooter::PrepShooter(double speed)
: mSpeed(speed)
{
  AddSequential(new SetArms(Intake::kDown));
  AddSequential(new SetLifter(Shooter::kUp));
  AddSequential(new ShooterControl(speed, 0.0));
}
