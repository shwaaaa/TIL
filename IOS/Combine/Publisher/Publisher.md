# Publisher

## Publisher란?
`Publisher`는 하나 혹은 여러 개의 `Subscriber` 객체에 시간의 흐름에 따라 값을 내보낼 수 있는 타입을 선언하기 위한 프로토콜이다.

```swift
protocol Publisher {
    associatedtype Output
    associatedtype Failure : Error
    func receive<S>(subscriber: S) where S : Subscriber, Self.Failure == S.Failure, Self.Output == S.Input
}
```

`Publisher`의 프로토콜을 살펴보면 `Output`, `Failure` 타입이 존재하고 동일한 타입의 `Subscriber`을 `receive` 함수로 연결할 수 있다.
> Output : publisher가 방출하는 값의 종류

> Failure : publisher가 방출할 수 있는 에러의 종류

***

## Convenience Publisher

- Just: 가장 단순한 형태의 `Publsiher`로 에러타입으로 `Never`를 갖는다

- Promise: `Just`와 비슷하지만 `Filter Type`을 정의할 수 있다.

- Fail: 정의된 실패타입을 내보낸다

- Empty: 어떤 데이터도 발행하지 않는 퍼블리셔로 주로 에러처리나 옵셔널값을 처리할때 사용

- Sequence: 데이터를 순차적으로 발행하는 `Publisher`로 `(1…10).Publisher`로 이에 해당

- ObservableObjectPublisher: `SwiftUI`에서 사용되는 `ObservableObject`를 준수하는 퍼블리셔

***

## Just
- 가장 단순한 형태의 `Publisher`
- 에러 타입은 항상 `Never`
```swift
Just((0...5))
  .sink { value in
      print(value) // 0...5
  }
```

***

## Future
일반적으로 `Publishe`r의 처리를 `sink` 라는 구독을 형태로 많이 처리하게 된다. 이 때 클로저를 전달하는 과정에서 콜백 기반의 `completion` 핸들러를 사용하게 되는데 `Futrue`를 통하여 더욱 깔끔한 코드 작성이 가능해 진다.

```swift
let myFuture = Future<Int, Never> { promise in
      promise(.success(10))
  }
  myFuture.sink { value in
      print(value) // 10
  }
```

`URLSeesion` 이나 `Alamofire` 등 `RestFul` 관련 API 비동기 요청시에 해당 요청이 성공했는지, 실패 했는지에 대한 여부를 리턴해주는 예제

```swift
func isSuccessAPIRequest() -> AnyPublisher<Bool, Never> { 
    Future<Bool, Never> { promise in 
        urlRequestPublisher
            .sink(
                receiveCompletion: { completion in 
                    switch completion {
                    case .finished: 
                        print("finished")
                        promise(.success(true))
                    case .failure(let error): print(error.localizedDescription)
                        promise(.success(false))
                    }
                }, receiveValue: { value in
                    print(value)
                }
            )
    }
    .eraseToAnyPublisher()
}

isSuccessAPIRequest()
	.sink { 
		if $0 {
			// true
		} else {
			// false
		}
	}
```

***

## Fail
지정한 종류의 에러로 즉시 종료하는 `Publisher`

***

## Empty
값을 게시하지 않고 선택적으로 즉시 완료되는 `Publisher`

```swift
Empty<String, Never>()
      .sink(
          receiveCompletion: { 
              print($0) // finished
          },
          receiveValue: {
              print("receiveValue : \($0)") // 출력 안함
          }
      )
```

***

## Deferred
- 구독이 일어나기 전까지 대기상태로 있다가 구독이 일어 났을 때 `Publisher`가 결정

- 클로저 안에는 지연 실행 할 `Publisher` 를 반환

```swift
Deferred { Just(Void()) }
  .sink(receiveValue: { print("Diferred") })
```

***

## Sequence
- 요소의 주어진 `Sequence`를 반환하는 `Publisher`
- `Publisher`가 `Sequence`에 있는 요소들을 하나 하나 제공해주며 모든 요소들이 다 제공되었을 때 종료

```swift
Publishers.Sequence<[Int], Never>(sequence: [1, 2, 3])
    .sink(receiveValue: { 
        print("Sequence : \($0)")
    })
/*
 Sequence : 1
 Sequence : 2
 Sequence : 3
 */
```

***

## 간단한 동작 방식

1. 관심있는 값에 구독을 걸고
2. 그 값에 새 이벤트가 발생하면(값이 변경되면)
3. 비동기식으로 이벤트(값)을 전달 받을 수 있다.