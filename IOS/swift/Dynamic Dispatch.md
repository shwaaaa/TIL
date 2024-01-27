# Dynamic Dispatch

## 메시지와 메서드: 다형성
객체 지향 프로그래밍의 핵심 중 하나는 특정한 객체에게 '메시지'를 보내도, 실제 그 메시지를 처리하는 객체, 메서드는 달라질 수 있다는 점이다.

덕분에 우리는 메시지를 보내는 객체의 코드를 전혀 바꾸지 않고도, 실제 동작 (메서드)를 런타임 시점에 바꿀 수 있다.

다시 말해, 같은 인터페이스에 대해서 다른 함수가 실행되도록 만들 수 있어 코드 설계를 훨씬 유연하게 만들어준다.

이걸 '다형성'이라고 하고, 객체 지향 프로그래밍의 가장 슈퍼 파워 중 하나다.

여기서 하나의 `메시지`에 대해서 실행되는 `메서드`가 `그때그때` 다르다 라고 했는데,

다른 말로 하면, 컴파일러가 코드를 해석할 때
어떤 인터페이스에 대해 보낸 메시지에 대해 정확히 어떤 메서드를 실행해야 할지 `그때그때` 찾아내야 한다는 말이 된다.

***

예를 들어 `Human`이라는 클래스가 있고 안에는 `sayHello`라는 메서드가 있다.

그리고 `Human`을 상속한 여러 클래스 (Student, Employee) 등이 있다.

그렇다면
```swift
eddy.sayHello()
```
이 코드(메시지)는 어떤 메서드를 실행해야 할까?

정답은 `그때 그때 다르다`

코드의 실행 맥락에 따라서 `eddy`라는 인스턴스는

`human`일 수도 있고,

`student`일 수도 있고,

`Employee`일 수도 있다.

그러니 `sayHello()`라는 메시지에 대해 어떤 클래스에 선언된 메서드가 실행될지는 저 코드만 봐서는 알 수가 없다.

***

## Dynamic Dispatch가 필요한 이유

**메시지와 메서드의 분리**를 구현하려면 `Dynamic dispatch`가 반드시 필요하다.

### Dynamic Dispatch란?
어떤 객체가 다른 객체에게 메시지를 전송 `ex) Object.method()`했을 때,

**그때 그때 상황에 맞게 (Dynamic) 그 메시지에 맞는 메서드를 보내준다(Dispatch)는 뜻이다.**

즉, `Dynamic dispatch`는 다형성을 구현하기 위한 핵심 기능이다.

대부분의 객체 지향 언어에서 `dynamic dispatch` 메커니즘을 갖고 있다.

### Static dispatch

`Static dispatch`는 쉽게 말해, `Dynamic dispatch`가 아닌 메서드 호출을 말한다.

우리가 별도로 다형성을 구현하지 않고, `.`을 찍어서 프로퍼티, 메서드를 호출하면 `Static dispatch`다.

하나의 코드에 대해 항상 정해진 함수가 실행된다.

***

##  Dynamic Dispatch vs Static dispatch

`Swift`의 성능을 말할 때 `Dynamic dispatch`는 자주 등장하는 키워드다.

왜냐하면 `Dynamic dispatch`는 `OOP`의 핵심인 다형성을 만들어주지만, 굳이 다형성을 쓸 필요가 없을 때는 성능의 저하를 가져오기 때문이다.

코드를 실행하는 와중에 어떤 함수 호출을 보면 바로 그 함수로 점프하는 게 아니라,

정확히 어떤 함수로 가야할지 알아보고 점프를 해야하므로 성능에서 손해를 보게 된다.

`Dynamic dispatch`와 `Static dispatch`도 어느 한쪽이 우월한 것은 아니다.

**다만 둘의 차이를 알고 상황에 따라서 잘 사용하면 되는 것!**

***

## Dynamic dispatch를 쓰는 경우

Swift 컴파일러는 **메시지와 메서드가 다를 가능성**이 있으면 `Dynamic dispatch`를 하고,

그럴 가능성이 없으면 `Static dispatch`를 한다.

`Swift`에서 다형성을 구현할 수 있는 방법은 `protocol`, `class` 2가지다.

