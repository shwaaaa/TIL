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