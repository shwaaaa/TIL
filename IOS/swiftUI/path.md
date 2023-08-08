# Path

## Path란?
---
- SwiftUI는 사용자가 원하는 `Custom Shape`를 그릴 수 있도록 `Path`를 제공하고 있다.

## path 사용방법
---
- `move(to:)` 메소드를 통해 시작점을 정하고, `addLine(to:)`를 통해 선을 그린다

예를 들면 삼각형을 그리고싶다면
```swift
var body: some View {
    Path { path in //Path 인스턴스와 해당 클로저를 삽입
      path.move(to: CGPoint(x: 200, y: 0)) //커서 이동, 선이 그려지진 않는다
      path.addLine(to: CGPoint(x: 200, y: 200)) //add라인을 사용하여 실제 선 그려주기
      path.addLine(to: CGPoint(x: 0, y: 200))
    }.stroke()
  }
```

이렇게 작성해주면 선 두개가 나오게 되는데 `.closeSubPath`수정자를 사용하여 자동으로 `Path`를 닫을 수 있다.
```swift
var body: some View {
    Path { path in 
      path.move(to: CGPoint(x: 200, y: 0)) 
      path.addLine(to: CGPoint(x: 200, y: 200)) 
      path.addLine(to: CGPoint(x: 0, y: 200))
      path.closeSubpath() //자동으로 경로 닫기
    }.stroke()
  }
```

- 기본적으로 검은색으로 채워져있지만 `.stroke()`를 사용해주면 도형을 채우지 않을 수 있다.

***

- 도형을 채우고 있는 색상을 바꾸고싶다면 `.fill()`을 사용하여 바꿔줄 수 있다.
```swift
var body: some View {
    Path { path in
       
       // ...
    }
    .fill(Color.green)
}
```

***

- 만약 stroke가 두꺼워 모서리가 깨질 경우 `colseSubpath()` 수정자를 사용한다.
```swift
var body: some View {
        Path { path in
          ...
          path.closeSubpath()
        }
        .stroke(Color.green, linewidth: 20)
    }
```

***

- 도형의 모서리를 둥글게 사용하고 싶다면 `StrokeStyle`구조체를 사용한다.
```swift
var body: some View {
        Path { path in
            ...
        }
        .stroke(Color.green, style: StrokeStyle(lineWidth: 20, lineCap: .round, lineJoin: .round))
        // lineWidth: 선의 두께를 조정
        // lineJoin: 두 선이 만나는 지점에대한 스타일링을 하는데 round, bevel, miter 3가지 옵션을 제공
    }
```

***

- `Shape` 프로토콜을 채택한 `Struct`를 선언하여 `Path`를 아래와 같은 `Shpae`로 간단히 변환할 수 있다.
```swift
struct MySquare: Shape {
    func path(in rect: CGRect) -> Path {
        var path = Path()
        
        path.move(to: CGPoint(x: 200, y: 0))
        path.addLine(to: CGPoint(x:200, y: 200))
        path.addLine(to: CGPoint(x: 0, y: 200))
        path.addLine(to: CGPoint(x: 0, y: 0))
        path.closeSubpath()
        
        return path
    }
}
 
struct MyShape: View {
    var body: some View {
        MySquare()
    }
}
```

