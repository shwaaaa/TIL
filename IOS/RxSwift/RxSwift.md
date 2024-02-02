# RxSwift

## RxSwift란?

`RxSwift`는 **R**eactive e**X**tension + Swift로 관찰 가능한 시퀀스를 사용하여 비동기 및 이벤트 기반 프로그램을 구성하기 위한 라이브러리이다.

Swift는 함수형 프로그래밍(Functional Programming) 패러다임을 강조하는 언어이다.

이에 RxSwift는 반응형 프로그래밍(Reactive Programming)을 더하여, Swift에서 FRP(Functional Reactive Programming) 따를 수 있도록 한다.

***

### 그렇다면 반응형 프로그래밍이란?

반응형 프로그래밍(Reactive Programming)이란,

데이터의 흐름 및 변경사항을 전파하는 데 중점을 둔 프로그래밍 패러다임이다

이 패러다임을 사용할 경우, 주변환경/데이터에 변화가 생길 때 

연결된 실행 모델들이 이 이벤트를 받아 동작하도록 설계하는 방식이다.

```swift
var a = 10
var b = 20
 
var sum = a + b
sum              // 30
```
위에서 sum이란 변수엔 당연히 30이 들어가 있다.

근데 만약 a라는 변수의 값이 어느 순간 20으로 바뀐다면?

```swift
a = 20
sum              // 30
```

우리가 평소 하던 일반적인 프로그래밍일 경우,

sum의 타입은 Int 타입이고, 대입할 당시의 a의 값을 복사 했고,

우리는 sum에 a가 바꼈다고 어떠한 작업을 해주지 않았기 때문에,

sum이 a+b였긴 하지만, a의 값이 바뀌었다고 해서 sum의 값이 바뀌진 않는다.

반면에 반응형 프로그래밍일 경우,

```swift
a = 20
sum              // 40
```

값을 20으로 바꾸면,

a가 바뀐 이후 우리가 어떠한 작업을 추가적으로 해주지 않아도 sum의 값이 바뀌어야한다.

**a라는 데이터의 흐름이 기존 10에서 20으로 변경됐을 때 이 변경사항에 대해서 a와 연결되어 있는 sum(실행 모델)이 이벤트를 "전파"받아서 어떠한 동작(값 갱신)을 할 수 있는 것**이다.

그렇다면 실행 모델(sum)은 a의 값이 바뀌는지 안 바뀌는지에 대해서 "관찰"을 하고 있어야하며,

a의 값이 바뀌었을 때 관찰 중인 sum에게 이를 전파 해야하고,

해당 이벤트를 전파 받았을 때 어떤 일을 하지 sum에서 정해야한다.

이걸 가능하게 해주는 것이 바로 RxSwift의 `Observable`, `Obsever`, `Operater`이다.