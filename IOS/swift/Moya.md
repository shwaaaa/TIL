# Moya

## Moya란?

iOS에서 네트워킹을 구현하는 가장 기본적인 방법은 `URLSession`을 사용하는 것이다

그치만 사용이 복잡하고 코드의 가독성이 좋지 않다는 단점이 있다

그걸 보완한게 바로 `Alamofire`

한번쯤 들어봤을법한 `Alamofire` 는 `URLSession` 을 추상화하여 보기 쉬운 형태로 네트워킹을 제공한다

그치만 유지보수와 유닛 테스트가 힘들다는 단점이 있다

그래서 등장한 `Moya`는 `URLSession`을 추상화한 `Alamofire`를 다시 추상화한 프레임워크로 `Network Layer`를 템플릿화 해서 재사용성을 높히고, 개발자가 `request`, `response`에만 신경을 쓰도록 해준다

***

## Moya의 장점

`Moya` 깃허브에서 설명하듯 장점으로는

- 컴파일시 API 엔드 포인트가 올바른지 체크
- `Enum`을 이용해서 언제, 어디에 사용될지 안전하게 (type-safe) 정의
- 유닛 테스트를 용이하게 만듦
- enum 을 활용해서 좀 더 안전한 방식으로 캡슐화된 요청을 보낼 수 있다
- API 추가/삭제가 편리

또 기존 구조의 문제점으로 크게 3가지를 제시하고 있는데 
> - 어디서 부터 시작할지 시작의 어려움
> - 유지보수의 어려움
> - 유닛 테스트 작성의 어려움

`Moya` 를 사용해서 깔끔한 네트워크 계층 구조를 갖게 하고, `Moya` 계층을 템플릿화하여 재사용할 수 있게 한다.

***

## 사용방법

1. API 목록 작성

`Enum` 을 사용해서 사용할 API 목록을 작성해준다.

```swift
enum UserAPI {
    case LogIn(oAuthProvider : OAuthProvider, accessToken : String)
    case refreshToken
}
```

***

2. TargetType 작성

`enum`으로 작성한 API 목록을 `extension` 할건데, `TargetType` 프로토콜을 `Conform` 하여 API 별로 리퀘스트에 필요한 것들을 지정할 수 있다.

**TargetType**
- baseURL : Server base URL 지정

- path : API Path 지정
> - (/users, /documents, ...)

- method : HTTP Method 지정
> - (GET, POST, ...)

- sampleData : Mock Data for Test
> - 테스트용 Mock Data

- task : Parameters for request 지정
> - request에 사용될 파라미터

- validationType : 허용할 response 정의
> - 기존 Alamofire 의 .validate() 처럼 리스폰스의 StatusCode 에 따라 성공 유무를 판단

- headers : HTTP headers 적용
: 기존의 인터셉터의 Adapter 역할을 할 수 있습니다. (ex. 헤더에 JWT 값 넣기)
> - HTTP Header

`Switch문`을 활용해서 간편하게 여러 타입의 API 에 대한 값들을 지정할 수 있고, 필요없는 파라미터는 `Wild Card 구문 (_)`을 사용해서 표현
