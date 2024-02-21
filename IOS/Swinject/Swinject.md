# Swinject

## Swinject

`Swinject`는 Swift 에서 DI (의존성 주입)을 위한 프레임워크로,

객체 자체가 아니라 프레임워크에 의해 객체의 의존성이 주입되도록 한다.

→ DI 패턴에서 Swinject는 앱이 느슨하게 결합된 구성 요소로 분할될 수 있도록 도와주며, 이는 보다 쉽게 개발, 테스트 및 유지 관리할 수 있다.

---

## Swinject 예제

1. `AppDelegate.swift` 에 `Container`를 생성한다. 그리고 `Container`에 프로토콜과 클래스를 등록한다.
- 의존성 주입은 클래스의 외부에서 한다. 따라서 ViewController 클래스의 외부인 AppDelegate 에 Swinject Container를 선언해줬다.
- register : Container 에 사용할 프로토콜 등록
- resolve : 클래스 사용

```swift
import UIKit
import Swinject
import Foundation


protocol Animal {
    var name: String? { get }
}

class Cat: Animal {
    let name: String?
    
    init(name: String?) {
        self.name = name
    }
}


@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    let container: Container = {
        let container = Container()
  		// Cat 이라는 클래스에 Animal 프로토콜에게 제어권을 넘기는 동시에,
  		// 의존성을 주입한다.
        container.register(Animal.self) { _ in Cat(name: "Mimi") }
        
  		// ViewController 클래스를 등록한다.
        container.register(ViewController.self) { resolver in
            let controller = ViewController()
            controller.animal = resolver.resolve(Animal.self)
            return controller
        }
        return container
    }()
	
  ...

}
```

---

2. SceneDelegate.swift 에서 등록했던 ViewController 를 사용한다.

```swift
class SceneDelegate: UIResponder, UIWindowSceneDelegate {

    var window: UIWindow?

    let appDelegate = UIApplication.shared.delegate as! AppDelegate
    

    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        guard let scene = (scene as? UIWindowScene) else { return }
        
        self.window = UIWindow(windowScene: scene)
        self.window?.rootViewController = appDelegate.container.resolve(ViewController.self)
        self.window?.makeKeyAndVisible()
    }
```

---

3. ViewController.swift에서 등록했던 Animal을 사용한다.

```swift
import UIKit

class ViewController: UIViewController {
    var animal: Animal?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        print("Animal name is \(animal!.name!)")
    }
}
```

![image](https://velog.velcdn.com/images/heyksw/post/e7a67dcb-1b21-4db2-ba61-fa7426b3429a/image.png)

---

+같은 프로토콜을 준수하는 클래스가 여러 개일 경우

Animal 프로토콜을 준수하는 Cat, Dog 클래스가 있을 때의 예시.

### AppDelegate.swift
```swift
import UIKit
import Swinject
import Foundation

protocol Animal {
    var name: String? { get }
    var cry: String? { get }
}

class Cat: Animal {
    let name: String?
    let cry: String?
    
    init(name: String?) {
        self.name = name
        self.cry = "Meow"
    }
}

class Dog: Animal {
    let name: String?
    let cry: String?
    
    init(name: String?) {
        self.name = name
        self.cry = "Bark"
    }
}


@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    let container: Container = {
        let container = Container()
        container.register(Cat.self) { _ in Cat(name: "Mimi")}
        container.register(Dog.self) { _ in Dog(name: "Popi")}
        
        container.register(ViewController.self) { resolver in
            let controller = ViewController()
            controller.cat = resolver.resolve(Cat.self)
            controller.dog = resolver.resolve(Dog.self)
            return controller
        }
        
        return container
    }()
...
}
```

### ViewController.swift

```swift
import UIKit

class ViewController: UIViewController {
    var cat: Cat?
    var dog: Dog?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        print("Cat name is \(cat!.name!)")
        print(cat!.cry!)
        print("Dog name is \(dog!.name!)")
        print(dog!.cry!)
    }
}

```
![image](https://velog.velcdn.com/images/heyksw/post/bca3ea7b-4114-4377-b7f2-3ab9e530100b/image.png)