# Property Wrappers

## 프로퍼티 래퍼란?

- 프로퍼티 래퍼는 Swift에서 특정한 방식으로 프로퍼티를 동작시키는 구조를 정의하는 기능이다.

- 프로퍼티 래퍼를 사용하면 복잡한 로직을 래퍼 내부에 숨기고, 코드의 가독성을 향상시키며, 일관된 방식으로 특정 기능을 제공할 수 있다. 

- `@State`, `@Binding`, `@ObservedObject`, `@EnvironmentObject`, `@FetchRequest` 등이 있다. 
> - `@State`: 뷰의 상태를 저장하는데 사용, 값을 변경할 때마다 뷰가 다시 렌더링
> - `@Binding`: 부모 뷰에서 자식 뷰로 값을 전달하고, 자식 뷰에서 부모 뷰로 값을 다시 전달하는 데 사용
> - `ObservedObject`, `@EnvironmentObject`: 객체의 변경을 감시하고 그 변화에 반응하는 데 사용
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

## @EnvironmentObject

- `parent 뷰`에서 `subview`에 특정 상태를 주입하여, `subview`에서 그 상태에 접근할때 사용한다.

- 필요한 곳 ​​어디에서나 모델 데이터를 공유 할 수 있으며, 데이터가 변경 될 때 뷰가 자동으로 업데이트 된 상태로 유지된다.

***

## @ObservedObject

- `@State`같은 경우에는 특정 view에서만 사용하는 프로퍼티였다면 `@ObservedObject`는 더 복잡한 프로퍼티(여러 프로퍼티나 메소드가 있거나, 여러 view에서 공유할 수 있는 커스텀 타입이 있는 경우) 대신 @ObservedObject를 사용한다.

- `Observed Object`가 데이터가 변경되었음을 view에 알리는 방법은 여러가지가 있지만 가장 쉬운 방법은 `@Published` 프로퍼티 래퍼를 사용하는 것이다.

## environmentobject observedobject 차이점

그렇다면 이 둘의 차이점은

- `EnvironmentObject`는 여러 뷰 간에 데이터를 공유하고 실시간으로 업데이트하기 위해 사용되며, 보통 앱의 전역 상태를 관리하는 데 사용된다. 한편, `ObservedObject`는 특정 뷰 내에서 관리되는 상태 변경을 추적하고 해당 뷰를 업데이트하는 데 사용된다.

- 요약하면, `EnvironmentObject`는 앱의 전역 데이터 공유 및 관리에 사용되며, `ObservedObject`는 뷰 내에서 특정 상태 변경을 관찰하고 해당 뷰를 다시 렌더링하는 데 사용됩니다.