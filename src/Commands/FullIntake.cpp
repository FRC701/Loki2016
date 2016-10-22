#include "FullIntake.h"
#include "SetArms.h"
#include "SetLifter.h"
#include "IntakeOn.h"
#include "ShooterControl.h"

// todo: remove mDirection.
FullIntake::FullIntake(double direction)
: mDirection(direction)
{
  AddSequential(new SetArms(Intake::kDown));
  AddSequential(new SetLifter(Shooter::kDown));

  if(Robot::shooter->IsRollerClosed())
  {
    AddParallel(new ShooterControl(1.0 *mDirection, 1.0 *mDirection));
    AddSequential(new IntakeOn(0.75 *mDirection));
  }

  else
  {
    AddParallel(new ShooterControl(0.0,0.0));
    AddSequential(new IntakeOn(0.0));
  }
}
