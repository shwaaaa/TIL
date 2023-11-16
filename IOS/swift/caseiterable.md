# CaseIterable

## CaseIterable이란?

만약 열거형에 포함된 모든 케이스에 대해서 순회를하고 싶다면?

`CaseIterable` 프로토콜을 채택하면 `allCase` 라는 타입 프로퍼티를 통해 모든 케이스에 대한 컬렉션을 생성할 수 있다.

## 사용법

```swift
enum Shwaaaa: CaseIterable {
    case name
    case age
}

let allCase: [Shwaaaa] = Shwaaaa.allCases
```

이때 열거형이 상속받을 원시값을 위해서 항상 첫 번째에 위치해야 한다.

단순히 `CaseIterable` 을 채택해주는 것만으로는 `allCases` 를 사용할 수 없는 복잡한 경우가 있다.

***

1. 플랫폼별로 조건
> - `available` 로 특정 케이스를 플랫폼에 따라 사용할 수 없는 경우가 생기면 `CaseIterable` 프로토콜을 채택하는 것만으로는 `allCases` 프로퍼티를 사용할 수 없다.

> - 이때는 직접 `allCases` 프로퍼티를 구현해 주어야 한다.

2. 케이스가 연관 값을 갖는 경우
> - enum 형의 케이스가 연관 값을 갖는 경우 즉, 파라미터를 전달하는 경우에는. `CaseIterable` 프로토콜을 채택하여도 `allCases` 프로퍼티를 사용할 수 없다.

> - 이때도 마찬가지로 직접 `allCases` 프로퍼티를 구현해 주어야 한다.