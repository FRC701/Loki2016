#include "LightsOn.h"

LightsOn::LightsOn(Relay::Value shooterLightValue, Relay::Value featureLightValue)
: mShooterLightValue(shooterLightValue), mFeatureLightValue(featureLightValue)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LightsOn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LightsOn::Execute()
{
	Robot::lights->SetShooterLights(mShooterLightValue);
	Robot::lights->SetFeatureLights(mFeatureLightValue);
}

// Make this return true when this Command no longer needs to run execute()
bool LightsOn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LightsOn::End()
{
	Robot::lights->SetShooterLights(Relay::kOff);
	Robot::lights->SetFeatureLights(Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LightsOn::Interrupted()
{
	Robot::lights->SetShooterLights(Relay::kOff);
	Robot::lights->SetFeatureLights(Relay::kOff);
}
