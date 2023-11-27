# Associatedtype

## Associatedtype이란?

`Associated Type`은 `Generic`에서 나오는 개념 중 하나이다.

하나 이상의 관련 타입을 선언할 때 유용하며, `Generic`과 같이 일종의 `Place holder` 역할을 해준다

즉, 진짜 타입을 주는 게 아니라 타입의 샘플을 주는거다.

사용할 실제 타입은 프로토콜이 채택될 때까지 지정되지 않으니 재사용성이 높아진다.

***

## 정의 방법

```swift
protocol SomeProtocol {
    associatedtype SomeType
}
```

타입이므로 첫 번째 단어는 대문자이고, 사용되기 전까지 `SomeType`은 어떠한 타입도 될 수 있다.

***

## 구현 예시

```swift
protocol ShwaaProtocol {
    var age: String { get }
}
```

이렇게 만들어진 ShwaaProtocol 채택하게 되면, 반드시 age를 String 타입으로 정의해줘야 한다.

여기서 만약, 다른 타입을 사용할 여지가 있거나 사용하고 싶을 때, 사용하는 것이 바로 `associatedType`이다.

***

먼저 MyType으로 Place holder 역할을 하는 타입을 만들어 준다

associatedType은 Place holder 역할만 할 뿐, 사용되기 전까지 값을 갖지 않기 때문에 값을 넣어준다.

```swift
protocol DannyProtocol {
    associatedtype MyType
    var age: MyType { get }
}
```

이제 이 만든 프로토콜을 사용하려면 

```swift
struct Danny: DannyProtocol {
    typealias MyType = Int
    var age = 10
}
```

```swift
struct Danny: DannyProtocol {
    typealias MyType = String
    var age = "열 살"
}
```

이와 같이 채택한 곳에서 원하는 타입으로 정할 수 있다.

또한 타입 추론으로 typealias를 생략해 줘도 무관하다.

***

## 특징

`associatedType`는 타입이므로 다른 프로토콜을 채택하여 제약조건을 줄 수 있다.

대신 사용 시 채택한 `MyType`이 사용할 프로토콜을 준수하고 있어야 한다.

```swift
associatedtype MyType: Equatable
```

만약 이렇게 프로퍼티에 제약을 준다면 `MyType`을 사용하는 프로퍼티는 `Equatable`을 준수하는 타입만을 채택할 수 있는 것이다.