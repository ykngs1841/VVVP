#include "VehicleState.h"

VehicleState::VehicleState()
    : batteryVoltage(0.0f),
    engineState(false),
    engineRpm(0),
    dashboardState(false)
{
}

// 배터리 전압
void VehicleState::setBatteryVoltage(float value)
{
    batteryVoltage = value;
}

float VehicleState::getBatteryVoltage() const
{
    return batteryVoltage;
}

// 엔진 상태
void VehicleState::setEngineState(bool state)
{
    engineState = state;
}

bool VehicleState::getEngineState() const
{
    return engineState;
}

// 엔진 RPM
void VehicleState::setEngineRpm(int value)
{
    engineRpm = value;
}

int VehicleState::getEngineRpm() const
{
    return engineRpm;
}

// 계기판 상태
void VehicleState::setDashboardState(bool state)
{
    dashboardState = state;
}

bool VehicleState::getDashboardState() const
{
    return dashboardState;
}