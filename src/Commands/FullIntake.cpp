#include "FullIntake.h"
#include "SetArms.h"
#include "SetLifter.h"
#include "IntakeOn.h"
#include "ShooterControl.h"
#include "RollerOn.h"

FullIntake::FullIntake(double direction)
: mDirection(direction)
{
	Requires(Robot::intake.get());
	Requires(Robot::shooter.get());
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

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

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
