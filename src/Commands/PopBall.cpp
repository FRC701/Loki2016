#include "PopBall.h"
#include "SetLifter.h"
#include "SetArms.h"
#include "ShooterControl.h"
#include "RollerOn.h"

PopBall::PopBall()
{
  AddSequential(new SetLifter(Shooter::kUp));
  AddParallel(new SetArms(Intake::kDown));
  AddSequential(new ShooterControl(1.0));
  AddParallel(new RollerOn(1.0));
}
