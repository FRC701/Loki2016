#include "Lights.h"
#include "../RobotMap.h"

Lights::Lights()
  : Subsystem("Lights")
{
  feature = RobotMap::lightsFeature;
  shooter = RobotMap::lightsShooter;

  SetFeatureLights(Relay::kForward);
}

void Lights::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  //SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Lights::SetFeatureLights(Relay::Value value)
{
  feature->Set(value);
}
