# IO List

## Input

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

### Battery Voltage

배터리 전압

- Type : Float
- Domain : 0.0 ~ 15.0
- Unit : V

/* ### Engine Button

엔진 버튼 입력

- Type : Boolean
- Domain : True / False
- Description
  - False : 버튼 미입력
  - True : 버튼 입력
*/
---

## VehicleState

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

## Output

### Verification Result

시뮬레이션 검증 결과

- Type : Enum
- Domain : PASS / FAIL

### Failure Reason

검증 실패 원인

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

Engine Button이 입력되면 아래 조건을 모두 만족해야 시동이 가능하다.

- Brake Position > 0
- Gear Position = P 또는 N
- Battery Voltage ≥ 11.5 V
- Engine State = OFF

조건을 모두 만족하면 VehicleState가 아래와 같이 변경된다.

- Engine State = ON
- Engine RPM = 850
- Dashboard State = ON
- Verification Result = PASS

조건을 만족하지 못하면 VehicleState는 변경되지 않으며 Verification Result는 FAIL을 반환한다.

### Engine Stop

Engine Button이 입력되면 아래 조건을 모두 만족해야 시동을 종료할 수 있다.

- Brake Position > 0
- Engine State = ON

조건을 모두 만족하면 VehicleState가 아래와 같이 변경된다.

- Engine State = OFF
- Engine RPM = 0
- Dashboard State = OFF
- Verification Result = PASS

조건을 만족하지 못하면 VehicleState는 변경되지 않으며 Verification Result는 FAIL을 반환한다.