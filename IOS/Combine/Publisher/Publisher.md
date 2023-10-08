# Publisher

## Publisher란?
`Publisher`는 하나 혹은 여러 개의 `Subscriber` 객체에 시간의 흐름에 따라 값을 내보낼 수 있는 타입을 선언하기 위한 프로토콜이다.

```swift
protocol Publisher {
    associatedtype Output
    associatedtype Failure : Error
    func receive<S>(subscriber: S) where S : Subscriber, Self.Failure == S.Failure, Self.Output == S.Input
}
```

`Publisher`의 프로토콜을 살펴보면 `Output`, `Failure` 타입이 존재하고 동일한 타입의 `Subscriber`을 `receive` 함수로 연결할 수 있다.
> Output : publisher가 방출하는 값의 종류

> Failure : publisher가 방출할 수 있는 에러의 종류

***

## Convenience Publisher

- Just: 가장 단순한 형태의 `Publsiher`로 에러타입으로 `Never`를 갖는다

- Promise: `Just`와 비슷하지만 `Filter Type`을 정의할 수 있다.

- Fail: 정의된 실패타입을 내보낸다

- Empty: 어떤 데이터도 발행하지 않는 퍼블리셔로 주로 에러처리나 옵셔널값을 처리할때 사용

- Sequence: 데이터를 순차적으로 발행하는 `Publisher`로 `(1…10).Publisher`로 이에 해당

- ObservableObjectPublisher: `SwiftUI`에서 사용되는 `ObservableObject`를 준수하는 퍼블리셔

***

## 간단한 동작 방식

1. 관심있는 값에 구독을 걸고
2. 그 값에 새 이벤트가 발생하면(값이 변경되면)
3. 비동기식으로 이벤트(값)을 전달 받을 수 있다.