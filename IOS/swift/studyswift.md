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

**옵셔널 바인딩 (Optional Binding)**
그럼 옵셔널의 값을 가져오고 싶은 경우에는 어떻게 하면 될까? 이 때 사용하는 것이 바로 옵셔널 바인딩Optional Binding

옵셔널 바인딩은 옵셔널의 값이 존재하는지를 검사한 뒤, 존재한다면 그 값을 다른 변수에 대입시켜준다. if let 또는 if var를 사용하는데요. 옵셔널의 값을 벗겨서 값이 있다면 if문 안으로 들어가고, 값이 nil이라면 그냥 통과하게 된다.

예를 들어, 아래의 코드에서 optionalEmail에 값이 존재한다면 email이라는 변수 안에 실제 값이 저장되고, if문 내에서 그 값을 사용할 수 있다. 만약 optionalEmail이 nil이라면 if문이 실행되지 않고 넘어간다.
```
if let email = optionalEmail {
  print(email) // optionalEmail의 값이 존재한다면 해당 값이 출력
}
// optionalEmail의 값이 존재하지 않는다면 if문을 그냥 지나친다.
```

하나의 if문에서 콤마(,)로 구분하여 여러 옵셔널을 바인딩할 수 있다. 이곳에 사용된 모든 옵셔널의 값이 존재해야 if문 안으로 진입한다.
```
var optionalName: String? = "전수열"
var optionalEmail: String? = "devxoul@gmail.com"

if let name = optionalName, email = optionalEmail {
  // name과 email 값이 존재
}
```
> Tip: 코드가 너무 길 경우에는, 이렇게 여러 줄에 걸쳐서 사용하는 것이 바람직하다.
>if let name = optionalName,
>  let email = optionalEmail {
>  // name과 email 값이 존재
>}
>참고로, 두 번째 let 부터는 생략이 가능.

위 코드는 아래 코드와 동일
```
if let name = optionalName {
  if let email = optionalEmail {
    // name과 email 값이 존재
  }
}
```
>Tip: 한 번의 if문에서 여러 옵셔널을 바인딩할 수 있게 된 것은 Swift 1.2 버전부터입니다. 이전 버전까지는 바로 위와 같이 여러 번으로 감싸진 옵셔널 바인딩을 사용했습니다.

옵셔널을 바인딩할 때 ,를 사용해서 조건도 함께 지정할 수 있다. , 이후의 조건절은 옵셔널 바인딩이 일어난 후에 실행된다. 즉, 옵셔널이 벗겨진 값을 가지고 조건을 검사하게 된다.
```
var optionalAge: Int? = 22

if let age = optionalAge, age >= 20 {
  // age의 값이 존재하고, 20 이상입니다.
}
```

위 코드는 아래 코드와 동일합니다.
```
if let age = optionalAge {
  if age >= 20 {
    // age의 값이 존재하고, 20 이상입니다.
  }
}
```

**옵셔널 체이닝 (Optional Chaining)**
Swift 코드를 간결하게 만들어주는 많은 요소들이 있는데, 옵셔널 체이닝Optional Chaining을 알게되면 다른 프로그래밍 언어가 조금 불편하게 느껴지는 경우가 생긴다.

옵셔널 체이닝을 이해하는 데에는 설명보다 코드를 보는 편이 훨씬 좋다. 예컨대, 옵셔널로 선언된 어떤 배열을 떠올려보자. 이 배열이 '빈 배열'인지를 검사하려면 어떻게 해야 할까? nil이 아니면서 빈 배열인지를 확인해보면 될 것이다. 이렇게
```
let array: [String]? = []
var isEmptyArray = false

if let array = array, array.isEmpty {
  isEmptyArray = true
} else {
  isEmptyArray = false
}

isEmptyArray
```

옵셔널 체이닝을 사용하면 이 코드를 더 간결하게 쓸 수 있습니다.
```
let isEmptyArray = array?.isEmpty == true
```

