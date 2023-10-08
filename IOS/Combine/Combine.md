# Combine

## Combine이란?
`Combine`은 2019년에 Apple에서 만든 새로운 프레임워크이다

```
Combine 프레임워크는 시간 경과에 따라 변경되는 값을 내보내는 Publisher와 이를 수신하는 Subscriber로 시간 경과에 따른 값 처리를 위한 선언적 Swift API
```

***

## Combine을 쓰는 이유
`Combine`이 없어도 `Delegate 패턴`, `콜백 함수`, `completion` 클로저 등을 활용해서 비동기 프로그래밍을 구현할수있다.

비동기로 구현할 때 아주 깊은 콜백 함수나 delegate가 여러 개가 되는 경우 코드도 지저분해지고 예외 처리도 까다로워진다.

이떄 `Combine`을 사용하면 깔끔하게 처리할 수 있다

***

## Combine의 구성 요소
- Publisher
> - Publisher는 하나 혹은 여러 개의 Subscriber 객체에 시간의 흐름에 따라 값을 내보낼 수 있는 타입을 선언하기 위한 프로토콜
> - Output, Failure 타입이 제네릭으로 구현

- Subscriber
> - Subscriber는 Publisher에게 값을 받을 수 있는 타입을 선언하기 위한 프로토콜
> - Input, Failure 타입이 제네릭으로 구현

- Operator
> - Operator는 Publisher를 반환하는 Publisher 프로토콜에 정의된 메서드들
> - 여러 종류의 Operator를 Combine 하여 사용하여 Publisher가 내보내는 값을 처리
> - Upstream, DownStream이라고 하는 Input, Output을 가지고 있다.

- Subscription
> - Subscription은 Publisher와 Subscriber의 연결을 나타내는 프로토콜
> - Publisher + Operator + Subscriber로 이뤄진 하나의 작업이 Subscription