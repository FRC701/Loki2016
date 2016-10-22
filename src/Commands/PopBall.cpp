#include "PopBall.h"

#include "Delay.h"
#include "SetArms.h"
#include "SetLifter.h"
#include "ShooterIntake.h"

PopBall::PopBall()
{
	AddSequential(new SetLifter(Shooter::kUp));
	AddSequential(new SetArms(Intake::kDown));
	AddSequential(new Delay(1.0));
	AddSequential(new ShooterIntake(1.0, 1.0));
}
