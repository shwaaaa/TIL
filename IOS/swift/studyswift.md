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

***

**조건문과 반복문**
-------

조건을 검사할 때에는 if, switch를 쓴다. 아래 코드는 if를 사용한 예시
```
var age = 19
var student = ""

if age >= 8 && age < 14 {
  student = "초등학생"
} else if age < 17 {
  student = "중학생"
} else if age < 20 {
  student = "고등학생"
} else {
  student = "기타"
}

student // 고등학생
```

if문의 조건절에는 값이 정확하게 참 혹은 거짓으로 나오는 Bool 타입을 사용해야한다. 위에서 언급한 것과 같이 Swift에서는 타입 검사를 굉장히 엄격하게 하기 때문에, 다른 언어에서 사용 가능한 아래와 같은 코드를 사용하지 못한다.
```
var number = 0
if !number { // 컴파일 에러!
  // ...
}
```

대신, 이렇게 쓴다.
```
if number == 0 {
  // ...
}
```

빈 문자열이나 배열 등을 검사할 때에도 명확하게 길이가 0인지를 검사해야 한다.
```
if name.isEmpty { ... }
if languages.isEmpty { ... }
```

Swift의 switch 구문은 조금 특별하다. 패턴 매칭이 가능하기 때문! 아래 코드는 위에서 작성한 if문을 switch문으로 옮긴 것
```
switch age {
case 8..<14:
  student = "초등학생"
case 14..<17:
  student = "중학생"
case 17..<20:
  student = "고등학생"
default:
  student = "기타"
}
```

8..<14와 같이 범위Range 안에 age가 포함되었는지 여부를 검사할 수 있다.
반복되는 연산을 할 때에는 for, while을 쓴다. for 구문을 사용해서 배열과 딕셔너리를 차례로 순환할 때에는 아래와 같이 씀
```
for language in languages {
  print("저는 \(language) 언어를 다룰 수 있습니다.")
}

for (country, capital) in capitals {
  print("\(country)의 수도는 \(capital)입니다.")
}
```

단순한 반복문을 만들고 싶다면 범위를 만들어서 반복시킬 수도 있다. 아래 예시는 1강에서 Playground를 만들고 가장 먼저 입력했던 코드
```
for i in 0..<100 {
  i
}
```

만약 i를 사용하지 않는데 단순한 반복을 하고 싶다면, i 대신 _를 사용해서 무시할 수도 있다.
```
for _ in 0..<10 {
  print("Hello!")
}
```

-키워드는 어디서나 변수 이름 대신에 사용할 수 있다.
while은 조건문의 값이 true일 때 계속 반복된다.
```
var i = 0
while i < 100 {
  i += 1
}
```

***

**옵셔널 (Optional)**
---------

Swift가 가지고 있는 가장 큰 특징 중 하나가 바로 옵셔널(Optional)이다. 직역하면 '선택적인' 이라는 뜻이 되는데, 값이 있을 수도 있고 없을 수도 있는 것을 나타낸다.

문자열의 값이 있으면 "가나다"가 될 것이다. 그럼, 값이 없다면 ""일까? 땡. ""도 엄연히 값이 있는 문자열이다. 정확히는 '값이 없다'가 아니고 '빈 값'!! 값이 없는 문자열은 바로 nil이다.

정수형의 값이 있으면 123과 같은 값이 있을 것이다. 값이 없다면 0일까? 마찬가지로 0은 0이라는 숫자 '값'이다. 이 경우에도 값이 없는 정수는 nil

마찬가지로, 빈 배열이나 빈 딕셔너리라고 해서 '값이 없는'것이 아니다. 다만 '비어 있을' 뿐. 배열과 딕셔너리의 경우에도 '없는 값'은 nil이다.

이렇게, 값이 없는 경우를 나타낼 때에는 nil을 사용한다. 그렇다고 해서 모든 변수에 nil을 넣을 수 있는 것은 아니다. 예로, 우리가 위에서 정의한 name이라는 변수에 nil을 넣으려 하면 에러가 발생한다.
```
var name: String = "전수열"
name = nil // 컴파일 에러!
```

값이 있을 수도 있고 없을 수도 있는 변수를 정의할 때에는 타입 어노테이션에 ?를 붙여야 한다. 이렇게 정의한 변수를 바로 옵셔널Optional이라고 한다. 옵셔널에 초깃값을 지정하지 않으면 기본값은 nil.
```
var email: String?
print(email) // nil

email = "devxoul@gmail.com"
print(email) // Optional("devxoul@gmail.com")
```

옵셔널로 정의한 변수는 옵셔널이 아닌 변수와는 다릅니다. 예를 들어, 아래와 같은 코드는 사용할 수 없습니다.
```
let optionalEmail: String? = "devxoul@gmail.com"
let requiredEmail: String = optionalEmail // 컴파일 에러!
```

requiredEmail 변수는 옵셔널이 아닌 String이기 때문에 항상 값을 가지고 있어야 한다. 반면에, optionalEmail은 옵셔널로 선언된 변수이기 때문에 실제 코드가 실행되기 전까지는 값이 있는지 없는지 알 수 없다. 따라서 Swift 컴파일러는 안전을 위해 requiredEmail에는 옵셔널로 선언된 변수를 대입할 수 없게 만들었다.

옵셔널은 개념적으로 이렇게 표현할 수 있다. 어떤 값 또는 nil을 가지고 있음.
```
        ,-- 어떤 값 (String, Int, ...)
Optional
        `-- nil
```