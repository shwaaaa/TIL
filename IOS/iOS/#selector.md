# selector

## Objective-C에서의 Selector

`Selector`는 원래 `Objective-C`에서 사용하던 기능이다.

이는 특정 메서드를 컴파일타임에 동적으로 식별하고 참조하는 역할을 했다.

이러한 특징을 기반으로 `Objective-C`에서 동적으로 메서드를 동작시키려할 때 `Selector`를 사용했다.

반면 `Swift`에서는 이런 별도의 객체를 사용하지 않아도 메서드를 동적으로 동작시킬 수 있기 때문에 직접적으로 `Selector`를 필요로 하지는 않는다.

---

## swift에서의 Selector

최근에는 주로 Swift로 iOS 개발을 진행하지만 여전히 많은 iOS의 API들이 Objective-C를 기반으로 동작하고 있다

따라서 Objective-C 기반 API에서 Selector 타입을 요구하는 경우, 이를 대체할 수 있는 타입을 Swift에서 제공할 수 있어야한다

그렇기 때문에 Swift에서 직접적으로 Selector를 사용하지는 않지만 Objective-C의 Selector와 유사한 기능을 하는 Selector를 필요로 했던 것이다.

---

## @objc의 필요성

컴파일 타임에 메서드를 바인딩하는 Swift와는 다르게 Objective-C는 런타임에 메서드를 바인딩한다.

따라서 Swift에서 Objective-C에 의존적인 메서드에 사용할 때는 해당 메서드가 Objective-C와 유사한 방식으로 컴파일 되어야함을 컴파일러에게 알려주어야한다

이를 의미하는 것이 `@objc`이다

이를 메서드 앞에 붙여주면 Swift로 작성된 코드를 Objective-C 런타임에서도 사용할 수 있게된다.