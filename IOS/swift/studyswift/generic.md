# Generic

## generic이란?
- 제네릭 코드는 유연하게 작성할 수 있고, 재사용가능한 함수와 타입이 어떤 타입과 작업할 수 있도록 요구사항을 정의한다

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

그렇기때문에 여기서 파라미터 타입이 Double, String일 경우엔 사용할 수 없다!

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

