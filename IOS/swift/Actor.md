# Actor

## Actor란?

`actor`는 클래스와 두 가지 주요 예외사항을 빼고는 거의 유사하게 동작한다.

즉, 참조로 전달되는 핵심은 마찬가지이다.

두 가지 다른 사항은 아래와 같다

1. `actor`는 해당 프로퍼티 및 메서드에 대한 모든 액세스를 자동으로 직렬화하기에 지정된 시간에 하나의 호출자만 액터와 직접 상호 작용할 수 있다.

    그렇다면 모든 변화가 차례로 순차적으로 수행되고 데이터 경합을 완전히 방지할 수 있다.

2. actor는 실제로 클래스가 아니기에 서브클래싱을 지원하진 않는다.

따라서 클래스를 액터로 변환하기 위해 할일은 딱 하나

class 키워드를 actor로 바꾸는거 그 이상 그 이하도 없다.

```swift
actor UserStorage {
    private var users = [User.ID: User]()

    func store(_ user: User) {
        users[user.id] = user
    }

    func user(withID id: User.ID) -> User? {
        users[id]
    }
}
```

아주 조그만 변화로 `UserStorage` 타입이 어떤 종류의 사용자 지정 디스패치를 가질지 구현할 필요 없이 완전히 스레드로부터 안전하게 된다

액터라는 키워드를 사용하여 다른 코드에서 메서드를 호출할때 `await` 키워드를 통해 호출하도록 강제하게 된다

***

예시로, 우리는 actor로 만들어진 UserStorage를 통해 값을 로드하고 저장하게 된다.

```swift
class UserLoader {
    private let storage: UserStorage
    private let urlSession: URLSession
    private let decoder = JSONDecoder()

    init(storage: UserStorage, urlSession: URLSession = .shared) {
        self.storage = storage
        self.urlSession = urlSession
    }

    func loadUser(withID id: User.ID) async throws -> User {
        if let storedUser = await storage.user(withID: id) {
            return storedUser
        }

        let url = URL.forLoadingUser(withID: id)
        let (data, _) = try await urlSession.data(from: url)
        let user = try decoder.decode(User.self, from: data)

        await storage.store(user)

        return user
    }
}
```

이제 액터와 상호작용이 필요한 메서드에서는 `await`를 사용하게 되는것이다.

***

## 여전히 발생할 수 있는 Race Condition

위의 학습을 통해 우리는 데이터 경합을 해결할 수 있었다.

그러나 반드시 데이터 경합에서 자유롭지 않을 수 있다.

실제로 `UserLoader`를 사용해 여러 곳에서 동시에 동일한 사용자를 로드하면 여러번의 중복 네트워크 API 호출이 수행되기에 경쟁 상태에 빠질 가능성이 농후하다.

저장된 사용자 값은 해당 사용자가 완전히 로드된 후에만 존재하기 때문이다.

모든 호출을 직렬화 한다쳐도, 액터 내에서 대기가 발생할 때 여전히 중단될 수 있다.

즉, 액터는 차단이 해제되고 다른 코드로부터 새로운 요청을 받을 준비가 된다.

그럼 일반적으로는 논블로킹 코드를 작성할 수 있기에 이러한 동작이 UserLoader가 클래스로 구현되었을 때와 마찬가지로 계속 중복 네트워크 호출을 수행하게 한다.

이걸 해결하기 위해 actor가 주어진 네트워크 통신을 수행하고 있는 시점을 추적해야 한다.

