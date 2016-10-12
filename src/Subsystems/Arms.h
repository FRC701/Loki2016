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


	static constexpr double kLeftBrazoForwardPositionLimit = 0.3;
	static constexpr double kLeftBrazoReversePositionLimit = -0.1;
	static constexpr double kRightBrazoForwardPositionLimit = 0.3;
	static constexpr double kRightBrazoReversePositionLimit = -0.2;
	static constexpr double kArmsProfile1_P = 10.0;
	static constexpr double kArmsProfile1_F = 5.0;

	//..........positions..........

	static constexpr double kIntakeLevelLeft = 0.0;
	static constexpr double kIntakeLevelRight = 0.0;

	static constexpr double kPortculisLevelLeft = 0.0;
	static constexpr double kPortculisLevelRight = 0.0;

	static constexpr double kScaleLevelLeft = 0.0;
	static constexpr double kScaleLevelRight = 0.0;

	static constexpr double kLowGoalLevelLeft = 0.0;
	static constexpr double kLowGoalLevelRight = 0.0;

	static constexpr double kMoatLevelLeft = 0.0;
	static constexpr double kMoatLevelRight = 0.0;

	static constexpr double kChevalLevelLeft = 0.0;
	static constexpr double kChevalLevelRight = 0.0;


public:

	enum ArmLevelPosition
				{
					Intake = 0,
					Portculis,
					Scale,
					LowGoal,
					Moat,
					Cheval
				};

	Arms();
	void InitDefaultCommand();

	void ArmsOn(double speed);

	void GeneralSetUp();

	void ArmLevelSetUp();

	void SetArmLevel(ArmLevelPosition position);

	void SetPortculisLevel();

	void SetIntakeLevel
};

#endif
