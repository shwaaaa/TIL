# strong, weak, unowned

## Strong

Strong은 강한참조로 객체를 참조하고 `reference count`를 증가시킨다.

```swift
var reference1: Person? = Person(name: "Song") //강한 참조
reference1 = nil //메모리 해제
```

이때 해당 객체에 `nil`을 넣어주어야 메모리가 해제된다.

하지만 여기서 두 개의 객체가 상호 참조하는 경우와 같은 `강한 순환 참조(Strong Reference Cycles)`가 만들어 질 수 있다.

이 경우 `reference count`가 0이 되지 못해 `메모리 누수(Memory Leak)`가 발생된다.

***

```swift
//자기 자신의 객체를 가지는 클래스
class Strong {
    var strong: Strong? = nil //강한 참조 객체
}

//두개의 객체 변수 선언
var strong1: Strong? = Strong()  //객체 변수
var strong2: Strong? = Strong()  //객체 변수

//서로 강한 참조 (강한 순환 참조)
strong1?.strong = strong2
strong2?.strong = strong1

//두개의 객체 변수 메모리 해제
strong1 = nil
strong2 = nil
```


이 코드에서 잘 살펴보아야 할 것은 두개의 객체 변수는 마지막에 `nil`을 넣어 메모리 해제가 되었지만 각각의 객체는 강한 참조가 되었기 때문에 메모리 해제가 되지 못한다는 점이다.

즉 객체인 strong은 nil을 넣어주지 못하고 객체 변수의 메모리를 해제하였다는 점이다.

이때 객체에 접근할 방법도 없고 메모리를 해제할 방법도 없으니 메모리 누수가 일어나고 있다.

이러한 `강한 순환 참조(Strong Reference Cycle)`를 해결하는 방법에는 두가지가 있는데, 그 두가지로는 `약한 참조(weak reference)`와 `미소유 참조(unowned reference)`가 있다.

***

## weak

weak는 약한참조로 객체를 참조하고 reference count는 변화가 없다.

```swift
weak var reference1: Person? = Person(name: "Song") //약한 참조
//약한 참조이므로 바로 객체가 해제되어 nil이 됨
```

약한 참조는 강한 순환 참조를 해결하기 위해 사용되는 가장 보편적인 방법이다.

주로 인스턴스의 생명주기가 짧을 때 사용하며 참조하고 있는 인스턴스를 강하게 유지하지 않기 때문에, 약한 참조로 참조하고 있는 동안에 인스턴스가 메모리 해제되는 것이 가능하다.

***

```swift
//자기 자신의 객체를 가지는 클래스
class Strong {
    weak var strong: Strong? = nil //약한 참조 객체
}

//두개의 객체 변수 선언
var strong1: Strong? = Strong()  //객체 변수
var strong2: Strong? = Strong()  //객체 변수

//서로 강한 참조 (강한 순환 참조)
strong1?.strong = strong2
strong2?.strong = strong1

//두 개의 객체 변수 메모리 해제
strong1 = nil
strong2 = nil
```

위의 코드에서 클래스의 객체 부분을 약한 참조로 바꾸기 위하여 변수의 앞에 weak를 붙여주었다.

여기서 중요하게 봐야 할 부분은 두 개의 객체 변수의 메모리가 해제되었을 때 강한 참조 일때와 달리 약한 참조를 한 객체는 `ARC`에서 자동으로 객체의 메모리까지 해제를 시켜준다는 점이다.

***

## unowned

unowned는 미소유 참조로 객체를 참조하고 reference count는 변화가 없다.

미소유 참조도 약한 참조와 마찬가지로 인스턴스가 참조하는 것을 강하게 유지하지 않는다.

하지만 약한 참조와는 달리 미소유 참조는 다른 인스턴스와 같은 생명주기를 가지거나 더 긴 생명주기를 가질 때 사용한다.

그리고 약한 참조와 가장 큰 차이점인 부분은 미소유 참조는 Optional에 사용하지 못한다는 점이다.

따라서 nil값을 가질 수 없고 항상 값을 가지고 있어야 한다.

참조하는 객체의 참조계수가 0이 되어 메모리가 해제되는 경우 약한 참조에서는 참조 값이 nil로 대체되지만 미소유 참조에서는 참조 값이 그대로 유지가 된다.

***

## Weak vs unowned

참조 객체의 메모리 해제시

- 약한 참조 (weak) : 참조 값은 nil
- 미소유 참조 (unowned) : 참조 값은 유지

***

- strong : reference count를 증가시켜 ARC로 인한 메모리 해제를 피하고, 객체를 안전하게 사용하고자 할 때 사용.
- weak : 순환 참조에 의해 메모리 누수 문제를 막기 위해 사용.
- unowned : 객체의 life cycle이 명확하고 개발자에 의해 제어 가능이 명확한 경우, weak Optional타입 대신하여 사용.