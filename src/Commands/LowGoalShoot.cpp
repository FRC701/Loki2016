#include "LowGoalShoot.h"
#include "SetArms.h"
#include "SetLifter.h"
#include "ShooterControl.h"

LowGoalShoot::LowGoalShoot()
{
  AddSequential(new SetArms(Intake::kUp));
  AddSequential(new SetLifter(Shooter::kDown));
  AddSequential(new ShooterControl(1.0, 0.0));
}
