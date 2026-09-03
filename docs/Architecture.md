# System Architecture

## Design Principles

본 프로젝트는 운전자의 입력, 차량 상태, ECU 제어 로직을 각각 독립된 역할로 분리하여 설계하였습니다.

운전자의 입력은 DriverInput에서 관리하고, 차량의 현재 상태는 VehicleState에서 관리합니다. ECU는 DriverInput과 VehicleState를 기반으로 제어 로직을 수행하며, 그 결과를 VehicleState와 ECU Output에 반영합니다.

또한 각 컴포넌트는 하나의 책임만 수행하도록 구성하여 유지보수성과 확장성을 높였습니다.

Battery Voltage는 실제 차량에서는 차량 상태에 해당하지만, 본 프로젝트에서는 다양한 시나리오를 검증하기 위한 초기 차량 상태로 설정합니다.

---

## System Components

### UserInterface

사용자로부터 운전자 입력과 테스트 환경을 입력받고 시뮬레이션 결과를 출력합니다.

DriverInput을 생성하고 Battery Voltage와 같은 초기 차량 상태를 설정합니다.

### DriverInput

운전자의 입력 상태를 저장합니다.

관리하는 정보는 다음과 같습니다.

- Brake Position
- Gear Position

### VehicleState

차량의 현재 상태를 저장합니다.

관리하는 정보는 다음과 같습니다.

- Battery Voltage
- Engine State
- Engine RPM
- Dashboard State

### ECU

DriverInput과 VehicleState를 확인하여 시동 및 종료 가능 여부를 판단합니다.

판단 결과에 따라 VehicleState를 변경하고 ECU Output을 생성합니다.



### Logger

VehicleState 변경 내용과 ECU Output을 기록합니다.

---

## Data Flow

프로그램은 아래 순서로 동작합니다.

1. 사용자가 테스트 환경과 운전자 입력을 입력합니다.

2. UserInterface가 DriverInput을 생성하고 Battery Voltage를 초기 차량 상태로 설정합니다.

3. Engine Button 이벤트가 발생하면 ECU가 DriverInput과 VehicleState를 확인합니다.

4. ECU가 제어 로직을 수행하여 VehicleState를 변경하고 ECU Output을 생성합니다.

5. Logger가 VehicleState 변경 내용과 ECU Output을 기록합니다.

6. UserInterface가 ECU Output과 차량 상태를 출력합니다.