옵셔널 체이닝은 옵셔널의 속성에 접근할 때, 옵셔널 바인딩 과정을 ? 키워드로 줄여주는 역할을 한다. 다음과 같이 3가지 경우의 수를 생각해보자.

- array가 nil인 경우

  >array?.isEmpty
  >-~~~~~~
  >여기까지 실행되고 `nil`을 반환합니다.
- array가 빈 배열인 경우

  >array?.isEmpty
  >-~~~~~~~~~~~~~~
  >여기까지 실행되고 `true`를 반환합니다.
- array에 요소가 있는 경우

  >array?.isEmpty
  >-~~~~~~~~~~~~~~
  >여기까지 실행되고 `false`를 반환합니다.

array?.isEmpty의 결과로 나올 수 있는 값은 nil, true, false가 된다. isEmpty의 반환값은 Bool인데, 옵셔널 체이닝으로 인해 Bool?을 반환하도록 바뀐 것. 따라서 값이 실제로 true인지를 확인하려면, == true를 해주어야 한다.

**옵셔널 벗기기**
옵셔널을 사용할 때마다 옵셔널 바인딩을 하는 것이 가장 바람직하다. 하지만, 개발을 하다보면 분명히 값이 존재할 것임에도 불구하고 옵셔널로 사용해야 하는 경우가 종종 있는데, 이럴 때에는 옵셔널에 값이 있다고 가정하고 값에 바로 접근할 수 있도록 도와주는 키워드인 !를 붙여서 사용하면 된다.
```
print(optionalEmail) // Optional("devxoul@gmail.com")
print(optionalEmail!) // devxoul@gmail.com
```

!를 사용할 때에는 주의할 점이 있는데, 옵셔널의 값이 nil인 경우에는 런타임 에러가 발생한다는 것입니다. Java의 NullPointerException과 비슷하다고 생각하시면 될 듯 합니다.
```
var optionalEmail: String?
print(optionalEmail!) // 런타임 에러!
```

**암묵적으로 벗겨진 옵셔널 (Implicitly Unwrapped Optional)**
만약, 옵셔널을 정의할 때 ? 대신 !를 붙이면 ImplicitlyUnwrappedOptional이라는 옵셔널로 정의된다. 직역하면 '암묵적으로 벗겨진 옵셔널'
```
var email: String! = "devxoul@gmail.com"
print(email) // devxoul@gmail.com
```

이렇게 정의된 옵셔널은 nil을 포함할 수 있는 옵셔널이긴 한데, 접근할 때 옵셔널 바인딩이나 옵셔널을 벗기는 과정을 거치지 않고도 바로 값에 접근할 수 있다는 점에서 일반적인 옵셔널과 조금 다르다.

옵셔널 벗기기와 마찬가지로, 값이 없는데 접근을 시도하면 런타임 에러가 발생한다.
```
var email: String!
print(email) // 런타임 에러!
```

***

**함수와 클로저**
-----

함수는 func 키워드를 사용해서 정의. **->** 를 사용해서 함수의 반환 타입을 지정
```
func hello(name: String, time: Int) -> String {
  var string = ""
  for _ in 0..<time {
    string += "\(name)님 안녕하세요!\n"
  }
  return string
}
```

Swift에서는 독특하게 함수를 호출할 때 파라미터 이름을 함께 써주어야 한다
```
hello(name: "전수열", time: 3)
```

만약, 함수를 호출할 때 사용하는 파라미터 이름과 함수 내부에서 사용하는 파라미터 이름을 다르게 사용하고 싶으면 이렇게 할 수 있다
```
func hello(to name: String, numberOfTimes time: Int) {
  // 함수 내부에서는 `name`과 `time`을 사용합니다.
  for _ in 0..<time {
    print(name)
  }
}

hello(to: "전수열", numberOfTimes: 3) // 이곳에서는 `to`와 `numberOfTimes`를 사용합니다.
```

