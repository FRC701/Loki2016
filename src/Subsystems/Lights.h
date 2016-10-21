#ifndef Lights_H
#define Lights_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lights: public Subsystem
{
private:
	std::shared_ptr<Relay> feature;
	std::shared_ptr<Relay> shooter;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Lights();
	void InitDefaultCommand();

	void SetFeatureLights(Relay::Value value);

};

#endif
