# Factory Method

## Factory Method Pattern

Factory 패턴은 객체를 생성하는 모듈인 `Factory`를 만들어놓고 요청에 따라 객체를 생성하는 패턴이다.

Factory Method 패턴은 어떤 객체의 인스턴스를 생성할지 서브 클래스에서 결정하도록 한다.

객체 생성을 처리하는 팩토리를 프로토콜로 관리하여 실질적인 생성을 캡슐화하는 것이 가능하다.

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fba4iFe%2FbtrAuLhfhZy%2FKE2a6HOYE3ZQrykcbG1PDK%2Fimg.png)

일반적으로 Creator, Concrete Creater, Product, Concrete Product로 구성된다.

`Creator`에서는 추상적 정보만 파악하고 있고, `Concrete Creator`에서 객체 생성에 대한 결정을 수행한다.

---

## 구현 예시

Product : 생성되는 객체에 대한 동작을 정의합니다.
```swift
// Product
protocol Product {
    func hello()
}
```

Concrete Product : Product에 대한 구체타입입니다.
```swift
// Concrete Product
class A: Product {
    func hello() {
        print("Hello, Im A")
    }
}

class B: Product {
    func hello() {
        print("Hello, Im B")
    }
}
```

Creator : Facotry의 역할을 정의합니다.
```swift
// Creator
protocol Factory {
    func createProduct() -> Product
}
```

Concrete Creator : Facotry에 대한 구체 타입입니다.

여기서 createProduct 메서드가 위의 factoryMethod에 해당합니다.
```swift
// Concrete Creator
class AFactory: Factory {
    func createProduct() -> Product {
        return A()
    }
}

class BFactory: Factory {
    func createProduct() -> Product {
        return B()
    }
}
```

Client는 Factory를 활용해 Product를 생성하고 활용합니다.
```swift
class Client {
    func order(factory: Factory) {
        let elctronicsProduct = factory.createProduct()
        elctronicsProduct.hello()
    }
}

var client = Client()

client.order(factory: AFactory()) // Hello, Im A
client.order(factory: BFactory()) // Hello, Im B
```

---

## Factory Method Pattern의 사용 이유

새로운 객체가 생기거나 객체에 대한 수정이 생겨도, 클라이언트가 아닌 `Factory`만 수정하면 되기 때문에 코드 간 결합성을 낮출 수 있기 때문이다.

이는 코드 사용에 강력한 유연성을 제공한다.

