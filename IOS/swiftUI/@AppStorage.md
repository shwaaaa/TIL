# @AppStorage

## @AppStorage란?

- UserDefault의 SwfitUI버전
- App의 전역범위에 데이터 공유 가능
- Binding으로 서브뷰로 전달하여 데이터를 바로 업데이트 가능

***

## 사용 방법

```swift
@AppStorage("KEY") var Name: Type = Value
```

@AppStorage 뒤에 고유 값을 적어주면 된다. 