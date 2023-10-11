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

***

## Sink
`Sink`는 횟수의 제한 없이 `Subscription`을 통해 값을 요청하는 간단한 `Subscriber`

구현을 살펴보면 아래와 같다
```swift
final public class Sink<Input, Failure> : Subscriber, Cancellable, CustomStringConvertible,
                                            CustomReflectable, CustomPlaygroundDisplayConvertible
where Failure : Error {
    final public var receiveValue: (Input) -> Void { get }
    final public var receiveCompletion: (Subscribers.Completion<Failure>) -> Void { get }
    
    final public var description: String { get }
    final public var customMirror: Mirror { get }
    final public var playgroundDescription: Any { get }
    
    public init(receiveCompletion: @escaping ((Subscribers.Completion<Failure>) -> Void), 
                receiveValue: @escaping ((Input) -> Void))
    
    final public func cancel()
    
    // Subscriber 프로토콜의 필수요소들
    final public func receive(subscription: Subscription)
    final public func receive(_ value: Input) -> Subscribers.Demand
    final public func receive(completion: Subscribers.Completion<Failure>)
}
```
> receiveValue
> - 값을 받았을 때 실행될 클로저

> receiveCompletion
> - Completion을 받았을 때 실행될 클로저

> description

> customMirror
> - 모든 타입의 인스턴스에 대한 하위 구조 및 표시되는 스타일을 나타내는 Mirror를 커스텀할 수 있다

> cancel
> - 말 그대로 subscription을 취소

***

실제 사용 예제
```swift
let intArrayPublisher = [1,2,3,4,5].publisher
        
let sink = Subscribers.Sink<Int, Never>(receiveCompletion: { print("completion: \($0)") },
                                        receiveValue: { print("value: \($0)")})

intArrayPublisher.subscribe(sink)
```
> sink를 직접 만들고 이를 Publisher의 subscribe로 전달

```swift
let intArrayPublisher = [1,2,3,4,5].publisher

intArrayPublisher
    .sink(receiveCompletion: { print("completion: \($0)") },
          receiveValue: { print("value: \($0)")})
```
> Publisher의 extension에 구현된 sink Operator를 사용

결과값
```swift
value: 1
value: 2
value: 3
value: 4
value: 5
completion: finished
```

***

## Assign
`Assign`은 `key path`로 표시된 프로퍼티에 수신된 값을 할당하는 간단한 `Subscriber`

구현을 살펴보면 아래와 같다
```swift
final public class Assign<Root, Input> : Subscriber, Cancellable, CustomStringConvertible, 
CustomReflectable, CustomPlaygroundDisplayConvertible {
    public typealias Failure = Never
    final public var object: Root? { get }
    final public let keyPath: ReferenceWritableKeyPath<Root, Input>
    
    public init(object: Root, keyPath: ReferenceWritableKeyPath<Root, Input>)

    final public func receive(subscription: Subscription)
    final public func receive(_ value: Input) -> Subscribers.Demand
    final public func receive(completion: Subscribers.Completion<Never>)
    
    final public func cancel()
}
```
> object
> - 프로퍼티를 포함하는 객체, Subscriber는 새로운 값을 받을 때마다 여기에 할당
> - Subscriber는 upstream publisher가 Subscriber의 receive(completion:)을 호출할 때까지 object에 대한 강한 참조를 유지하고, 호출된 이후에야 nil로 설정

> keyPath
> - 할당할 프로퍼티를 나타내는 key-path