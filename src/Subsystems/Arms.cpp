#include "Arms.h"
#include "../RobotMap.h"
#include "../Commands/ArmOn.h"

Arms::Arms() :
		Subsystem("Arms")
{
	 leftBrazo = RobotMap::armsLeftBrazo;
     rightBrazo = RobotMap::armsRightBrazo;

     GeneralSetUp();
}

void Arms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArmOn(0.0));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Arms::ArmsOn(double speed){
	leftBrazo->Set(speed);
	rightBrazo->Set(speed);
}

void Arms::ArmLevelSetUp()
{
	leftBrazo->SetControlMode(CANTalon::kPosition);
	rightBrazo->SetControlMode(CANTalon::kPosition);
}

void Arms::SetArmLevel(ArmLevelPosition position)
{
	if(position == Arms::Portculis)
	{
		Robot::arms->leftBrazo->SelectProfileSlot(1);
		Robot::arms->rightBrazo->SelectProfileSlot(1);

		Robot::arms->leftBrazo->Set(-0.026);
		Robot::arms->rightBrazo->Set(0.022);
	}

	else
	{
	Robot::arms->leftBrazo->SelectProfileSlot(0);
	Robot::arms->rightBrazo->SelectProfileSlot(0);
	}

	switch(position)
	{
	case Intake:
		Robot::arms->leftBrazo->Set(0.0);
		Robot::arms->rightBrazo->Set(0.0);
		break;
	case Scale:
		Robot::arms->leftBrazo->Set(0.150);
		Robot::arms->rightBrazo->Set(-0.150);
		break;
	case LowGoal:
		Robot::arms->leftBrazo->Set(0.151);
		Robot::arms->rightBrazo->Set(-0.153);
		break;
	case Moat:
		Robot::arms->leftBrazo->Set(0.08);
		Robot::arms->rightBrazo->Set(-0.08);
		break;
	case Cheval:
		Robot::arms->leftBrazo->Set(0.0);
		Robot::arms->rightBrazo->Set(0.0);
	}

}

void Arms::GeneralSetUp()
{
	/*
    rightBrazo->SetInverted(true);
    rightBrazo->SetControlMode(CANTalon::kFollower);
    rightBrazo->Set(RobotMap::kLeftBrazo);
	*/

    //..........left..........

    leftBrazo->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    leftBrazo->SetPosition(leftBrazo->GetPulseWidthPosition() - kLeftBrazoAbsoluteOffset / kDegreesInRotation);
    leftBrazo->SetSensorDirection(true);

    leftBrazo->ConfigNominalOutputVoltage(+0.0f, -0.0f);
    leftBrazo->ConfigPeakOutputVoltage(+12.0, -12.0);

    leftBrazo->SelectProfileSlot(1);
    leftBrazo->SetPID(kArmsProfile1_P, 0.0, 0.0, kArmsProfile1_F);
    leftBrazo->Set(0.0);

    leftBrazo->SelectProfileSlot(0);
    leftBrazo->SetPID(5.0, 0.0, 0.0, 0.0);
    leftBrazo->Set(0.0);

    leftBrazo->SetControlMode(CANTalon::kPercentVbus);
    leftBrazo->Set(0.0);

    //..........right..........

    rightBrazo->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    rightBrazo->SetPosition(rightBrazo->GetPulseWidthPosition() - kRightBrazoAbsoluteOffset / kDegreesInRotation);
    rightBrazo->SetSensorDirection(true);

    rightBrazo->Set(0.0);
    rightBrazo->ConfigNominalOutputVoltage(+0.0f, -0.0f);
    rightBrazo->ConfigPeakOutputVoltage(+12.0, -12.0);

    rightBrazo->SelectProfileSlot(1);
    rightBrazo->SetPID(kArmsProfile1_P, 0.0, 0.0, kArmsProfile1_F);
    rightBrazo->Set(0.0);

    rightBrazo->SelectProfileSlot(0);
    rightBrazo->SetPID(5.0, 0.0, 0.0, 0.0);
    rightBrazo->Set(0.0);

    rightBrazo->SetControlMode(CANTalon::kPercentVbus);
    rightBrazo->Set(0.0);
}
