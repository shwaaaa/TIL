# ReactorKit

## ReactorKit이란?

`ReactorKit`은 `RxSwift`와 함께 사용되는 프레임워크이다.

따라서, `ReactorKit`을 사용하려면 `RxSwift`에 대한 이해와 `Swift` 언어의 기본 지식은 필수적으로 선행되어야 한다.

`ReactorKit`의 핵심 개념은 `Reactor`이다.

`Reactor`는 Rx의 개념인 `Observable`과 함께 사용하여 비동기적으로 데이터를 처리하고, UI와의 상호 작용을 쉽게 관리할 수 있는 구조를 만든다.

즉, `MVVM` 모델의 `뷰 모델(ViewModel)`과 같은 역할을 하며, 비즈니스 로직을 처리하고 `뷰(View)`와 상호 작용하는 방법을 제공한다.

이를 통해 UI 관련 코드와 비즈니스 로직을 분리하고, 코드의 재사용성을 높일 수 있다.

***

## 작동 방식과 사용법

![image](https://oliveyoung.tech/static/893e7add9b1ab3f41a6ec8ff617e7826/bbbf7/flow1.png)

사용자의 `Action`은 `Reactor`로, `Reactor`에서 방출된 `State`는 `View`로 `Observable` 스트림을 통해 전달된다.

이러한 흐름은 단방향적이다.

View는 Action만 방출 할 수 있으며, Reactor는 State만 방출 할 수 있다.

단방향적 흐름으로, View와 비즈니스 로직을 분리 할 수 있으며 모듈 간 결합도가 낮게 개발할 수 있다.

***

![image](https://oliveyoung.tech/static/573196199db5394de87ee54b6fb9f217/bbbf7/flow2.png)

### View
View는 Reactor로 받는 State를 통해 UI를 보여주는 역할과, 사용자 인터랙션을 추상화하여 Reactor로 전달하는 역할을 수행한다.

그림을 통해 보면 View는 Reactor를 향해 Action을 방출하고 있으며, Reactor는 View를 향해 State를 방출해주고 있다.

이를 적용하기 위해선, View 프로토콜을 적용해야하며, 그 안에 `DisposeBag` 프로퍼티와 `bind(reactor:)` 메서드를 반드시 정의해주어야 한다.

`bind` 내부에는, Reactor로 보낼 Action과, Reactor로부터 수신할 State를 작성하면 된다.

```swift
import ReactorKit
import RxGesture
import RxSwift

class MyViewController: UIViewController, View {
 var disposeBag = DisposeBag()

 func bind(reactor: MyReactor) {
		// Reactor로 보낼 Action
		self.testButton.rx.tapGesture().when(.recognized).map { _ in
							Reactor.Action.testAction }.bind(to: reactor.action).disposed(by: disposeBag)
		
		// Reactor로 부터 수신할 State
		reactor.state.map { $0.testState }.distinctUntilChanged().bind(to: testLabel.rx.text).disposed(by: disposeBag)
  }
}
```

### Reactor
그림을 보면, Reactor는 View로 부터 Action Stream을 전달 받아, 내부에서 `mutate()`와 `reduce()` 과정을 거쳐서 State Stream으로 바꾸어 다시 View로 전달해주는 역할을 한다.

이를 적용하기 위해선, Reactor 프로토콜을 적용해야하며, 그 내부에는 사용자 인터랙션을 의미하는 `Action`, Action과 State의 매개체인 `Mutation`, View가 가질 상태를 의미하는 State 를 반드시 정의해야한다.

`mutate()` 함수는 Action 스트림을 Mutation 스트림으로 변환하고, 변환된 Mutation 스트림은 `reduce()` 함수로 전달된다.

`reduce()` 함수는 이전 State와 Mutation을 활용하여 새로운 State를 반환한다.

이 State를 View에서 구독을 하고 있었다면, State가 변경됨에 따라서, UI가 업데이트 될 것이다.

```swift
import ReactorKit
import RxSwift

class MyViewReactor: Reactor {
	enum Action {
		case test
	}

	enum Mutation {
		case setTest(Int)
	}

	struct State {
		var testValue: Int = 0
	}
	
	let initialState: State = State()
}

extension myReactor {
  func mutate(action: Action) -> Observable<Mutation> {
    switch action {
      case .test:
      return Observable.just(Mutation.setTest(1))
        }
    }

  func reduce(state: State, mutation: Mutation) -> State {
    var newstate = state
    switch mutation {
      case let .setTest(testValue):
      newstate.testValue = testValue
    }
    return newstate
  }
}
```

***

## 장점

1. 사용법이 간단하다.
2. 특정 부분애만 적용할 수 있다.
> 전체 적용이 전제되지 않음
3. 테스트하기 쉽다.
> Reactor와 View에 대해 의존성이 없기 때문
4. 유지보수하기 쉽다.
> 상태값 관리를 용이하게 할 수 있기 때문
5. 코드가 간결해진다.
> ViewController에 있는 로직을 분리하면 간결해짐

