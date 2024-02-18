# ViewModifier

## Opaque Type

`some View`는 View의 한 종류인것만 결정되어있고, 자세히 어떤 View인지는 컴파일러가 직접 판단하는 View이다

`Some`은 Opaque Type (불투명 타입)을 표현한다
- `Opaque Type Some`은 `computed property` 혹은 함수의 구체적인 `return type`을 숨길 수 있도록 해준다. 이를 통해 간결한 코드 작성이 가능해진다.
- Opaque Type은 `Reverse Generic Type`이라고 불리기도 한다.
- `Generic`은 함수가 타입 제약을 유지하면서 다양한 타입을 허용할 수 있도록 한다.
- Opaque은 함수가 자유로운 타입을 리턴할 수 있도록 한다

---

## ViewModifier

SwiftUI에 내장된 프로토콜로, 기존의 뷰 또는 다른 `View Modifier`에 적용시켜 또 다른 버전을 만들 수 있는 `Modifier`이다.

기존의 View 또는 Modifier를 추가적으로 꾸며 새로운 Modifier를 생성할 수 있다.

아래는 기존에 존재하는 content에 내장 Modifier를 사용하여 `BorderedCaption`라는 하나의 Modifier를 만든 것이다.

```swift
struct BorderedCaption: ViewModifier {
    func body(content: Content) -> some View {
        content
            .font(.caption2)
            .padding(10)
            .overlay(
                RoundedRectangle(cornerRadius: 15)
                    .stroke(lineWidth: 1)
            )
            .foregroundColor(Color.blue)
    }
}
```

이렇게 생성된 Modifier는 적용이 필요한 View 뒤에 .modifier(modifier: T)를 입력하는 것으로 사용할 수 있다.

```swift
struct ContentView: View {
  var body: some View {
    Text("Downtown Bus")
      .modifier(TextModifier())
  }
}
```

modifier를 `extension`에 적용해 더 선언적으로 사용할수도 있다.

```swift
extension View {
    func borderedCaption() -> some View {
        modifier(BorderedCaption())
    }
}
```

```swift
struct ContentView: View {
  var body: some View {
    Text("Downtown Bus")
      .borderedCaption()
  }
}
```

Modifier를 적용하면 매번 새로운 View가 생성되는 것이나 마찬가지다.
> SwiftUI에서 View 자체는 구조체 형태로 구성되는데, 구조체는 immutable하기 때문에 내부를 수정할 수 없다.

> 따라서 변화가 생기면 수정사항이 반영된 새로운 View를 리턴하는 것이다.
