# DI (의존성주입)

## 의존관계 역전 원칙 (DPI : Dependency inversion principle)

의존관계 역전 원칙은 SOLID의 마지막 원칙으로 상위 모듈이 하위 모듈에게 의존하지 않도록 설계하는 것이다.

즉, 상위 모듈과 하위 모듈 모두 추상화를 통해 간접적으로 의존하게 만들어야 한다.
> - 상위 모듈: 다른 모듈에서 의존하는 모듈을 말한다. (다른 모듈을 사용하는 모듈)
> - 하위 모듈: 다른 모듈에 의존되는 모듈을 말한다. (세부 구현 및 일부 기능을 제공하는 모듈)

또한, 추상화는 세부 사항(변수, 메서드 등)에 의존해서는 안되며, 세부사항이 추상화를 의존해야한다.

***

## 의존성(Dependency)이란?

의존성이란, 한 객체가 다른 객체에 의존하는 것을 의미한다.

```swift
// 하위 모듈
class Engine {
    func start() {
        print("엔진 가동")
    }
}

// 상위 모듈
class Car {
    // 👉 강하게 결합
    let engine = Engine()

    func start() {
        // 하위 모듈을 의존
        engine.start()
        print("차가 출발합니다.")
    }
}

let myCar = Car()
myCar.start()

// 엔진
// 차가 출발합니다.
```
여기서 상위 모듈은 Car 클래스이고 하위 모듈 Engine 클래스이며, Car 객체는 Engine의 객체에 의존한다.

의존 관계가 생겨 Car와 Engine의 객체가 강하게 결합되어 있으므로, 의존관계 역전 원칙도 위반하게 된다.

그렇기 때문에 만약, 엔진 대신 전기모터 차량으로 개조를 하기 위해선 기존 코드(Car 클래스)를 수정해야 하는 번거로움이 생기게 된다.

이러한 문제를 해결하기 위해서는

Car 클래스가 Engine 클래스에 직접 의존하지 않도록 만들어 줘야한다.

그 방법이 바로 **의존성 주입 방법**이다.

***

## 의존성 주입(DI : Dependency Injection)이란?

클래스 내부에서 의존하는 객체를 생성하는 것이 아니라,

외부에서 생성한 후 의존하는 객체를 전달받아 사용하는 디자인 패턴이다.

이를 통해 객체 간의 결합도를 낮추고, 유연하고 확장성 있는 설계가 가능하도록 도와준다.

크게 4가지 방법이 있다.

1. 생성자 주입

2. 프로퍼티 주입

3. 메서드 주입

4. 인터페이스 주입

***

### 생성자 주입

생성자를 통해 파라미터 값으로 필요한 의존성을 받아 객체를 생성한다.

보통 초기에 꼭 필요한 데이터나 객체가 있을 때 사용된다.

```swift
class Engine {
    func start() {
        print("엔진 가동")
    }
}

class Car {
    private let engine: Engine
    
    init(engine: Engine) {
        self.engine = engine
    }

    func start() {
        engine.start()
        print("차가 출발합니다.")
    }
}

let engine = Engine()
let myCar = Car(engine: engine)
myCar.start()

// 엔진 가동
// 차가 출발합니다.
```

***

### 프로퍼티 주입

객체를 생성한 후 프로퍼티를 통해 의존성을 전달하는 방식이다.

```swift
class Engine {
    func start() {
        print("엔진 가동")
    }
}

class Car {
    var engine: Engine?
    
    func start() {
        engine?.start()
        print("차가 출발합니다.")
    }
}

let engine = Engine()
let myCar = Car()

// Car 인스턴스의 engine 프로퍼티에 Engine 인스턴스 할당
myCar.engine = engine
myCar.start()

// 엔진 가동
// 차가 출발합니다.
```

단점으로는 클래스 내부에서 의존성을 갖고 있는 객체를 생성 못하므로,

외부에서 생성되기 전까지 객체를 생성 및 전달할 수 없다.

또한, 다른 곳에서도 engine로 접근할 수 있으므로 캡슐화가 깨지게 된다.

***

### 메서드 주입

의존성이 필요한 메서드를 호출할 때, 해당 메서드에 파라미터 값에 의존성을 전달하는 방식이다.

```swift
class Engine {
    func start() {
        print("엔진 가동")
    }
}

class Car {
    // Engine 클래스를 파라미터로 전달받음
    func start(with engine: Engine) {
        engine.start()
        print("차가 출발합니다.")
    }
}

let engine = Engine()
let myCar = Car()
// Engine 클래스의 인스턴스를 전달함
myCar.start(with: engine)

// 엔진 가동
// 차가 출발합니다.
```

단점은 프로퍼티 주입 방식과 동일하다.

***

### 인터페이스 주입

인터페이스란? 객체와 객체 사이의 상호작용을 정의하는 추상적인 개념이다.

Swift에서는 보통 Protocol를 이용하여 추상화를 시켜준다.

객체의 내부 구조나 구현 방식에 관계없이 외부에서 객체를 다룰 수 있게 도와준다.

```swift
// 프로토콜 정의
protocol EngineProtocol {
    func start()
}

// 하위 모듈 - 프로토콜 채택
class Engine: EngineProtocol {
    func start() {
        print("엔진 가동")
    }
}

// 상위 모듈 - 생성 시 프로토콜을 파라미터로 받음
class Car {
    private let engine: EngineProtocol
    
    init(engine: EngineProtocol) {
        self.engine = engine
    }
    
    func start() {
        // 프로토콜을 이용해 하위 모듈의 메서드 사용
        engine.start()
        print("차가 출발합니다.")
    }
}

let engine = Engine()
let myCar = Car(engine: engine)
myCar.start()

// 엔진 가동
// 차가 출발합니다.
```

인터페이스 주입 패턴을 사용하면, 서로 긴밀하게 연결된 의존성이 약해져 유지보수 및 확장성을 높일 수 있다.

'의존성' -> '의존성 주입'으로 변경하면 어떤 차이가 있는지, 코드를 추가해 확인해보면,

인터페이스 주입 패턴을 이용하여, 이번에도 전기차로 개조를 시켜보면

이와 같이, 상위 모듈의 코드를 수정하지 않고 확장이 용이해지며 깔끔하게 구현할 수 있다.

```swift
// 프로토콜 정의
protocol EngineProtocol {
    func start()
}

// 하위 모듈 - 가솔린 엔진
class GasolineEngine: EngineProtocol {
    func start() {
        print("가솔린 엔진 가동")
    }
}

// 하위 모듈 - 전기 모터 (추가)
class ElectricMotor: EngineProtocol {
    func start() {
        print("전기모터 가동")
    }
}

// 상위 모듈
class Car {
    private let engine: EngineProtocol
    
    init(engine: EngineProtocol) {
        self.engine = engine
    }
    
    func start() {
        // 프로토콜을 이용해 하위 모듈의 메서드 사용
        engine.start()
        print("차가 출발합니다.")
    }
}

let gasoline = GasolineEngine()
let motor = ElectricMotor()

let myGasolineCar = Car(engine: gasoline)
let myElectricCar = Car(engine: motor)

myGasolineCar.start()
// 가솔린 엔진 가동
// 차가 출발합니다.

myElectricCar.start()
// 전기모터 가동
// 차가 출발합니다.
```