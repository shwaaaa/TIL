# @MainActor

iOS에서 UI 업데이트에 관한건 모두 메인 스레드에서만 업데이트 해야한다.

만약 메인 스레드가 아닌 타 백그라운드 같은 스레드에서 UI 업데이트를 친다면 예기치 못한 동작이 발생할 수 있고 또한 경고를 내보낸다.

따라서 백그라운드 스레드에서 직접 혹은 간접적으로 작업을 수행할 때마다 UI 렌더링과 관련한 속성 및 메서드에 접근하기 전에 꼭 메인 스레드로 이동시켜야 한다.

***

## 기존에는 어떻게 UI 업데이트에 관한것을 메인 스레드로 넘겼을까?

```swift
class ProfileViewController: UIViewController {
    private let userID: User.ID
    private let loader: UserLoader
    private lazy var nameLabel = UILabel()
    ...

    private func loadUser() {
        loader.loadUser { [weak self] result in
            DispatchQueue.main.async {
                switch result {
                case .success(let user):
                    self?.nameLabel.text = user.name
                case .failure(let error):
                    self?.showError(error)
                }
            }
        }
    }
}
```
일반적으로는 DispatchQueue.main.async을 이용해 UI 관련 업데이트를 비동기 호출로 래핑할 수 있었다.

위 코드는 당연히 정상적으로 돌아가지만 단점은 매번 DispatchQueue.main 코드를 넣어 신경써야 한다는 점이다.

실제 Combine Publisher를 관찰하거나 특정 딜리게이트 메서드를 구현할 때와 같은 경우 백그라운드 큐에서 실행될 수 있다는 점이 있기에 오류가 발생하기 쉽다.

***

## @MainActor란?

`MainActor`는 `main dispatch queue`와 동등한 효과를 가져다 주기때문에 `DispatchQueue.main.async{ ... }` 를 사용하는 대신 `MainActor`를 사용할 수도 있다.

단, `MainActor`는 `DispatchQueue`와 달리 `iOS13+`에서 사용가능하다는 제약사항이 있다.

따라서 View의 body 블럭 내에는 기본적으로 메인스레드에서 동작한다.