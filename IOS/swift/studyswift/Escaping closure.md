# Escaping 클로저

## Escaping 클로저란?

- `scaping 클로저`는 클로저가 함수의 인자로 전달됐을 때, 함수의 실행이 종료된 후 실행되는 클로저이다.

- `Non-Escaping` 클로저는 이와 반대로 함수의 실행이 종료되기 전에 실행되는 클로저

***

## Non-Escaping Closure

```swift
func runClosure(closure: () -> Void) {
 closure()
}
```

이 코드를 보면

1. 클로저가 `runClosure()` 함수의 `closure` 인자로 전달됨
2. 함수 안에서 `closure()` 가 실행됨
3. `runClosure()` 함수가 값을 반환하고 종료됨

이렇게 클로저가 함수가 종료되기 전에 실행되기 때문에 `closure`는 `Non-Escaping 클로저` 이다!!

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

이 코드를 보면

1. 클로저가 fetchData() 함수의 completion 인자로 전달됨
2. 클로저 completion이 completionhandler 변수에 저장됨
3. fetchData() 함수가 값을 반환하고 종료됨
4. 클로저 completion은 아직 실행되지 않음

`completion`은 함수의 실행이 종료되기 전에 실행되지 않기 때문에 `escaping 클로저`, 다시말해 `함수 밖(escaping)`에서 실행되는 클로저이다.

***

- escaping 클로저는 completion handler, 즉 함수의 결과에 따라 다르게 동작하도록 비동기적 처리를 요구하는 함수에서 활용할 수 있다.

