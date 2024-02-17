# defer

## defer란?

`defer`는 작성된 위치와 상관 없이 함수 종료 직전에 실행되는 구문으로

보통 함수 안에서 작성되는 클로저이다.

***

## defer 사용법

```swift
func testDefer() {
    print("Check #1")
    
    defer { print("defer #1") }
    
    print("Check #2")
}
 
testDefer()
```

이렇게 `defer`를 사용하면 

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FVPVLe%2FbtqQmPBv8d8%2FqNrdSFuK1prsHadLdzbcxK%2Fimg.png)

이렇게 defer 구문은 함수의 가장 마지막에 실행되는 것을 볼 수 있다.

***

## defer의 특징

### defer를 읽기 전에 함수가 종료되면 defer는 실행되지 않는다

```swift
func testDefer() {
    print("Check #1")
    
    return;
    defer { print("defer #1") }
    
    print("Check #2")
}
 
testDefer()
```

이렇게 defer를 읽기 전에 함수가 종료되어 버리면

defer는 불리지 않는다

### 하나의 함수에서 여러 번 defer를 호출 가능하며, 실행 순서는 가장 마지막에 실행된 defer부터 역순이다

defer는 다음과 같이 여러 번 호출이 가능한데,

```swift
func testDefer() {
    defer { print("defer #1") }
    defer { print("defer #2") }
    defer { print("defer #3") }
}
 
testDefer()
```

**먼저 읽은 defer부터 `stack`에 쌓인다**고 생각하면 된다.

따라서, 가장 마지막에 읽은 defer가 가장 먼저 실행되고,

가장 처음 읽은 defer가 가장 마지막에 실행 된다.

### defer는 중첩해서도 사용 가능하며, 실행 순서는 가장 바깥쪽 defer부터 실행된다

이 defer는 defer 안에서도 다음과 같이

```swift
func testDefer() {
    defer {
        defer {
            defer {
                print("defer #3")
            }
            print("defer #2")
        }
        print("defer #1")
    }
}
```

중첩해서 실행이 가능하며,

이때는 가장 바깥 쪽에 있는 defer가 가장 먼저 실행되고,

가장 안쪽에 있는 defer가 가장 마지막에 실행 된다.

***

## defer는 언제 사용할까?

defer는 함수를 종료하기 직전에 정리해야 하는 변수나 상수를 처리하는 용도로 사용된다