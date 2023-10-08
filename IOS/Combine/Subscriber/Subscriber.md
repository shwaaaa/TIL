# Subscriber

## Subscriber란?
`Subscriber`는 `Publisher`에게 값을 받을 수 있는 타입을 선언하기 위한 프로토콜이며 `Input`, `Failure` 타입이 제네릭으로 구현되어있다.
> Input : subscriber가 받는 값의 종류

> Failure : subscriber 받을 수 있는 에러의 종류

***

## Subscriber 구현
Subscriber는 크게 3가지로 구현할 수 있다.

1. `Subscriber`를 상속받아 직접 구현하기
2. `sink`를 이용하여 결괏값 받기
3. `asggin`을 이용하여 스트림 값을 전달하기

***

## Subscriber 역할을 하는 타입들을 정의해둔 곳
- Demand
- Completion
- Sink
- Assign