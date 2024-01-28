# UserDefaults

## UserDefaults란?

공식 문서에서 `UserDefaults`를

```
앱을 실행하는 동안 지속적으로 키-값 쌍을 저장하는 사용자의 기본 데이터베이스에 대한 인터페이스
```

이렇게 설명하고있다.

`UserDefaults`는 런타임 환경에서 동작하고, 앱이 실행되는 동안 기본 데이터베이스에 접근해 `key-value`의 형태로 데이터를 기록하거나 가져온다.

***

## UserDefaults는 어디에 저장될까?

우리가 iOS에 앱을 설치하면 앱이 실행되는 시점에 데이터를 저장할 수 있는 기본 데이터베이스가 생성된다.

기본 데이터베이스는 `Property List`를 기반으로 하며, `.plist` 파일에 `xml` 형식으로 데이터가 저장된다.

기본 데이터베이스인 `plist` 파일은 `SandBox` 내의 `Bundle Container`에 저장된다

`plist` 파일이 `SandBox` 내에 존재하기 때문에, 앱을 꺼도 데이터가 유지되며 앱을 삭제한 경우에만 해당 파일에 저장한 데이터가 제거된다.

때문에 `UserDefaults`를 사용할 때는 대용량의 데이터나 사용자 정보같은 데이터 보다 자동로그인 여부, 아이디 저장, 알림 설정 여부 등과 같은 단일 데이터를 저장한다.

***

## 저장법
### UserDefaults.standard

싱글톤 인스턴스로, 공유된 기본 값 객체를 반환하는 함수이다.

```swift
let defaults = UserDefaults.stand
```

### 데이터 저장하기

데이터를 저장할 때는 `set` 메서드를 사용한다.

```swift
defaults.set("value", forkey: "key")
```

이때, **key 값은 항상 String** 이어야 한다.

String 외에도 Float, Int, Bool, URL 등의 타입을 저장할 수 있다.

nil값을 저장하면 해당 데이터를 지우는 것과 동일한 효과다. 필요없다면 nil을 넣어버리자

### 데이터 가져오기

저장한 데이터를 꺼내올 때는 타입에 맞게 가져와야 한다.

```swift
let data1 = defaults.object(forkey: "key") as! String
let data2 = defaults.string(forkey: "key")
```

타입을 신경쓰지 않고 꺼낸 뒤 올바른 타입으로 타입캐스팅을 해주거나, 타입에 맞는 메서드를 사용한다.

### 전체 데이터 가져오기

기본 데이터베이스에 저장되어 있는 모든 key-value 쌍을 가져올 때 `dictionaryRepresentation()` 메서드를 사용한다.

```swift
let defaults = UserDefaults.standard

for (key, value) in defaults.dictionaryRepresentation() {
   print("\\(key): \\(value)")
 }

_ = defaults.dictionaryRepresentation().map {
		print("\\($0.key): \\($0.value)")
}

defaults.dictionaryRepresentation().forEach{ 
		print("\\($0.key): \\($0.value)") 
}
```

기본 데이터베이스 내의 모든 key 또는 value만 보고 싶을 때는 밑과 같이 하면 된다.

```swift
defaults.dictionaryRepresentation().keys
defaults.dictionaryRepresentation().values
```

***

## 사용자 정의 타입 저장하기

앞에서 알아본 바로는 굉장히 다양한 타입을 저장할 수 있다. 

하지만 구조체나 클래스의 인스턴스 등 사용자 정의 타입의 경우에는 직접 바꾸어야 한다.

***

### 💡 구조체를 그냥 저장하면 안될까?

UserDefaults는 Data 형을 따르는데, 이 Data 타입은 Base64 인코딩 형식을 따른다.

즉, 저장할 객체는 모두 Base64 인코딩을 거쳐야 한다.

기본 타입인 Int, String 등은 UserDefaults를 사용할 때 내부적으로 적용되지만, 구조체 같은 경우에는 직접 변환해야 한다.

***

### 무지성 돌격하기
첫번째 방법은 바로 `그냥 바꿔 넣기`이다

```swift
let data = self.diaryList.map {
	[
    	"uuidString": $0.uuid,
        "title": $0.title,
        "contents": $0.contents,
	]
}
        
let userDefaults = UserDefaults.standard
userDefaults.set(data, forKey: "diaryList")
```

이런 식으로 직접 매핑하여 넣는 방식이다

### JSONEncoder/Decoder
두번쨰는 `JSONEncoder/Decoder`를 사용해 객체를 저장 가능한 바이너리 타입으로 인코딩/디코딩해서 사용하는 방법이다.

먼저 구조체를 Codable로 선언한다.

```swift
struct Diary: Codable {
	var uuid: String
    var title: String
    var contents: String
}
```

데이터를 넣은 뒤, JSONEncoder를 사용하여 데이터를 저장한다.

```swift
let diary = Diary(uuid: "uuid", title: "title", contnets: "contents")

let defaults = Userdefaults.standard
let encoder = JSONEncoder()

if let encodeData = try? encoder.encode(diary) {
	defaults.set(encodeData, forkey: "diary)
}
```

데이터를 불러올 때는 JsonDecoder()를 사용한다.

```swift
let decoder = JSONDecoder()

if let data = defaults.object(forkey: "diary") as? Diary {
	if let decodeData = try? decoder.decode(Diary.self, from: data) {
    	print(decodeData)
    }
}
```