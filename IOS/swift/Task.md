# Task

## Task란
```
A task is a unit of work that can be run asynchronously as part of your program.
```

Task는 비동기적으로 실행될 수 있는 작업 단위라고 한다.

Task 자체는 한 번에 한 가지 작업만 수행하지만 여러 작업을 생성하면 Swift는 해당 작업이 동시에 실행되도록 예약할 수 있다. 

즉, 실생활의 멀티 태스킹과 비슷하다!

예를 들어 sync에서 async 호출을 Task없이 async 함수 호출 시 에러가 발생한다

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbqdr3c%2FbtrSmrX73Cu%2FJvPuiN9R10Jkao9QuypbL1%2Fimg.png)

이런 경우에 Task 블록으로 감싸게 되면 해결된다

```swift
Task {
  await fetchItems()
}
```

***

## Task와 DispatchQueue 스레드 차이

공통점
- DispatchQueue 블록 안에 들어가면 임의의 스레드로 처리
- Task 블록 안에서도 임의의 스레드로 처리

차이점
- Task 블록 안에서 코드가 대기하여 다음 코드를 실행하지는 않지만, 내부적으로 스레드는 block 되지 않고 다른 일을 처리할 수 있도록 효율적으로 설계
```swift
override func viewDidLoad() {
    super.viewDidLoad()
    
    Task {
      try? await Task.sleep(for: .seconds(10)) // await를 만남 -> 다음 라인의 코드 실행시키지 않고 대기
    }
  }
```

- DispatchQueue는 해당 Thread가 점유하고 일을 하고 있으면, 그 스레드는 block되어 해당 일을 끝낼때까지 다른 일 처리를 못하는 상태
```swift
override func viewDidLoad() {
    super.viewDidLoad()
    
    DispatchQueue.global().async {
      self.fetchHeavyItems()
    }
  }
  
  func fetchHeavyItems() {
    // get some heavy items
  }
```