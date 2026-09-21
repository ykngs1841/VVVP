#include "DriverInput.h"

DriverInput::DriverInput()
    : brakePosition(0),
    gearPosition(GearPosition::P),
    engineButtonEvent(false)
{
}

// 브레이크
void DriverInput::setBrakePosition(int value)
{
    brakePosition = value;
}

int DriverInput::getBrakePosition() const
{
    return brakePosition;
}

// 기어
void DriverInput::setGearPosition(GearPosition gear)
{
    gearPosition = gear;
}

GearPosition DriverInput::getGearPosition() const
{
    return gearPosition;
}

// 엔진 버튼
void DriverInput::pressEngineButton()
{
    engineButtonEvent = true;
}

bool DriverInput::isEngineButtonPressed() const
{
    return engineButtonEvent;
}

void DriverInput::clearEngineButtonEvent()
{
    engineButtonEvent = false;
}