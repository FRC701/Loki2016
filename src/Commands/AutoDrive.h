#ifndef AutoDrive_H
#define AutoDrive_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoDrive: public Command
{
public:
	enum Distance {
		DoNothing = 0,
		Cross,
		Shoot,
		LowBar,
		Reach,
		Cheval_Cross
	};
	AutoDrive(Distance distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Distance mdistance;
	int mposition;
	int counter;
	int tolerance;
};

#endif
