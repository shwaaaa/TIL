# LazyGrid

## LazyVGrid 

`LazyVGrid`란? `VStack`과 같이 세로로 뷰가 정렬되고 싸이는 컨테이너 뷰이다.

```swift
import SwiftUI

struct ContentView: View {
  let columns = [GridItem(.flexible()), GridItem(.flexible())]
  let colors: [Color] = [.black, .blue, .brown, .cyan, .gray, .indigo, .mint, .yellow, .orange, .purple]
  
  var body: some View {
    LazyVGrid(columns: columns) {
      ForEach(colors, id: \.self) { color in
        RoundedRectangle(cornerRadius: 10)
          .frame(width: 150, height: 100)
          .foregroundColor(color)
      }
    }
  }
}
```
위의 코드는 둥근 사각형을 `VGrid`로 보여준다.

### GridItem
- `GridItem`이란? 그리드의 행 혹은 열에 대한 디스크립션이다.

- `Grid`를 만들때 `GridItem` 타입의 컴포넌트를 만들어야한다.

- 초기화 시 넘겨줄 수 있는 파라미터는 `alignment(정렬 방법)`, `spacing(item 간격)`, `size(크기)`가 있다.

***

- size(크기)
> - `adaptive(minumum: CGFloat, maximum: CGFloat)` : 최소값과 최대값을 정하고 이 사이의 사이즈로 가장 많이 배치 가능하게 할때 사용한다.

> - `flexible(minimum: CGFloat, maximum: CGFloat)` : 최소/최대값을 정해두고 뷰 크기에 따라 사이즈를 조절할 수 있다. 인자에 아무것도 주어지지 않는다면 해당 뷰의 크기를 아이템의 수로 나눠 계산해 그려준다.

> - `fixed(CGFloat)` : 고정된 사이즈로 아이템을 지정해준다.

```swift
GridItem(.flexible(), spacing: 50)
```

***

## LazyHGrid

`LazyHGrid`란? Horizontal, 즉 수평으로 늘어나는 그리드에 SubView를 정렬하여 나타낼 수 있는 컨테이너 뷰이다.

```swift
import SwiftUI

struct ContentView: View {
  let rows = [GridItem(.flexible()), GridItem(.flexible())]
  let colors: [Color] = [.black, .blue, .brown, .cyan, .gray, .indigo, .mint, .yellow, .orange, .purple]
  
  var body: some View {
    LazyHGrid(rows: rows) {
      ForEach(colors, id: \.self) { color in
        RoundedRectangle(cornerRadius: 10)
          .frame(width: 150, height: 100)
          .foregroundColor(color)
      }
    }
  }
}
```
- `LazyVGrid`와 사용방법 동일 