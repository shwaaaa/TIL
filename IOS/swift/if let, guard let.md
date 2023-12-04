# if let, guard let

## if vs if let vs guard let

### if

일반적으로 사용되는 if 조건문은 단순히 조건의 값이 true인지 false인지 체크하는 것이다.

```swift
let colors = ["red", "green", "blue"]
 
if colors.contains("red") {
  print("red is present in palette")
} else {
  print("red is not present in palette")
}
```

***

### if let

```swift
let colors = ["red", "green", "blue"]

let index = colors.firstIndex(where: {$0.elementsEqual("green")})

if index != nil {
  print("green is present in palette at position \(index ?? -1)")
} else {
  print("green is not present in palette")
}
```

이렇게 위 예제와 같이  `optional` 타입을 계속 사용하는 경우 조건문 안에서 `optional` 타입을 계속 `unwrapping` 하는 것을 확인할 수 있다.

이를 if let 구문으로 사용하면

```swift
let colors = ["red", "green", "blue"]

if let index = colors.firstIndex(where: {$0.elementsEqual("green")}) {
  print("green is present in palette at position \(index)")
} else {
  print("green is not present in palette")
}
```

변수 index는 원래 `optional` 타입이나 `if let` 구문 안에서는 `non-optional` 타입으로 사용되는 것을 확인할 수 있다.

***

### guard let

`guard let`은 `if let`과 비슷하게 조건의 참 여부와 `optional` 값을 `unwrap` 하는데 사용되나, 조금 다른 점이 있다.

`guard let`은 함수, 루프(반복문), 또는 if 조건문을 탈출(exit)하는 경우에 사용된다.

```swift
func checkColorInPalette() {
  let colors : [String] = ["red", "green", "blue"]

  guard let index = colors.firstIndex(where: {$0.elementsEqual("green")}) else {
    print("green is not present in palette")
    return
  }

  print(print("green is present in palette at position \(index)"))
}

checkColorInPalette()
```

위 예제에서 확인할 수 있듯이, index에 nil이 할당되면 else 구문으로 이동하여 checkColorInPalette 함수를 exit 한다.

***

## if let과 guard let의 차이점

`if let`은 if 조건문에 `optional unwrapping`을 할 수 있는 let 변수를 정의하는 기능을 추가한 것이다.

`guard let`은 `if let`과 비슷하나 실행의 흐름에 초점이 맞춰져 있다. 즉 if 조건이 true가 아닐 때 특정 함수나, 루프 조건 등에서 return, break, 또는 throw(예외)를 처리하는 경우에 적합하다.

`if let`에서 정의된 let 변수는 if 구문 안에서 사용할 수 있지만 if 구문 밖에서는 사용할 수 없다.

`guard let`에서 정의된 let 변수는 else 구문에서는 사용할 수 없지만 else 구문 이후로 사용이 가능하다.