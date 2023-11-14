# UIRepresentable

`SwiftUI`도 좋은 기능을 많이 가지고있지만 아무래도 `UIKit`보다는 나온지 얼마 안됐기때문에 지원하지 않는 기능이나 기존에 UIKit이 더 유용한 경우가 많다. 

그래서 SwiftUI에서는 이 UIKit을 SwiftUI에 맞게 wrapping해주는 기능을 제공한다.

***

## UIViewRepresentable

`UIViewRepresentable` 프로토콜은 말 그대로 `UIKit view`를 `SwiftUI`에서 사용할 수 있도록 랩핑해준다.

***

## 필수적으로 구현해야 하는 메서드

- makeUIView(context:) -> Self.UIViewType
> - SwiftUI 뷰가 생성될 때 호출되어, UIView 인스턴스를 생성하고 초기화한다
> - 초기화 과정에서 UIView의 초기 설정을 진행하고 생성된 UIView를 반환한다

- updateUIView(Self.UIViewType, context: Self.Context)
> - SwiftUI 뷰가 업데이트되는 시점에 호출되며, 변경된 데이터가 있는 경우 이를 통해 UIView를 업데이트한다
> - @Binding을 이용하여 SwiftUI에서 UIKit 방향으로 데이터를 업데이트한다

- Coordinator
> - UIKit의 뷰와 SwiftUI의 뷰 간의 통신을 위한 클래스로 UIKit의 데이터를 SwiftUI로 업데이트할 때 사용된다
> - 구조체 내에 Coordinator 클래스를 선언하고 makeCoordinator 메서드를 구현하여 Coordinator 인스턴스를 생성하고 반환한다.

***

## 사용방법

ex) UIViewRepresentable를 이용하여 SwiftUI에서 UILabel 사용

```swift
struct MyUILabel: UIViewRepresentable {
  @Binding var text: String // @Bidning property: SwiftUI -> UIKit으로의 데이터 전달
  
  func makeUIView(context: Context) -> UILabel {
    let label = UILabel()
    label.textColor = .blue
    return label
  } // makeUIView메소드
  func updateUIView(_ uiView: UILabel, context: Context) {
    uiView.text = text
  } // updateUIView
}
```

사용할 땐 SwiftUI 사용하는 방법대로 그대로 사용

```swift
import UIKit
import SwiftUI

struct ContentView: View {
  @State var text: String
  var body: some View {
    VStack {
      MyUILabel(text: $text)
    }
  }
}

struct ContentView_Previews: PreviewProvider {
  static var previews: some View {
    ContentView(text: "Example Text")
  }
}
```

