# Protocol

## Protocol이란?

특정 역할(기능)을 하기 위한 메서드, 프로퍼티, 기타 요구사항의 청사진을 정의한 것으로 기능을 정의하고 제시할 뿐, 스스로 기능을 구현하는 것이 아니다.
> - 구조체/클래스/열거형은 특정 프로토콜을 채택(adopted)해서 그 역할을 위한 요구사항을 구현한다.
> - 어떤 타입이 어떤 프로토콜의 요구사항을 따르면, '해당 프로토콜을 준수한다(conform)'라고 표현한다

스위프트에서 프로토콜은 완전한 하나의 타입으로 사용된다.
> - 파라미터나 리턴타입으로 사용 가능
> - 프로퍼티, 변수, 상수의 타입으로 사용 가능
> - 배열 등 컨테이너 요소의 타입으로 사용 가능

***

## Protocol을 사용법

`protocol` 키워드를 사용해 선언한다.

```swift
protocol 프로토콜이름 {
    프로토콜 정의
}
```

***

프로퍼티 요구사항
- 프로퍼티와 타입 프로퍼티 요구 가능
- 프로퍼티 요구사항은 항상 `var`로 선언
- 프로퍼티를 읽기 전용(`{ get }`) 으로 할지, 읽고 쓰기(`{ get, set }`)로 할지 정해줘야 함
- 구현할 때는 프로퍼티의 이름과 타입만 맞으면 됨
- 타입 프로퍼티는 `static` 키워드를 사용해 선언

```swift
protocol SomeProtocol {
    var settableProperty: String { get set }
    var notNeedToBeSettableProperty: String { get }
    static var typeProperty: Int { get }
}
```

***

메서드 요구사항
- 인스턴스 메서드 또는 타입 메서드 요구 가능
- 메서드에서 함수 `body`를 제외하고 시그니처만 작성
- 타입 메서드는 `static` 키워드 사용
```swift
protocol Sendable {
    var from: Sendable { get }
    
    func send(data: Any)
  
    static func isSendableInstance(_ instance: Any) -> Bool
}
```

***

가변 메서드 요구 (mutating method requirements)
- 값 타입(구조체, 열거형)의 인스턴스 메서드에서 자신 내부의 값을 변경할 때 `func` 앞에 `mutating`으로 선언해 준다.
- 가변 메서드를 요구한 프로토콜을 클래스가 구현할 때는 `mutating` 키워드를 생략한다.
- 프로토콜에서 가변 메서드를 요구하지 않는다면, `mutating` 메서드는 구현이 불가능하다
```swift
protocol Resettable {
  mutating func reset()
}

struct Point: Resettable {
    var x: Int = 0
    var y: Int = 0
  
    mutating func reset() {
        self.x = 0
        self.y = 0
    }
}
```

***

프로토콜 채택
- 구조체, 클래스, 열거형 등에서 타입 이름 뒤에 콜론을 붙인 후, 채택할 프로토콜을 쉼표로 나열함
- 클래스 상속도 함께 받는 경우, 상속받는 클래스 이름 다음에 프로토콜 나열한다
```swift
struct SomeStruct: AProtocol, AnotherProtocol {
  
}
```

***

프로토콜의 상속
- 프로토콜끼리도 상속이 가능하다.
- 문법은 클래스 상속 문법과 유사하다.
- 구현할 때는 상속받은 프로토콜의 요구사항까지 모두 구현해야 한다.
```swift
protocol Readable {
    func read()
}

protocol Writeable {
    func write()
}

protocol ReadWriteSpeakable: Readable, Writeable {
    func speak()
}
```

***

