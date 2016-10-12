#ifndef PrepShooter_H
#define PrepShooter_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class PrepShooter: public CommandGroup
{
public:
	PrepShooter(double mSpeed);

private:
	double speed;
};

#endif
