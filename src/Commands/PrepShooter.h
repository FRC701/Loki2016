#ifndef PrepShooter_H
#define PrepShooter_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class PrepShooter: public CommandGroup
{

private:
	double mSpeed;
public:
	PrepShooter(double speed);

};

#endif
