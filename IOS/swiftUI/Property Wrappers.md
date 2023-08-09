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