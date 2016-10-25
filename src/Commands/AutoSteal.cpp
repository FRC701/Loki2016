#include "AutoSteal.h"
#include "SetArms.h"
#include "AutoDrive.h"
#include "AutoStealTankDrive.h"
#include "SetShifter.h"
#include "SetBrake.h"
#include "FullIntake.h"

AutoSteal::AutoSteal()
{
	Requires(Robot::chassis.get());
	Requires(Robot::intake.get());
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
	AddParallel(new AutoStealTankDrive(0.5, 0.5));
	AddSequential(new FullIntake(-1.0));

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
