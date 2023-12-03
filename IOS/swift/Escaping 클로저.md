# Escaping 클로저

## Escaping 클로저란?

`Escaping 클로저`는 클로저가 함수의 인자로 전달됐을 때, 함수의 실행이 종료된 후 실행되는 클로저이다.

`Non-Escaping 클로저`는 이와 반대로 함수의 실행이 종료되기 전에 실행되는 클로저이다.

***

## Non-Escaping Closure

```swift
func runClosure(closure: () -> Void) {
 closure()
}
```

클로저가 실행되는 순서를 보면

1. 클로저가 runClosure() 함수의 closure 인자로 전달됨
2. 함수 안에서 closure() 가 실행됨
3. runClosure() 함수가 값을 반환하고 종료됨

이렇게 클로저가 함수가 종료되기 전에 실행되기 때문에 closure는 Non-Escaping 클로저이다.

***

## Escaping Closure

```swift
class ViewModel {
    var completionhandler: (() -> Void)? = nil
    
    func fetchData(completion: @escaping () -> Void) {
        completionhandler = completion
    }
}
```

클로저가 실행되는 순서를 보면

1. 클로저가 fetchData() 함수의 completion 인자로 전달됨
2. 클로저 completion이 completionhandler 변수에 저장됨
3. fetchData() 함수가 값을 반환하고 종료됨
4. 클로저 completion은 아직 실행되지 않음

completion은 함수의 실행이 종료되기 전에 실행되지 않기 때문에 escaping 클로저, 다시말해 함수 밖(escaping)에서 실행되는 클로저이다.

***

## Non-Escaping Closure 와 Escaping Closure

@escaping이 붙어 있어도 다음과 같이 non-escaping 클로저를 인자로 넣을 수 있다.

```swift
func runClosure(closure: @escaping () -> Void) {
 closure()  // ✅ closure는 non-escaping 클로저이지만 @escaping 사용 가능
}
```

반대로 escaping 클로저를 @escaping 없이 사용할 수 없다.

```swift
class ViewModel {
    var completionhandler: (() -> Void)? = nil
    
    func fetchData(completion: () -> Void) { // ❗️@escaping 누락으로 컴파일 에러 발생!
        completionhandler = completion
    }
}
```

***

## 주의사항

`@escaping` 키워드가 붙은 파라미터에 `non-escaping` 클로저를 전달할 수 있지만

`@escaping` 키워드가 붙지 않은 파라미터에 `escaping` 클로저를 전달할 수는 없다.

***

## 그렇다면 언제 사용할까?

### 비동기 작업에서 사용

주로 비동기 작업에서 사용

비동기 함수는 클로저를 인자로 받아 작업을 완료했을 때 클로저를 호출하는데, 이때 클로저가 함수를 벗어날 수 있다.
```swift
func fetchData(completion: @escaping (Result<Data, Error>) -> Void) {
    // 비동기 작업 후
    // completion 클로저를 호출
    DispatchQueue.main.async {
        completion(.success(data))
    }
}
```

### 콜백으로 사용할 때

API 요청이나 데이터베이스 쿼리와 같이 완료 콜백이나 처리 클로저를 사용할 때, 해당 클로저가 함수 완료 후 호출될 가능성이 있다.
```swift
func performNetworkRequest(completion: @escaping (Result<String, Error>) -> Void) {
    // 네트워크 요청 후
    // completion 클로저를 호출
    completion(.success(response))
}
```

### Delegate 패턴에서

delegate 패턴을 사용할 때, 즉 다른 객체에게 특정 이벤트가 발생했음을 알리기 위해 클로저를 사용할 때, 해당 클로저가 함수를 벗어날 수 있다.
```swift
protocol SomeDelegate: AnyObject {
    func didReceiveData(data: String)
}

class DataManager {
    weak var delegate: SomeDelegate?

    func fetchData() {
        // 데이터를 가져온 후
        delegate?.didReceiveData(data: result)
    }
}
```

`@escaping` 키워드는 기본적으로 `Swift`에서는 클로저가 함수의 스코프 내에서 완료되는 것으로 기대되기 때문에 명시적으로 `@escaping`을 사용하여 클로저가 함수의 범위를 벗어날 수 있음을 나타낸다

이는 메모리 관리나 비동기 작업 등에서 중요한 역할을 한다.