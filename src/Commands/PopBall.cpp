#include "PopBall.h"
#include "SetLifter.h"
#include "SetArms.h"
#include "ShooterControl.h"

PopBall::PopBall()
{
  AddSequential(new SetLifter(Shooter::kUp));
  AddParallel(new SetArms(Intake::kDown));
  AddSequential(new ShooterControl(1.0, 1.0));
}
