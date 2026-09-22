#pragma once

#include "DriverInput.h"
#include "VehicleState.h"

class EngineController
{
public:

    EngineController(DriverInput& driverInput, VehicleState& vehicleState);

    void processEngineButton();

private:

    DriverInput& driverInput;
    VehicleState& vehicleState;
};