파라미터 이름을 _로 정의하면 함수를 호출할 때 파라미터 이름을 생략할 수 있게 된다.
```
func hello(_ name: String, time: Int) {
  // ...
}

hello("전수열", time: 3) // 'name:' 이 생략되었습니다.
```

파라미터에 기본 값을 지정할 수도 있다. 기본 값이 지정된 파라미터는 함수 호출시 생략 가능
```
func hello(name: String, time: Int = 1) {
  // ...
}

hello("전수열")
```

...을 사용하면 개수가 정해지지 않은 파라미터Variadic Parameters를 받을 수 있음
```
func sum(_ numbers: Int...) -> Int {
  var sum = 0
  for number in numbers {
    sum += number
  }
  return sum
}

sum(1, 2)
sum(3, 4, 5)
```

함수 안에 함수를 또 작성할 수도 있음
```
func hello(name: String, time: Int) {
  func message(name: String) -> String {
    return "\(name)님 안녕하세요!"
  }

  for _ in 0..<time {
    print(message(name: name))
  }
}
```

심지어 함수 안에 정의한 함수를 반환할 수도 있다.
```
func helloGenerator(message: String) -> (String) -> String {
  func hello(name: String) -> String {
    return name + message
  }
  return hello
}

let hello = helloGenerator(message: "님 안녕하세요!")
hello("전수열")
```

여기서 핵심은, helloGenerator() 함수의 반환 타입이 (String) -> String라는 것!! 즉, helloGenerator()는 '문자열을 받아서 문자열을 반환하는 함수'를 반환하는 함수인 것

만약 helloGenerator() 안에 정의한 hello() 함수가 여러개의 파라미터를 받는다면 이렇게 써야 한다
```
func helloGenerator(message: String) -> (String, String) -> String {
  func hello(firstName: String, lastName: String) -> String {
    return lastName + firstName + message
  }
  return hello
}

let hello = helloGenerator(message: "님 안녕하세요!")
hello("수열", "전")
```
>(String) -> String이 (String, String) -> String으로 바뀌었다. 문자열 두 개를 받아서 문자열을 반환하는 의미

**클로저(closer)**
------

클로저Closure를 사용하면 바로 위에 작성한 코드를 조금 더 간결하게 만들 수 있다. 클로저는 중괄호({})로 감싸진 '실행 가능한 코드 블럭'
```
func helloGenerator(message: String) -> (String, String) -> String {
  return { (firstName: String, lastName: String) -> String in
    return lastName + firstName + message
  }
}
```

함수와는 다르게 함수 이름 정의가 따로 존재하지 않는다. 하지만 파라미터를 받을 수 있고, 반환 값이 존재할 수 있다는 점에서 함수와 동일. **함수는 이름이 있는 클로저**

클로저는 중괄호({})로 감싸져있다. 그리고 파라미터를 괄호로 감싸서 정의. 함수와 마찬가지로 ->를 사용해서 반환 타입을 명시. 조금 다른 점은 in 키워드를 사용해서 파라미터, 반환 타입 영역과 실제 클로저의 코드를 분리하고 있다.
```
{ (firstName: String, lastName: String) -> String in
  return lastName + firstName + message
}
```

클로저의 장점은 사실 간결함와 유연함에 있다. 바로 위에서 작성한 코드는 이해를 돕기 위해 생략가능한 것들을 하나도 생략하지 않고 모두 적었기 때문에 조금 복잡해보일 수 있다. 이제 하나씩 생략해자

Swift 컴파일러의 타입 추론 덕분에, helloGenerator() 함수에서 반환하는 타입을 가지고 클로저에서 어떤 파라미터를 받고 어떤 타입을 반환하는지를 알 수 있다. 과감하게 생략해버림.
```
func helloGenerator(message: String) -> (String, String) -> String {
  return { firstName, lastName in
    return lastName + firstName + message
  }
}
```

