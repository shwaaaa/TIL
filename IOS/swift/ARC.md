# ARC

## 참조(Reference) 타입과 Heap

```swift
class Human {
    var name: String?
    var age: Int?
    
    init(name: String?, age: Int?) {
        self.name = name
        self.age = age
    }
}
 
let shwaaaa = Human(name: "Shwaaaa", age: 17)
```

위의 코드에서 Human이라는 클래스가 있고 shwaaaa라는 인스턴스를 생성해 그 값을 초기화 해주었다

이렇게 되면 메모리에는 지역 변수 shwaaaa는 스택에 할당 되고 실제 Human 인스턴스는 힙에 할당 된다

스택에 있는 shwaaaa는 힙 영역에 있는 인스턴스를 참조하고 있는 형태이다

따라서 shwaaaa 안엔 힙에 할당된 인스턴스의 주소값이 들어가 있다

참조이기 떄문에 

```swift
let clone = sodeul
```

이런 작업을 해준다면 인스턴스가 복사되지 않고 실제 메모리가 같은 힙 영역의 인스턴스를 가리키고 있는다.

여기서 주목해야할 힙의 특징 중 하나는 **사용하고 난 후에 반드시 메모리 해제를 해줘야한다**라는 것이다.

지금까지 인스턴스를 마음대로 할당하고 사용해 왔지만 단 한번도 release나 free 같은 함수를 통해 인스턴스를 직접 메모리에서 해제해 준 적은 없다.

그 이유는 바로 `ARC`가 해제 해주기 떄문이다.

***

## ARC란?

`ARC`에 대한 Swift 문서를 보면

```
ARC는 클래스 인스턴스가 더 이상 필요하지 않을 때 메모리를 자동으로 해제한다
```

라는 내용이 있다.

지금까지 힙에 메모리를 자동 할당하며 사용해 왔지만 손수 메모리를 해제해주지 않아도 됐던 이유는 `ARC`가 메모리를 자동으로 해제해주기 때문이다.

***

## ARC의 메모리 관리 방법

ARC는 메모리의 참조 횟수(RC)를 계산하여, 참조 횟수가 0이 되면 더 이상 사용하지 않는 메모리라 생각하여 해제한다.

다시 말해 `RC`는 이 인스턴스를 현재 누가 가리키고 있느냐 없느냐(참조하냐 안하냐)를 숫자로 나타낸 것이다.

따라서 모든 인스턴스는 자신의 RC 값을 가지고 있다
> 인스턴스가 생성될 때 힙에 같이 저장

그럼 이 RC는 어떤 기준으로, 어떻게 셀까?

***

참조 횟수가 +1이 되는 순간은 인스턴스의 주소값을 변수에 할당할 때이다.

1. 인스턴스를 새로 생성할 때 
> ```swift
> let shwaaaa = Human(name: "Shwaaaa", age: 17)
> ```
> 아까 봤던 이 코드는 실행되는 시점에 지역 변수 shwaaaa은 스택에 할당되고 실제 인스턴스는 힙에 할당되며 shwaaaa엔 힙에 할당된 인스턴스의 주소값이 들어간다

> 이렇게 인스턴스를 새로 생성할 때 (새로운 변수에 대입할 때) 해당 인스턴스에 대한 RC가 증가

2. 기존 인스턴스를 다른 변수에 대입할 때 
> ```swift
> let clone = shwaaaa
> ```
> 기존 인스턴스를 다른 변수에 대입할 때도 당연히 참조에 의하기 때문에 RC 값이 증가된다.

***

그렇다면 참조 횟수는 언제 내려갈까?

1. 인스턴스를 가리키던 변수가 메모리에서 해제되었을 때 
> ```swift
> func makeClone(_ origin: Human) {
>     let clone = origin                          // ② Instance RC : 2
> }
>  
> let shwaaaa = Human(name: "Shwaaaa", age: 17)     // ① Instance RC : 1
> makeClone(shwaaaa) // ③ Instance RC : 1
> ```
> shwaaaa가 생성되는 순간 인스턴스의 RC + 1이 된다.

> makeClone 함수가 실행 되어 sodeul을 참조하는 clone 변수가 생성되는 순간 인스턴스의 RC + 1이 된다.

> 함수가 종료되어 지역변수 clone이 스택에서 해제되는 순간 인스턴스의 RC -1이 된다.

2.  nil이 지정되었을 때  
> ```swift
> var shwaaaa: Human? = .init(name: "Shwaaaa", age: 17)      // ① Instance RC : 1
> var clone = shwaaaa                                       // ② Instance RC : 2
>  
> clone = nil                                              // ③ Instance RC : 1
> shwaaaa = nil                                             // ④ Instance RC : 0 (메모리 해제)
> ```

3. 변수에 다른 값을 대입한 경우 
> ```swift
> var sodeul: Human? = .init(name: "Sodeul", age: 26)    // ① Sodeul Instance RC : 1
> var clone: Human? = .init(name: "Sodeul2", age: 26)    // ② Clone Instance RC  : 1
>  
> sodeul = clone                                         // ③ Clone Instance RC  : 2, Sodeul Instance RC : 0 (메모리 해제)
> ```

***

## ARC에서 발생할 수 있는 문제점

`ARC`에서는 두개의 클래스 인스턴스가 서로를 참조하는 경우에는 `강한 순환참조`가 일어나서 영원히 메모리에서 해제되지 않는 문제가 발생하기도 한다.

이를 해결하기 위한 방법으로는 `weak`, `unowned` 참조가 있다.