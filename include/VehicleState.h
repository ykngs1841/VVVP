#pragma once

class VehicleState
{
public:

    VehicleState();

    // 배터리 전압
    void setBatteryVoltage(float value);
    float getBatteryVoltage() const;

    // 엔진 상태
    void setEngineState(bool state);
    bool getEngineState() const;

    // 엔진 RPM
    void setEngineRpm(int value);
    int getEngineRpm() const;

    // 계기판 상태
    void setDashboardState(bool state);
    bool getDashboardState() const;

private:

    float batteryVoltage;
    bool engineState;
    int engineRpm;
    bool dashboardState;
};