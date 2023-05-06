**Enum**
- **열거**라는 뜻을 가진 Enumeration에서 따온 용어입니다. 한글로 번역할 때에는 열거형이라는 말을 많이 사용합니다. 1월부터 12월까지를 enum으로 한 번 정의해볼까요?
```swift
enum Month: Int {
  case january = 1
  case february
  case march
  case april
  case may
  case june
  case july
  case august
  case september
  case october
  case november
  case december

  func simpleDescription() -> String {
    switch self {
    case .january:
      return "1월"
    case .february:
      return "2월"
    case .march:
      return "3월"
    case .april:
      return "4월"
    case .may:
      return "5월"
    case .june:
      return "6월"
    case .july:
      return "7월"
    case .august:
      return "8월"
    case .september:
      return "9월"
    case .october:
      return "10월"
    case .november:
      return "11월"
    case .december:
      return "12월"
    }
  }
}

let december = Month.december
print(december.simpleDescription()) // 12월
print(december.rawValue)            // 12
```

- 위 예시에서 작성한 Month는 Int를 원시값Raw Value으로 가지도록 정의되었습니다. 그렇기 때문에 각 케이스들은 1부터 12까지의 값을 가지고 있습니다. rawValue 속성이 바로 그 값을 나타내는데요. 반대로, 원시값을 가지고 Enum을 만들 수도 있습니다.
```swift
let october = Month(rawValue: 10)
print(october) // Optional(Month.october)
```
> - Month(rawValue:)의 반환값이 옵셔널인 이유는, Enum에서 정의되지 않은 원시값을 가지고 생성할 경우 nil을 반환하기 때문입니다.
>```swift
> Month(rawValue: 13) // nil
>```

- 아래 예시는 String을 원시값으로 가지는 Enum입니다.
```swift
enum IssueState: String {
  case open = "open"
  case closed = "closed"
}
```
> - 만약 어떤 API의 응답에서 내려주는 state의 값이 open 또는 closed라면, if-else 없이도 IssueState(rawValue:)를 사용해서 Enum을 생성할 수 있습니다.

- Enum은 원시값을 가지지 않을 수도 있습니다. 원시값을 가져야 할 필요가 없다면 굳이 만들지 않아도 돼요.
```swift
enum Spoon {
  case dirt
  case bronze
  case silver
  case gold

  func simpleDescription() -> String {
    switch self {
    case .dirt:
      return "흙수저"
    case .bronze:
      return "동수저"
    case .silver:
      return "은수저"
    case .gold:
      return "금수저"
    }
  }
}
```

- Enum을 예측할 수 있다면 Enum의 이름을 생략할 수 있습니다.
```swift
let spoon: Spoon = .gold // 변수에 타입 어노테이션이 있기 때문에 생략 가능

func doSomething(with spoon: Spoon) {
  // ...
}
doSomething(with: .silver) // 함수 정의에 타입 어노테이션이 있기 때문에 생략 가능
```

**연관 값 (Associated Values) 을 가지는 Enum**
-------

- Enum은 연관 값(Associated Values)을 가질 수 있습니다. 아래 예시는 어떤 API에 대한 에러를 정의한 것인데요. invalidParameter 케이스는 필드 이름과 메시지를 가지도록 정의되었습니다.
```swift
enum NetworkError {
  case invalidParameter(String, String)
  case timeout
}

let error: NetworkError = .invalidParameter("email", "이메일 형식이 올바르지 않습니다.")
```

- 이 값을 꺼내올 수 있는 방법으로는 if-case 또는 switch를 활용하는 방법이 있습니다.
```swift
if case .invalidParameter(let field, let message) = error {
  print(field) // email
  print(message) // 이메일 형식이 올바르지 않습니다.
}

switch error {
case .invalidParameter(let field, let message):
  print(field) // email
  print(message) // 이메일 형식이 올바르지 않습니다.

default:
  break
}
```

