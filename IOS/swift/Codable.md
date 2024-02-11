# Codable

## Codable이란?

공식문서에 따르면 `Codable`은 자신을 외부 표현으로 변환(Encode)하거나 외부 표현으로부터 변환(Decode) 할 수 있는 타입으로, `Encodable` & `Decodabl`e로 구성된 유니온 타입(union type)으로 정의할 수 있다.

Codable은 프로토콜 이기 때문에 채택하여 사용하는데, class, struct, enum에 채택 가능하다.

Codable은 `typealis` 형태로 Decodable & Encodable을 묶어놓은 프로토콜이다.
> - typealias : 기존 선언된 데이터 타입에 별칭을 사용함으로서 코드를 더 읽기 쉽도록 만드는 문법
> - Encodable : Swift 데이터 -> 외부 표현으로
> - Decodable : 외부 표현 -> Swift 데이터 

`SwiftyJSON` 같은 라이브러리를 사용하지 않더라도 `Codable`을 사용해서 JSON데이터와 <---> Swift 자료형과 자유자재로 왔다갔다 할 수 있다.

***

## Codable 사용하기

Codable을 사용하려면 

```swift
struct codableDemo {
    var name: String
}
```
이렇게 생긴 구조체에

```swift
struct codableDemo : Codable {
    var name: String
}
```
이렇게 codable 프로토콜을 채택해주면 된다!

***

## Encodable

원하는 형태로 바꾸어줌 (f(x) 함수와 같다) 

-> 자기 자신을 외부 표현으로 encode 할 수 있는 타입

***

## Encode

다음과 같이 JSONEncoder를 통해 JSON 데이터로 쉽게 encode 할 수 있게 된다.

```swift
do {
    let user = User(name: "승황", age: 17)
    let encoder = JSONEncoder()
    let data = try encoder.encode(user)
} catch {
    print("\(error)")
}
```

***

## Decodable

그 형태를 해석해줌(f-1(x) 역함수와 같다)

자기 자신을 외부 표현으로 `decode` 할 수 있는 타입

참고로 `Decodable`을 채택하는 데이터는 `init함수`를 필수적으로 가져야 한다

***

## Decode

- 다음과 같이 JSONDecoder를 통해 JSON 데이터를 쉽게 decode 할 수도 있다.
- 다음 코드를 실행하면 정확히 우리가 넣었던 JSON 데이터가 나올 것이다.

```swift
let decoder = JSONDecoder()
let secondUser = try decoder.decode(User.self, from: data)
```

***

## NSCoding

다이나믹하게 다형성으로 동작하는 방식이 필요한 경우에는 `NSCoding` 프로토콜을 사용하는 것이 권장된다.

`Codable`과 동시에 채택도 가능하다

`required init`과 `encode` 메서드 구현이 필요하다.

***

## NSKeyedArchiver

`NSCoding` 프로토콜을 채택한 객체는 `NSKeyedArchiver`로 인코딩, `NSKeyedUnarchiver`로 디코딩한다.

아카이브 한 결과는 Data 타입이 되고, json 형식은 불가능하다.

json 형식으로 데이터를 전송하려면 UserDefault or Plist 파일을 이용해서 저장하는 방법이 있다

```swift
static func unarchive(with text: Data) -> Any? {
        do {
            let object = try NSKeyedUnarchiver.unarchiveTopLevelObjectWithData(text)
            return object
        }
        catch {
            print(error)
        }
        return nil
    }
    
    static func archive<T>(with things: T) -> Data {
        do {
            let archived = try NSKeyedArchiver.archivedData(withRootObject: things, requiringSecureCoding: false)
            return archived
        }
        catch {
            print(error)
        }
        return Data()
    }
```

***

## CodingKey

`codingKey`란?

만약 우리의 User 데이터가
```swift
struct User: Codable {
    var userName: String
    var userEmail: String
}
```

jsonData 형태
```swift
{
"user_name" : "shwaaaa",
"user_email": "qwer@gmail.com"
}
```
으로 되어있을때

이 jsonData를 User 데이터 타입으로 decode하게 될시 key 값의 이름이 같지 않기 때문에 에러가 나게된다.

이를 위해 codingKey라는 protocol이 존재한다.

codingKey는 인코딩 및 디코딩을 위한 키로 사용할 수 있는 타입으로 

enum을 사용해 codingKey 프로토콜을 채택하게 하는것이다

따라서 우리가 기존에 세웠던 User struct는

```swift
struct User: Codable {
	var userName: String
	var userEmail: String
}

//codingKey 추가
struct User: Codable {
	var userName: String
	var userEmail: String

	enum CodingKeys: String, CodingKey {
	    case userName = "user_name"
	    case userEmail = "user_email"
	}
}
```