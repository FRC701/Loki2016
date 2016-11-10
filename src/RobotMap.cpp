#include "RobotMap.h"

//......................Chassis...........................
std::shared_ptr<CANTalon> RobotMap::chassisLeft1Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisLeft2Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisLeft3Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight1Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight2Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight3Wheel;

//......................Solenoids..........................
std::shared_ptr<DoubleSolenoid> RobotMap::chassisShifter;
std::shared_ptr<DoubleSolenoid> RobotMap::chassisKickstand;

void RobotMap::init() {
    //..................Chassis.....................
    chassisLeft1Wheel.reset(new CANTalon(kLeft1ID));
    chassisLeft2Wheel.reset(new CANTalon(kLeft2ID));
    chassisLeft3Wheel.reset(new CANTalon(kLeft3ID));

    chassisRight1Wheel.reset(new CANTalon(kRight1ID));
    chassisRight2Wheel.reset(new CANTalon(kRight2ID));
    chassisRight3Wheel.reset(new CANTalon(kRight3ID));

    //..................Solenoids....................
    chassisShifter.reset(new DoubleSolenoid(kShifterF,kShifterR));
}
