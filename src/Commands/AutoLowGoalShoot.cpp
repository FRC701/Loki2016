#include "AutoLowGoalShoot.h"
#include "SetLifter.h"
#include "AutoDrive.h"
#include "AutoTurn.h"
#include "ShooterControl.h"
#include "SetArms.h"

AutoLowGoalShoot::AutoLowGoalShoot()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	AddSequential(new SetArms(Intake::kUp));
	AddSequential(new SetLifter(Shooter::kDown));
	AddSequential(new AutoDrive(AutoDrive::LowBar));
	AddSequential(new AutoTurn(AutoTurn::turnLeft, 600));
	AddSequential(new ShooterControl(1.0, 1.0));


	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}