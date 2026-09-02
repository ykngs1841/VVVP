# IO List

## DriverInput

### Brake Position

브레이크 페달 입력값

- Type : Integer
- Domain : 0 ~ 100
- Unit : %

- Description
  - 0 : 브레이크 미입력
  - 1 ~ 99 : 브레이크 강도
  - 100 : 최대 제동

### Gear Position

변속기 위치

- Type : Enum
- Domain : P, R, N, D
- Unit : N/A

---

## VehicleState

### Battery Voltage

차량 배터리 전압

- Type : Float
- Domain : 0.0 ~ 15.0
- Unit : V

### Engine State

엔진 상태

- Type : Boolean
- Domain : ON / OFF

### Engine RPM

엔진 회전수

- Type : Integer
- Domain : 0 ~ 8000
- Unit : rpm

### Dashboard State

계기판 상태

- Type : Boolean
- Domain : ON / OFF

---

## Event

### Engine Button

엔진 버튼 입력 이벤트

- Type : Event

- Description
  - Press : 엔진 버튼 입력

※ Engine Button은 상태(State)를 저장하지 않으며, 버튼이 눌리는 순간 ECU를 호출하는 이벤트로 동작한다.

---

## ECU Output

### Control Result

ECU 제어 결과

- Type : Enum
- Domain : PASS / FAIL

### Failure Reason

제어 실패 원인

- Type : String

- Description
  - None
  - Brake Not Pressed
  - Invalid Gear Position
  - Low Battery Voltage
  - Engine Already Running
  - Engine Already Stopped

---

## Validation Rules

### Engine Start

Engine Button 이벤트가 발생하면 ECU는 DriverInput과 VehicleState를 확인하여 아래 조건을 모두 만족해야 시동을 수행한다.

#### DriverInput

- Brake Position > 0
- Gear Position = P 또는 N

#### VehicleState

- Battery Voltage ≥ 11.5 V
- Engine State = OFF

조건을 모두 만족하면 VehicleState가 아래와 같이 변경된다.

- Engine State = ON
- Engine RPM = 850
- Dashboard State = ON
- Control Result = PASS

조건을 만족하지 못하면 VehicleState는 변경되지 않으며 Control Result는 FAIL을 반환한다.

---

### Engine Stop

Engine Button 이벤트가 발생하면 ECU는 DriverInput과 VehicleState를 확인하여 아래 조건을 모두 만족해야 시동을 종료한다.

#### DriverInput

- Brake Position > 0

#### VehicleState

- Engine State = ON

조건을 모두 만족하면 VehicleState가 아래와 같이 변경된다.

- Engine State = OFF
- Engine RPM = 0
- Dashboard State = OFF
- Control Result = PASS

조건을 만족하지 못하면 VehicleState는 변경되지 않으며 Control Result는 FAIL을 반환한다.