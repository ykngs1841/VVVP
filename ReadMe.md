# Virtual Vehicle Verification Platform

## Project Overview

Virtual Vehicle Verification Platform(VVVP)은 사용자가 입력한 차량 상태를 기반으로 ECU의 제어 로직을 시뮬레이션하고, 차량의 시동 및 종료 동작을 검증하는 C++ 기반 프로젝트입니다.

본 프로젝트는 실제 차량의 동작 흐름(Input → ECU Decision → Vehicle State Update → Verification)을 객체지향적으로 모델링하여 자동차 소프트웨어의 기본적인 제어 구조를 구현하는 것을 목표로 합니다.

## Project Goal

- 객체지향 기반 자동차 소프트웨어 설계
- ECU 제어 로직 구현
- 차량 시동 및 종료 로직 구현
- 사용자 입력 기반 시뮬레이션 구현
- 차량 상태 검증(PASS / FAIL)
- 유지보수 및 확장이 가능한 소프트웨어 구조 설계

## Key Features

- 사용자 입력 기반으로 차량 상태 시뮬레이션
- ECU 제어 로직을 통한 시동 및 종료 조건 판단
- 차량 상태 검증 및 결과 제공
- 시뮬레이션 결과 및 실패 원인 기록

## How it Works

1. 사용자가 차량 상태를 입력합니다.
1. ECU가 입력 조건을 검증합니다.
1. 차량 상태를 변경합니다.
1. 검증 결과를 생성합니다.
1. 시뮬레이션 결과를 기록합니다.

## How to Run

```bash
git clone https://github.com/ykngs1841/VVVP.git
cd VVVP
mkdir build
cd build
cmake ..
cmake --build .
./VVVP

\> Detailed interface specifications are available in `docs/IO\_List.md`.
