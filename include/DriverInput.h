#pragma once

#include "Types.h"

class DriverInput
{
public:

    DriverInput();
    
    // 브레이크
    void setBrakePosition(int value);
    int getBrakePosition() const;

    //기어
    void setGearPosition(GearPosition gear);
    GearPosition getGearPosition() const;

    //엔진 버튼 
    void pressEngineButton();
    bool isEngineButtonPressed() const; //엔진 버튼 입력 확인
    void clearEngineButtonEvent(); //엔진버튼 초기화

private:

    int brakePosition;
    GearPosition gearPosition;
    bool engineButtonEvent;
};