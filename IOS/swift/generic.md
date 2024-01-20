# Generic

## generic이란?
- `Generic`을 사용하면 좀 더 유연하게 Funtion 및 Type을 작성할 수 있다.

- 제네릭을 사용하면 중복을 피하고, 의도를 명확하게 표현하고, 추상적인 방법으로 코드를 작성할 수 있다.

***

## 제네릭 함수(Generic Function) 
먼저 함수를 만들어보면
```swift
func genericFunction (_a: Int, _b: Int) {
    print("a = \(a)")
    print("b = \(b)")
}
```
이렇게 파라미터 타입은 Int이다.

그렇기때문에 여기서 파라미터 타입이 Double, String일 경우엔 사용할 수 없다.

만약 Double, String 값도 받고싶을 때 `제네릭`을 쓸 수 있다!!!

```swift
func genericFunction<T>(_a: T, _b: T) {
    print("a = \(a)")
    print("b = \(b)")
}
genericFunction(1.26, 2.7) //a = 1.26, b = 2.7
genericFunction("쿠쿸", "다스") //a = 쿠쿸, b = 다스
```
이렇게 `꺽새<>`를 이용해서 안에 타입처럼 사용할 `이름(T)`를 선언해주면,

그 뒤로 해당 `이름(T)`를 `타입`처럼 사용할 수 있다!!!

여기서 이 `T`를 `Type Parameter`라고 부르는데, 

`T`라는 새로운 형식이 생성되는 것이 아니라,

실제 함수가 호출될 때 해당 매개변수의 타입으로 대체되는 `Placeholder`이다.

***

## 제네릭 타입(Generic Type)
제네릭은 함수에서만 가능한 것이 아닌 `구조체`, `클래스`, `열거형` 타입에도 선언할 수 있는데, 이것을 `제네릭 타입(Generic Type)` 이라고 한다

Stack을 제네릭으로 만들고 싶다면 
```swift
struct Stack<T> {
    let items: [T] = []
 
    mutating func push(_ item: T) { ... }
    mutating func pop() -> T { ... }
}
```

제네릭 타입의 인스턴를 생성하고 싶다면
```swift
let stack1: Stack<Int> = .init()
let stack2 = Stack<Int>.init()
```

***

## 제네릭 타입을 이용한 예시

```swift
func replaceNilValues<T>(from array: [T?], with element: T) -> [T] {
  array.compactMap {
    $0 == nil ? element : $0
  }
}
```

()는 함수의 매개 변수를 둘러싸고있고, <>는 함수의 타입 매개변수를 둘러싸고 있다.

여기에는 T라고 불리는 하나의 타입 매개변수가 사용되었다.

이 T는 특별한 의미를 지니고 있는것은 아니며 사용자에 의해 다른 이름으로 얼마든지 지어질 수 있으며,

제네릭 타입을 사용한 함수를 호출하게될 경우, 스위프트는 T를 구체타입으로 대체한다.

```swift
let numbers: [Int?] = [32, 3, 24, nil, 4]
let filledNumbers = replaceNilValues(from: numbers, with: 0)
print(filledNumbers) // [32, 3, 24, 0, 4]
```

앞서 함수를 정의할 때, T?의 배열과 T를 매개변수 타입으로 지정해주었다.

제네릭을 이용하여 정의한 함수를 numbers에서 호출하면 스위프트는 numbers에 [Int?]의 유형이 사용된다는 것을 캐치하고 T를 Int로 교체해야 한다는 것을 똑똑하게 알아낼 수 있다.

이렇게 하면 여러 타입에 대한 단일 함수를 만들 수 있게되어 굳이 타입별로 여러 함수를 만들 필요가 없어진다.

