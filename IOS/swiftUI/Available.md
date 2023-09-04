# Available

## Available이란?

버전을 체크하고 분기처리를 하게 해준다.

***

## Available 사용법
`#available`과 `@available`로 사용할 수 있다.

- `#available`은 조건문과 같이 사용할 때 사용된다!
- 즉, Bool 타입을 반환시켜주니 꼭 조건문과 같이 사용된다.
- *는 필수로 적어줘야한다.
```swift
if #available(iOS 17, *) {
  // 17 이상 버전 코드
}
else {
  // 17 미만 버전 코드
}
```

- `@available`은 조건문과 같이 분기 처리를 할 수 없고, 배포 타겟 버전을 체크한다.
- 즉 아래와 같이 보통 클래스, 프로토콜, 메서드 같은 곳에 붙여 사용
```swift
@available(iOS 17, *)
func example() { }
// 만약 배포 타겟이 17 미만이라면 컴파일 시 에러
```

- 플랫폼 여러개도 가능!
```swift
@available(iOS 10.0, macOS 10.12, *)
func setupDoneButton() { } 
```

***

## @available과 #available의 차이점
- `@available`은 클래스나 메소드의 가용성을 표시하는 데 사용됩니다.

- `#available`은 특정 플랫폼 또는 버전에 대한 코드를 실행하는 데만 사용됩니다.

***

## unavailable
- 지정된 플랫폼에서 사용할 수 없음을 나타낸다.

- 이렇게 선언하면 애플 모든 플랫폼과 버전에서 해당 shwaa 메서드를 사용할 수 없다
```swift
@available(*, unavailable)
func shwaa() { }
```
