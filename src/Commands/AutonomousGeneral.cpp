#include "AutonomousGeneral.h"

#include "AutoTankDrive.h"
#include "SetArms.h"
#include "SetBrake.h"

AutonomousGeneral::AutonomousGeneral()
{
  AddSequential(new SetBrake(Chassis::kBrake));
  AddSequential(new SetArms(Intake::kDown));
  AddSequential(new AutoTankDrive(3.0, -0.9, -0.9));
}
