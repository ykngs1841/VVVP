#pragma once

#include "Types.h"

class DriverInput
{
public:

    DriverInput();

    void setBrakePosition(int value);
    int getBrakePosition() const;

    void setGearPosition(GearPosition gear);
    GearPosition getGearPosition() const;

    void pressEngineButton();
    bool isEngineButtonPressed() const;
    void resetEngineButton();

private:

    int brakePosition;

    GearPosition gearPosition;

    bool engineButtonPressed;
};