# Convinience init

초기화의 종류에는 크게 2가지로 `Designated`, `convenience`가 있다.

이는 모든 멤버를 초기화하고 상속받은 멤버들을 `customizing`을 하기 위해서이다.

## Init

swift의 초기화 이니셜라이저로, 본 이름은 `Designated init`(지정 이니셜라이저)이다.

init은 클래스의 모든 프로퍼티가 초기화 될 수 있도록 만들어주는 역할이며

모든 클래스의 프로퍼티를 초기화해야 한다. → 지키지 않을시 오류 발생

```swift
class Person {
    var name: String
    var age: Int
    var gender: String

    init(name: String, age: Int, gender: String) {
        self.name = name
        self.age = age
        self.gender = gender
    }
}
```

***

## Convenience init

보조 이니셜라이저로, 클래스의 원래 이니셜라이저인 init을 도와주는 역할을 한다.

`convenience init`은 같은 클래스에서 다른 이니셜라이저를 호출해야한다는 규칙이 있다.

init의 파라미터 중 일부를 기본값을 설정해서, `convenience init`안에서 init을 호출하여 초기화 진행할 수 있다. (= `Convenience init` 내부에서 반드시 `Designated init`이 호출되어야 한다 self.init() )

즉, 파라미터로 넘겨주지 않은 값은 그냥 임의로 지정해주고, 파라미터로 넘어간 것들만 넣어주면 된다.

```swift
class Person {
    var name: String
    var age: Int
    var gender: String

    init(name: String, age: Int, gender: String) {
        self.name = name
        self.age = age
        self.gender = gender
    }
		
		convenience init(age: Int, gender: String) {
        self.init(name: "zedd", age: age, gender: gender)
    }
}
```

***

## 초기화 규칙

모든 멤버가 초기화 되어야한다는 보장

- D init - 반드시 바로 위 super class의 D init을 호출해야합니다.
> ( delegation : sub class에서 super class의 init호출 )

- C init - 반드시 같은 클래스의 D init을 호출해야합니다.
> ( D init이 이미 모든 멤버 초기화를 보장하기 때문에 )

***

## 상속에서의 초기화 규칙

1. 자신의 클래스 멤버 모두 초기화
2. super class로 부터 상속받은 멤버들은 super class의 designated init을 호출함으로서 모두 초기화
> 1. 단, super class의 D init 호출 전에 자신의 멤버 먼저 초기화
> 2. super class로 부터 상속받은 멤버를 초기화 할 때, super class의 D init을 먼저 호출
> 3. C init도 D init 호출 후 별도의 값 대입 가능
> 4. 초기화 중에는 instance method와 instance property 사용 불가