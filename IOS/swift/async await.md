# async/await

## 동기와 비동기

### 동기 (sync)
작업을 동기적(synchronous)으로 실행한다는 것은 무엇을 의미할까?

만약 어떤 작업을 동기적으로 실행한다면, 해당 작업이 끝날 때까지 다른 작업들은 기다린다.

### 비동기 (async)
반면 비동기(asynchronous) 로 작업을 실행한다면?

해당 작업이 끝나든 말든 신경 쓰지 않고 나머지 작업을 바로 실행한다.

그래서 이미지 다운로드나 네트워킹 등 작업 시간이 오래걸리는 것들은 비동기로 처리하는게 일반적인 방식이었다.

이때 일을 비동기로 보내놓으면 실제 해당 작업이 언제 끝나는지는 어떻게 알까?

Swift에서는 클로저를 통해 해당 시점을 알려준다.

바로 `completionHandler`로!

### 비동기 작업의 completionHandler 사용 문제점

![image](https://miro.medium.com/v2/resize:fit:1400/format:webp/1*vHoVZgIFNRumlWPj07XbQw.png)

다음과 같은 코드는 네트워크를 요청하고 데이터 받아왔을때 `completion` 호출하는 코드이다

하지만 위 코드에서는 에러 상황에서 `completion` 을 호출하지 않고 바로 return을 한다는 문제점이 있다.

![image](https://miro.medium.com/v2/resize:fit:1400/format:webp/1*-ZNqzsP-70y4W5S5ukXnYg.png)

`completionHandler`는 작업 종료시 항상 호출 되어야하는데, 이 작업은 온전히 개발자에게 달렸다.

컴파일러가 “여기서 `completion` 호출해라!”라고 알려주지 않는다는 것이다

따라서 5개의 잠재적 버그(정상적으로 반환하지 않아 UI를 갱신하지 못하는)발생 기회를 가진 코드가 만들어진다.

Swift 5.0부터 도입된 `ResultType`을 통해 성공/에러 상황에서 보내는 모양이 좀 더 나아지긴 했지만 그래도 `completion` 미호출에 대한 위험 있는건 마찬가지이다.

**completionHandler 콜백 형식의 문제점**
- completionHandler 호출하는걸 잊을 수도 있음
- 오류 처리를 어렵고 장황하게 만듦
- 비동기 호출간의 제어 흐름이 복잡할 때도 문제가 됨
- 심지어 매개변수 구문 @escaping (String) -> Void은 읽기 어려움

이러한 상황을 해결하기 위해 Swift 5.5 부터 `async & await` 가 도입되었다.

비동기 코드를 마치 동기 코드인것처럼 작성할 수 있기 때문에, 동기 코드에서 사용할 수 있는 동일한 언어 구조를 최대한 활용할 수 있다.

***

## 기존 GCD 코드

아래 코드를 통해 다시 한번 비동기로 수행되는 함수에 @escaping 속성으로 탈출 클로저를 전달하여 비동기 Task 이후에 수행할 작업을 Completion Handler로 처리하는 구체적인 코드를 살펴보면

```swift
func addNumWithGCD(completion: @escaping (Int) -> ()) {
    DispatchQueue.global().async {
        var result: Int = 0
        
        for i in 1...10 {
            result += i
        }
        
        completion(result)
    }
}

func callGCDFunction() {
    addNumWithGCD(completion: { result in
        print(result)
    })
}

callGCDFunction()    //55
```

`addNumWithGCD(completion:)` 함수의 내부에는 1부터 10까지 수를 더하는 과정이 `DispatchQueue`를 통해 비동기로 수행되고 `callGCDFunction()` 함수에서는 `addNumWithGCD(completion:)`함수를 호출하고 매개변수 `completion`으로 탈출 클로저를 전달하여 비동기 `Task`가 종료된 이후에 수행할 작업을 수행하고 있다.

***

## async / await

위의 과정을 `DispatchQueue`를 사용하지 않고 `async`와 `await` 만을 이용하여 코드를 작성하면 다음과 같다.

```swift
func addNumWithAsync() async -> Int {
    var result: Int = 0
    
    for i in 1...10 {
        result += i
    }
    
    return result
}

func callAsyncFunction() async {
    print(await addNumWithAsync())
}

Task {
    await callAsyncFunction()    //55
}
```

`DispatchQueue`로 인한 들여 쓰기가 없어지고 매개변수로 탈출 클로저를 전달하지 않아도 되기 때문에 코드가 간결해지고 가독성도 향상된 모습을 볼 수 있다.

특히 중첩된 형태의 `Completion Handler`를 `async`와 `await`로 구현한다면 그 효과는 극대화 될것이다.

`async`와 `await`를 사용한다면 `Completion Halder`를 사용하지 않아도 비동기 `Task`가 완료된 시점에 비동기 함수가 호출된 위치(Suspension Point)로 돌아와 그 다음 코드를 이어서 진행할 수 있도록 보장하고 개발자 입장에서는 코드를 마치 동기 코드처럼 작성할 수 있어 개발에 편리함을 줄 수 있다.

### async

```swift
func addNumWithAsync() async -> Int
```

함수 이름 뒤에 `async`라는 키워드를 사용하면 해당 함수를 비동기로 실행하겠다는 의미이다.

만약 함수 수행 중에 `Error`가 발생할 가능성이 있어 `throws` 키워드를 사용해야 한다면 아래의 코드와 같이 `async` 키워드 뒤에 throws 키워드를 사용하도록 한다.

```swift
func addNumWithAsync() async throws -> Int
```

추가적으로 `async`로 선언된 함수는 다른 `async`로 선언된 함수 내부, 혹은 `Task` 구조체의 이니셜라이저로 전달되는 클로저 내부와 같은 `asynchronous context`에서만 호출될 수 있다.

### await

`async`로 선언한 함수를 호출하기 위해서는 아래의 코드와 같이 `await` 키워드와 함께 호출한다.

```swift
func callAsyncFunction() async {
    print(await addNumWithAsync())
}
```

참고로 `await` 뒤에 호출되는 함수는 반드시 비동기로 수행되는 함수가 와야한다.

위에서 언급한 것과 같이 `async` 함수를 호출하기 위해서는 `asynchronous context` 내부에서만 호출할 수 있고 결국 `await` 또한 `asynchronous context` 내부에서만 사용될 수 있다.

만약 `await`로 호출하는 함수가 `Error` 발생의 가능성이 있다면 아래의 코드와 같이 `await` 앞에 `try` 키워드를 사용한다.

```swift
func callAsyncFunction() async {
	do {
		try await addNumWithAsync()
	} catch {
		print(error)
	}
}
```

`await` 키워드를 사용하여 `async` 함수를 호출하게 되면 해당 지점을 `Suspension Point`라고 한다.

***

## Suspension Point

Apple에서는 Suspension Point에 대해 다음과 같이 설명한다.

```
A suspension point is a point in the execution of an asynchronous function where it has to give up its thread
```

비동기 함수의 실행 지점인건 알겠는데, 해당 스레드를 포기해야 한다는 것은 무슨 의미일까?

이것을 이해하기 위해서는 동기와 비동기 함수에서 thread 제어권이 어떻게 이동하는지 이해할 필요가 있다.

### 동기 함수의 thread 제어권

먼저 `callAsyncFunction()` 함수에서 `addNum()`이라는 동기 함수를 호출 한다고 가정했을때 thread 제어권의 흐름은 다음과 같다.

![image](https://velog.velcdn.com/images/jeunghun2/post/49b16e72-e6a0-446e-9158-300ee30b76be/image.png)

`callAsyncFunction()` 함수에서 시작된 thread는 동기 함수인 `addNum()` 함수의 호출과 함께 thread 제어권을 해당 함수로 넘겨 주게되고 `addNum()` 함수가 종료 되었을때 다시 `callAsyncFunction()` 함수로 thread 제어권을 넘겨주게 된다.

이런 경우 동기 함수에 thread 제어권을 넘겨 주었기 때문에 동기 함수가 종료 될때까지 thread는 다른 작업을 수행할 수 없게 된다.

### 비동기 함수의 thread 제어권

다음으로 `callAsyncFunction()` 함수에서 비동기 함수인 `addNumWithAsync()`를 호출했을때 thread 제어권의 흐름은 다음과 같다.

![image](https://velog.velcdn.com/images/jeunghun2/post/dc4e7e75-4b6c-410e-905d-a92eb9518b7f/image.png)

위에서 설명한 것과 같이 `await`를 통해 비동기 함수를 호출하게 되면 그 지점이 `Suspension Point`가 되고 해당 함수를 호출한 thread의 thread 제어권을 `System`에게 넘긴다.

`System`은 해당 thread 제어권을 가져와 다른 `Task`에 할당하여 다른 `Task`를 수행하다가 비동기 함수가 완료 되었을때 다시 thread 제어권을 돌려 줌으로서 비동기 함수 호출 이후의 작업을 이어서 수행할 수 있다.

`Suspension Point`의 내용을 보면 마치 `GCD`를 이용한 비동기 함수의 탈출 클로저와 역할이 비슷해 보인다.

Swift Concurrency를 사용하면 탈출 클로저 없이 `async`와 `await`만으로 탈출 클로저와 같은 기능을 수행할 수 있다.

위에서 등장한 코드를 조금 수정하여 아래와 같은 코드가 있을때 결과는 어떻게 될까?

```swift
func callAsyncFunction() async {
    print(await addNumWithAsync())    //Suspension Point 잠시 대기
    print("Hello World!")
}
```

`await`로 `async` 함수를 호출하여 그 지점부터 `Suspension Point`가 되어 그 이후의 코드는

`addNumWithAsync()` 함수가 종료 될때까지 잠시 대기하고 `System`은 해당 함수가 종료 될때까지 다른 `Task`를 먼저 수행한다.

그리고 `addNumWithAsync()` 함수가 종료 되면 `System`으로부터 thread 제어권을 부여 받아 그 다음 print 문이 실행 되기 때문에 출력되는 순서는 아래와 같을 것이다.

```swift
//55
//Hello World!
```