기본적으로 이 2가지 경우에 `Dynamic dispatch`를 하게 된다.

***

### Protocol의 메서드/프로퍼티 사용

`protocol`을 사용하면 기본적으로 `Dynamic dispatch`를 실행한다.

`Swift`는 `Protocol`을 사용해 타입을 특정한 인터페이스로 묶어준다.

메시지를 보낼 때 해당 `Protocol`에 대해서 코드를 작성할 수 있다.

```swift
// 프로토콜 정의
protocol canFly {
	func fly()
}

// 프로토콜을 따르는 타입 정의
struct Bird(): canFly {
	func fly() { print("Bird is flying!") }
}

struct Dragon(): canFly {
	func fly() { print("Dragon is flying!") }
}
func makeFly(canFly: canFly) {
	canFly.fly()
}

func makeFly(Bird()) // "bird is flying!"
func makeFly(Dragon()) // "Dragon is flying!
```

이렇게 프로토콜을 사용해서 메서드나 프로퍼티를 호출하는 경우,

Swift 컴파일러는 `canFly` 타입이 실제로 `Bird`인지 `Dragon`인지 찾기 위해서 `Dynamic dispatch`를 사용한다.

***

### Class의 메서드/프로퍼티 사용

`Class`를 쓰면 기본적으로 `Dynamic dispatch`를 실행한다

하위 클래스가 상속을 받거나 메서드를 **오버라이딩** 했을 가능성이 있기 때문이다.

상위 클래스의 메서드/프로퍼티를 가리키는 건지, 하위 클래스의 메서드/프로퍼티를 가리키는 건지 알아내야 한다.

***

## Static dispatch를 쓰는 경우

### Value type (struct, enum)의 메서드/프로퍼티 사용

`struct`, `enum` 으로 선언했을 때는 `static dispatch`를 실행한다.

`value type`인 경우 기본적으로 `static dispatch`다.

왜냐? `value type` 인스턴스는 `protocol`, `class`와 다르게 메시지를 다른 객체에게 위임할 수 없기 때문이다.

즉, 메시지와 메서드가 다를 가능성이 없기 때문에 `static dispatch`로 처리한다.

***

### Extension을 사용해 추가한 메서드 사용

`Swift`는 모든 타입에 `Extension`을 붙일 수 있다.

하지만 `extension`으로 새로운 기능을 추가할 수는 있지만, 그 안에서 이미 있는 메서드를 `상속(override)`를 할 수는 없다.

즉, 메시지-메서드가 다를 수 없다. (다형성을 사용할 수 없다.)

그래서 `Protocol/Class`에 `extension`을 붙여서 추가한 메서드는 `Static dispatch`로 실행한다.

***

## 예외 상황

### Class에 Final, Private, Static 키워드를 사용

#### final
`Swift`에서는 `class` 선언부나, 메서드/프로퍼티 선언부에 `final` 키워드를 붙일 수 있다.

`final` 키워드를 붙이면 **상속/오버라이드를 할 수 없기 때문에** 해당 클래스나 메서드에 대해 메시지를 보낼 때 다형성을 사용할 수 없다.

따라서 `Class`를 쓸 때는 기본적으로 `Dynamic dispatch`를 실행하지만,

`final` 키워드가 붙은 클래스의 메서드/프로퍼티일 때는, 컴파일러가 자동으로 `Static dispatch`를 쓴다.

```
다형성을 활용하지 않을 거라면, final을 써서 성능을 높이자!
```

#### Private
`private` 키워드가 붙으면, 메서드/프로퍼티는 선언부 내에서만 사용할 수 있다.

따라서 `Class`를 선언하는 블록/파일 내에 오버라이딩이 없다면, 컴파일러가 알아서 `final` 키워드를 추론해서 붙여준다.

그렇게 되면 `Static dispatch`가 되면서 성능이 좋아진다.

#### Static
`static` 키워드를 붙인 프로퍼티/메서드는 아예 인스턴스에서는 사용할 수 없다.

따라서 메시지-메서드가 달라질 가능성이 없고, `static dispatch`를 쓴다.

static이니까 당연히 static diaptch겠지? 하면 된다.