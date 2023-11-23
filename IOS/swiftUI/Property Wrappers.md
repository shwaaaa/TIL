# Property Wrappers

## 프로퍼티 래퍼란?

- 프로퍼티 래퍼는 Swift에서 특정한 방식으로 프로퍼티를 동작시키는 구조를 정의하는 기능이다.

- 프로퍼티 래퍼를 사용하면 복잡한 로직을 래퍼 내부에 숨기고, 코드의 가독성을 향상시키며, 일관된 방식으로 특정 기능을 제공할 수 있다. 

- `@State`, `@Binding`, `@ObservedObject`, `@EnvironmentObject`, `@FetchRequest` 등이 있다. 
> - `@State`: 뷰의 상태를 저장하는데 사용, 값을 변경할 때마다 뷰가 다시 렌더링
> - `@Binding`: 부모 뷰에서 자식 뷰로 값을 전달하고, 자식 뷰에서 부모 뷰로 값을 다시 전달하는 데 사용
> - `@ObservedObject`, `@EnvironmentObject`: 객체의 변경을 감시하고 그 변화에 반응하는 데 사용
> - `@FetchRequest`: CoreData에서 데이터를 검색하는 데 사용

***

## 프로퍼티 래퍼를 사용하는 이유는?

- 프로퍼티 래퍼를 통해 다양한 동작을 캡슐화하고 코드를 간결하게 유지하는데 도움이 된다.

- 다양한 데이터 흐름 패턴을 쉽게 구현할 수 있다.

***

## 그럼 프로퍼티 래퍼를 언제 사용할까?

- SwiftUI에서 프로퍼티 래퍼는 주로 뷰의 상태 관리나 환경 설정에 사용된다.

***

## 프로퍼티 래퍼 사용법

밑은 프로퍼티래퍼를 사용한 예시 코드이다!

```swift
struct ContentView: View {
    @State private var isOn = false // @State Property Wrapper를 사용하여 isOn 변수 선언
    
    var body: some View {
        VStack {
            Toggle(isOn: $isOn) { // $isOn을 사용하여 isOn 변수를 바인딩
                Text("Toggle")
            }
            Text("Toggle is \(isOn ? "on" : "off")")
        }
    }
}
```
- Toggle 뷰에서 isOn 변수가 변경될 때마다 뷰가 다시 렌더링된다.

- 또한 sOn 변수가 변경될 때마다 Text 뷰에서 텍스트가 업데이트된다.

***

## @State

`@State` 속성을 사용하면 SwiftUI는 해당 뷰가 변경될 때마다 자동으로 뷰를 다시 그리도록 처리한다.

`@State`를 사용하는 변수는 구조체 내부에서만 사용할 수 있다.

구조체는 값 타입이기 때문에 `@State`로 선언된 변수의 값이 변경되면 SwiftUI는 해당 뷰를 다시 렌더링한다

***

## Binding

`Binding`은 SwiftUI에서 데이터의 양방향 바인딩을 가능하게한다

Binding을 사용하면 여러 뷰 간에 데이터를 전달하고 업데이트할 수 있다

주로 상위 뷰에서 하위 뷰로 데이터를 전달하거나 하위 뷰에서 상위 뷰로 변경 사항을 알리는 데 사용되며, 보통 `@State`와 함께 사용된다
> 상위 뷰에서 `@State`로 상태를 관리하고, 하위 뷰에서는 `Binding`으로 해당 상태를 전달받아 사용

***

## @EnvironmentObject

`parent 뷰`에서 `subview`에 특정 상태를 주입하여, `subview`에서 그 상태에 접근할때 사용한다.

필요한 곳 ​​어디에서나 모델 데이터를 공유 할 수 있으며, 데이터가 변경 될 때 뷰가 자동으로 업데이트 된 상태로 유지된다.

`EnvironmentObject`를 사용하려면, 먼저 해당 객체가 `ObservableObject` 프로토콜을 준수해야 한다

그런 다음 최상위 뷰에서 `@EnvironmentObject` 속성 래퍼를 사용하여 해당 객체를 설정하고, 이를 하위 뷰에서 `@EnvironmentObject`로 가져와 사용

***

## @ObservedObject

`@State`같은 경우에는 특정 view에서만 사용하는 프로퍼티였다면 `@ObservedObject`는 더 복잡한 프로퍼티(여러 프로퍼티나 메소드가 있거나, 여러 view에서 공유할 수 있는 커스텀 타입이 있는 경우) 대신 @ObservedObject를 사용한다.

`Observed Object`가 데이터가 변경되었음을 view에 알리는 방법은 여러가지가 있지만 가장 쉬운 방법은 `@Published` 프로퍼티 래퍼를 사용하는 것이다.

***

## environmentobject observedobject 차이점

그렇다면 이 둘의 차이점은

- `EnvironmentObject`는 여러 뷰 간에 데이터를 공유하고 실시간으로 업데이트하기 위해 사용되며, 보통 앱의 전역 상태를 관리하는 데 사용된다. 한편, `ObservedObject`는 특정 뷰 내에서 관리되는 상태 변경을 추적하고 해당 뷰를 업데이트하는 데 사용된다.

- 요약하면, `EnvironmentObject`은 주로 전역 데이터 공유에 사용되고, `ObservedObject`는 주로 로컬 뷰의 상태를 관리하는 데 사용된다

***

## ObservedObject와 StateObject

`@ObservedObject`와 `@StateObject` 모두 기본적으로 뷰 내부에서 관찰 가능한 객체의 인스턴스를 저장하기 위해 사용된다.

그렇다면 이 두개의 차이점은 무엇일까?

***

### 데이터 변화

- @ObservedObject: 데이터 변화가 있을 때 뷰를 처음부터 다시 그린다.

- @StateObject: 데이터 변화가 있을 때 변화가 있는 부분의 뷰만 다시 그린다.

### 생명주기

- @ObservedObject: 뷰가 사라지고 다시 그려짐에 따라, 인스턴스도 사라지고 다시 생성된다.

- @StateObject: 초기에 인스턴스가 생성되고 뷰와 상관없이 유지된다.

### 사용

- @ObservedObject: 보통 다루는 데이터가 달라지는 하위 뷰에서 사용한다.

- @StateObject: 보통 데이터를 유지해야하고 초기에 생성되는 상위 뷰에서 사용된다.