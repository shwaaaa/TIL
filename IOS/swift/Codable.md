# Codable

## Codable이란?

공식문서에 따르면 `Codable`은 자신을 외부 표현으로 변환(Encode)하거나 외부 표현으로부터 변환(Decode) 할 수 있는 타입으로, `Encodable` & `Decodabl`e로 구성된 유니온 타입(union type)으로 정의할 수 있다.

Codable은 프로토콜 이기 때문에 채택하여 사용하는데, class, struct, enum에 채택 가능하다.

Codable은 `typealis` 형태로 Decodable & Encodable을 묶어놓은 프로토콜이다.
> - typealias : 기존 선언된 데이터 타입에 별칭을 사용함으로서 코드를 더 읽기 쉽도록 만드는 문법
> - Encodable : Swift 데이터 -> 외부 표현으로
> - Decodable : 외부 표현 -> Swift 데이터 

`SwiftyJSON` 같은 라이브러리를 사용하지 않더라도 `Codable`을 사용해서 JSON데이터와 <---> Swift 자료형과 자유자재로 왔다갔다 할 수 있다.

***

## Codable 사용하기

Codable을 사용하려면 

```swift
struct codableDemo {
    var name: String
}
```
이렇게 생긴 구조체에

```swift
struct codableDemo : Codable {
    var name: String
}
```
이렇게 codable 프로토콜을 채택해주면 된다!

***

## Encode

다음과 같이 JSONEncoder를 통해 JSON 데이터로 쉽게 encode 할 수 있게 된다.

```swift
do {
    let user = User(name: "승황", age: 17)
    let encoder = JSONEncoder()
    let data = try encoder.encode(user)
} catch {
    print("\(error)")
}
```

***

## Decode

- 다음과 같이 JSONDecoder를 통해 JSON 데이터를 쉽게 decode 할 수도 있다.
- 다음 코드를 실행하면 정확히 우리가 넣었던 JSON 데이터가 나올 것이다.

```swift
let decoder = JSONDecoder()
let secondUser = try decoder.decode(User.self, from: data)
```