여기서 생략할 수 있는게 더 있다. 마찬가지로 타입 추론 덕분에 첫 번째 파라미터가 문자열이고, 두 번째 파라미터도 문자열이라는 것을 알 수 있다. 첫 번째 파라미터는 $0, 두 번째 파라미터는 $1로 바꿔서 쓸 수 있다.
```
func helloGenerator(message: String) -> (String, String) -> String {
  return {
    return $1 + $0 + message
  }
}
```

클로저 내부의 코드가 한 줄이라면, return까지도 생략해버릴 수 있다!!!!!
```
func helloGenerator(message: String) -> (String, String) -> String {
  return { $1 + $0 + message }
}
```
처음에 작성했던 helloGenerator() 함수의 코드가 4줄이었는데 클로저를 사용하면서 3줄로 줄어들었고, 클로저에서 불필요한 부분을 생략하면서 달랑 1줄로 줄어들었다.

클로저는 변수처럼 정의할 수 있습니다.
```
let hello: (String, String) -> String = { $1 + $0 + "님 안녕하세요!" }
hello("수열", "전")
```

물론 옵셔널로도 정의할 수 있다. 옵셔널 체이닝도 가능
```
let hello: ((String, String) -> String)?
hello?("수열", "전")
```

클로저를 변수로 정의하고 함수에서 반환할 수도 있는 것처럼, 파라미터로도 받을 수 있다.
```
func manipulate(number: Int, using block: Int -> Int) -> Int {
  return block(number)
}

manipulate(number: 10, using: { (number: Int) -> Int in
  return number * 2
})
```

아까 했던 것처럼, 생략도 가능
```
manipulate(number: 10, using: {
  $0 * 2
})
```

만약 함수의 마지막 파라미터가 클로저라면, 괄호와 파라미터 이름마저 생략해버릴 수 있다
```
manipulate(number: 10) {
  $0 * 2
}
```

이런 구조로 만들어진 예시가 바로 sort()와 filter()이다. 함수가 클로저 하나만을 파라미터로 받는다면, 괄호를 아예 쓰지 않아도 된다
```
let numbers = [1, 3, 2, 6, 7, 5, 8, 4]

let sortedNumbers = numbers.sort { $0 < $1 }
print(sortedNumbers) // [1, 2, 3, 4, 5, 6, 7, 8]

let evens = numbers.filter { $0 % 2 == 0 }
print(evens) // [2, 6, 8, 4]
```

**클로저 활용하기**
----

클로저는 Swift의 굉장히 많은 곳에서 사용된다. 바로 위에서 예시를 든 것처럼 sort()나 filter()와 같은 배열에 많이 쓰인다. 대표적인 메서드로는 sort(), filter(), map(), reduce()가 있다. sort()와 filter()는 바로 위에서 써봤으니 map()과 reduce()에 대해서 살펴보자

map()은 파라미터로 받은 클로저를 모든 요소에 실행하고, 그 결과를 반환. 예를 들어, 정수 배열의 모든 요소들에 2를 더한 값으로 이루어진 배열을 만들고 싶다면, 이렇게 작성할 수 있다.
```
let arr1 = [1, 3, 6, 2, 7, 9]
let arr2 = arr1.map { $0 * 2 } // [2, 6, 12, 4, 14, 18]
```

reduce()는 초깃값이 주어지고, 초깃값과 첫 번째 요소의 클로저 실행 결과, 그리고 그 결과와 두 번째 요소의 클로저 실행 결과, 그리고 그 결과와 세 번째 요소의 클로저 실행 결과, ... 끝까지 실행한 후의 값을 반환. 바로 위에서 정의한 arr1의 모든 요소의 합을 구하고 싶다면, 아래와 같이 작성할 수 있다.
```
arr1.reduce(0) { $0 + $1 } // 28
````

