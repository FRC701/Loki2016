#include "FullIntake.h"
#include "SetArms.h"
#include "IntakeOn.h"
#include "ShooterControl.h"
#include "RollerOn.h"

FullIntake::FullIntake(double speed)
: mSpeed(speed)
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
	AddParallel(new IntakeOn(mSpeed));
	AddParallel(new ShooterControl(mSpeed));
	AddParallel(new RollerOn(mSpeed));

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
