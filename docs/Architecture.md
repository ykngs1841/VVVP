# System Architecture

## Design Principles

본 프로젝트는 운전자의 입력(State + Event), 차량 상태, 기능별 제어 로직을 각각 독립된 역할로 분리하여 설계하였습니다.

운전자의 입력은 DriverInput에서 관리하고, 차량의 현재 상태는 VehicleState에서 관리합니다. 기능별 Controller는 DriverInput과 VehicleState를 기반으로 제어 로직을 수행하며, 그 결과를 VehicleState와 ECU Output에 반영합니다.

---

## System Components

### UserInterface

사용자로부터 운전자 입력과 테스트 환경을 입력받고 시뮬레이션 결과를 출력합니다.

DriverInput을 생성하고 Battery Voltage와 같은 초기 차량 상태를 설정합니다.

### DriverInput

관리하는 정보는 다음과 같습니다.

- Brake Position (State)

- Gear Position (State)

- Engine Button Event (Event)

### VehicleState

차량의 현재 상태를 저장합니다.

관리하는 정보는 다음과 같습니다.

- Battery Voltage
- Engine State
- Engine RPM
- Dashboard State

### EngineController

DriverInput과 VehicleState를 확인하여 시동 및 종료 가능 여부를 판단합니다.

Engine Button Event를 처리한 후 VehicleState를 변경하고 ECU Output을 생성합니다.


### Logger

VehicleState 변경 내용과 ECU Output을 기록합니다.

---

## Data Flow

프로그램은 아래 순서로 동작합니다.

1. 사용자가 테스트 환경과 운전자 입력을 입력합니다.

2. UserInterface가 DriverInput을 생성하고 Battery Voltage를 초기 차량 상태로 설정합니다.

3. 사용자가 Engine Button을 누르면 DriverInput에 Engine Button Event가 생성됩니다.

4. EngineController가 DriverInput과 VehicleState를 확인하여 시동 및 종료 제어 로직을 수행합니다.

5. EngineController가 VehicleState를 변경하고 ECU Output을 생성합니다.

6. UserInterface가 ECU Output과 차량 상태를 출력합니다.