#ifndef PrepShooter_H
#define PrepShooter_H

//#include "Commands/CommandGroup.h"
#include "Commands/CommandGroup.h"
#include "WPILib.h"

class PrepShooter: public CommandGroup
{
public:
	PrepShooter(double speed);

private:
	double mSpeed;
};

#endif
