#ifndef Arms_H
#define Arms_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arms: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> Armleft;
	std::shared_ptr<CANTalon> Armright;

public:
	Arms();
	void InitDefaultCommand();
};

#endif
