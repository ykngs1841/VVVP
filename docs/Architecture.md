# System Architecture

## Design Principles

본 프로젝트는 차량 상태와 제어 로직을 분리하여 설계하였습니다.

차량의 상태는 VehicleState에서 관리하고, 모든 제어 판단은 ECU에서 수행

각 컴포넌트는 하나의 역할만 수행하도록 구성하여 유지보수와 확장이 가능하도록 설계

## System Components

### User Interface

사용자로부터 차량 상태를 입력받고 시뮬레이션 결과를 출력

### ECU

차량 상태를 확인하여 시동 및 종료 가능 여부를 판단

판단 결과에 따라 VehicleState를 변경

### DriverInput

운전자의 입력 상태를 저장한다.

관리하는 정보는 다음과 같다.

- Brake Position
- Gear Position
- Engine Button

### VehicleState

차량의 현재 상태를 저장한다.

관리하는 정보는 다음과 같다.

- Battery Voltage
- Engine State
- Engine RPM
- Dashboard State

### Logger

사용자 입력과 시뮬레이션 결과를 기록한다.

## Data Flow

프로그램은 아래 순서로 동작한다.

1. 사용자가 차량 정보를 입력한다.
2. UserInterface가 입력을 DriverInput에 저장한다.
3. ECU가 DriverInput을 읽어 제어 조건을 판단한다.
4. ECU가 VehicleState를 변경한다.
5. Logger가 결과를 기록한다.
6. UserInterface가 결과를 출력한다.