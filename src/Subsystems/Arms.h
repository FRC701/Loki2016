#ifndef Arms_H
#define Arms_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arms: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> leftBrazo;
	std::shared_ptr<CANTalon> rightBrazo;

	static const int kDegreesInRotation = 4096.0;

	static const int kLeftBrazoAbsoluteOffset = 2010;//final 2005;//1138;
	static const int kRightBrazoAbsoluteOffset = -221;//final 3038;//2355;


	const double kLeftBrazoForwardPositionLimit = 0.3;
	const double kLeftBrazoReversePositionLimit = -0.1;
	const double kRightBrazoForwardPositionLimit = 0.3;
	const double kRightBrazoReversePositionLimit = -0.2;
	const double kArmsProfile1_P = 10.0;
	const double kArmsProfile1_F = 5.0;

	enum ArmLevelPosition
			{
				Intake = 0,
				Portculis,
				Scale,
				LowGoal,
				Moat,
				Cheval
			};

public:
	Arms();
	void InitDefaultCommand();
	void ArmsOn(double speed);

	void GeneralSetUp();

	void ArmLevelSetUp();

	void SetArmLevel(ArmLevelPosition position);
};

#endif
