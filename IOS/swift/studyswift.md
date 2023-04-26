**이름짓기규칙**
------
함수나 메서드,상수 같은 것들은 소문자로 시작하는 camel case 사용
>- Lower Camel Case : fuction, method, variable, constant
>ex)someVariableName

>- class나 구조체, 열거형, extentionrkxdms 같은 타입 이름은 대문자로 시작하는 camel case 사용
>ex)Person,Point,Week

***

**콘솔로그**
--------------

- print
> 단순 문자열 출력
- dump
> 인스턴스의 자세한 설명(description 프로퍼티)까지 출력

***

**변수와 상수**
----

변수(variable)는 값을 수정할 수 있고, 상수(constant)는 그렇지 않다. Swift에서는 언제 어디서 값이 어떻게 바뀔지 모르는 변수보다는 상수를 사용하는 것을 권장하고 있다.

상수 선언 키워드 **let**
변수 선언 키워드 **var**
```
var name = "seunghwa"
let birthyear = 1995

```
나중에 이름을 바꾸고싶다면 바꾸기 가능
```
name = "승화"
```

태어난 해 바꾸긴 불가능
```
birthyear = 2000 // 컴파일 에러!
```

Swift는 정적 타이핑 언어입니다. 말이 어려운데요. 변수나 상수를 정의할 때 그 자료형(타입)이 어떤 것인지를 명시해주어야 하는 언어를 말해요. 예를 들면

```
var name: String = "seughwa"
let birthyear: Int = 2007
var height: Float = 200
```

name은 String이고, birthyear는 Int고, height은 Float 타입
이렇게 변수 또는 상수 이름 뒤에 콜론(:)을 붙이고 자료형을 써주면 된다

Swift에서는 타입을 굉장히 엄격하게 다루기 때문에, 다른 자료형끼리는 기본적인 연산조차 되지 않는다. 아래와 같이 Int 타입인 birthyear와 Float 타입인 height을 더하려고 하면 컴파일 에러가 발생
```
birthyear + height // 컴파일 에러!
```

이럴 때에는 명확하게 다음과 같이 사용
```Float(birthyear) + height // 22207
```

숫자를 문자열로
```
String(birthyear) + "년에 태어난 " + name + "야 안녕!" // 2007년에 태어난 승화야 안녕!
```

더 간단하게 나타내기
```
"\(birthyear)년에 태어난 \(name)야 안녕!" // 2007년에 태어난 승화야 안녕!
```

**타입추론**
Swift 컴파일러도 마찬가지로, 큰 따옴표(")로 감싸진 텍스트는 String 타입인 것을 알고, 숫자는 Int 타입인 것을 인식할 수 있다. 이렇게 타입을 직접 명시하지 않고도 값을 가지고 정적 타이핑을 할 수 있게 해주는 것을 타입 추론(Type Inference)이라고 합니다.

**배열과 딕셔너리**

배열과 딕셔너리는 모두 대괄호([])를 이용해서 정의할 수 있다.
```
var languages = ["Swift", "Objective-C", "Python"]
var capitals = [
  "한국": "서울",
  "일본": "도쿄",
  "중국": "베이징",
]
```

배열과 딕셔너리에 접근하거나 값을 변경할 때에도 대괄호를 사용한다.
```
languages[0] // Swift
languages[1] = "Ruby"

capitals["한국"] // 서울
capitals["프랑스"] = "파리"
```
**다른 상수와 마찬가지로 배열과 딕셔너리를 let으로 정의하면 값을 수정할 수 없습니다. 물론 값을 추가하거나 빼는 것도 불가능**

위에서 정의해본 languages와 capitals의 타입은 어떻게 쓸 수 있을까? 이번에도 대괄호를 쓴다. 대신, 대괄호 안에 어떤 타입을 받을 것인지를 명시
```
var languages: [String] = ["Swift", "Objective-C", "Python"]
var capitals: [String: String] = [
  "한국": "서울",
  "일본": "도쿄",
  "중국": "베이징",
]
```

만약 빈 배열이나 빈 딕셔너리를 정의하고 싶다면? 이번에도 또 대괄호를 씀. 배열과 딕셔너리는 대괄호로 시작해서 대괄호로 끝나는 친구들
```
var languages: [String] = []
var capitals: [String: String] = [:]
```

빈 배열로 선언하는 것을 조금 더 간결하게 하고싶다면
```
var languages = [String]()
var capitals = [String: String]()
```