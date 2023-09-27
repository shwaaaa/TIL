# Struct와 Class

## Struct 
`Struct(구조체)`는 `struct` 키워드로 다음과 같이 정의한다.
```swift
struct seunghwa {
    var name: String
    var age: Int
}
```

구조체를 정의하고 인스턴스를 초기화 
```swift
var member = seunghwa(name: "seunghwa", age: 17)
```

프로퍼티에 기본값이 있는 경우 아래와 같이 생성해도 무방
```swift
var member = seunghwa()
```

인스턴스가 생성이 되고 프로퍼티 값에 접근 하고 싶을 때는 `dot syntax (.)` 를 사용
```swift
var member = seunghwa(name: yena, age: 17)
member.name = "seunghwa"
member.age = 17
print(member.name) //seunghwa
print(member.age) //17
```

***

## Class

`Class(클래스)`는 `class` 키워드로 다음과 같이 정의한다.
```swift
class gsmMember {
    var name = ""
    var grade = 1
}

클래스를 정의하고 인스턴스를 초기화 
```swift
var member2 = gsmMember()
```

구조체와 마찬가지로 클래스도 인스턴스가 생성이 되고 초기화되고 프로퍼티 값에 접근 하고 싶을 때는 `dot syntax (.)` 를 사용하면 된다.
```swift
var member2 = gsmMember()
member2.name = "seunghwa"
member2.age = 1
print(member2.name) //seunghwa
print(member2.age) //1
```

***

## Struct와 Class의 차이점

구조체와 클래스는 매우 유사하다!

공통점으로는 
1. 값을 저장하는 `프로퍼티`를 정의한다
2. 기능 제공을 위한 `메서드`를 정의한다
3. 초기화 상태를 설정하기 위한 `초기화`를 정의한다
4. 특정 종류의 표준 기능을 제공하는 `프로토콜`을 준수한다
5. `extension`을 사용하여 기능을 확장할 수 있다.

그렇다면 차이점은?
1. 클래스는 상속이 가능하다.
2. 클래스는 타입 캐스팅을 사용하여 런타임에 클래스 인스턴스의 타입을 확인하고 해석할 수 있다.

또 `Struct`는 `값타입`, `class`는 `참조타입`이다

- 값타입인 `struct`는 `stack`에 실제 데이터가 저장
> - `stack`은 `LIFO(Last In First Out)` 형태의 자료구조로 가장 마지막에 들어간 객체가 가장 먼저 나오게 되는 자료구조이다.
> - `Stack`의 값을 사용하는 것이 `Heap`의 값을 사용하는 것보다 빠르다고 할 수 있다.

- 참조타입인 `class`는 `heap`에 실제 데이터가 저장되고, `stack`에는 `heap`영역의 메모리주소가 저장
> - 메모리 할당과 해제가 하나의 명령어로 처리되지 않기 때문에 `Heap`은 `stack`보다 관리하기 어렵다.
> - `stack`에서는 `pop`, `push`라는 하나의 명령어로 할당, 해제가 이루어졌지만 `Heap`은 참조 계산도 해줘야 하므로 `Stack`보다 복잡하다.

애플은 가이드라인에서 다음 조건 중 하나 이상에 해당된다면 `구조체`를 사용하기를 권한다.

- 연관된 간단한 값의 집합을 캡슐화 하는 것만이 목적일 때 
- 캡슐화된 값이 참조되는 것보다 복사되는 것이 합당할 때
- 구조체에 저장된 프로퍼티가 값 타입이며 참조되는 것보다 복사되는 것이 합당할 때
- 다른 타입으로부터 상속받거나 자신이 상속될 필요가 없을 때 
