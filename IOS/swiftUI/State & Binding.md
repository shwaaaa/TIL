# State & Binding

## State 
- `State`는 뷰 내부에서 특정 View의 상태를 나타내는 변수이다.

- 뷰내부에서만 사용이 가능하기 때문에 `private`으로 선언해줘야한다.
> ```swift
> @State private var myName = ""
> ```

- `state property`에 해당하는 변수 값이 변경되면 view를 다시 랜더링하기때문에 항상 최신값을 가진다.

- 상태프로퍼티인 `State`는 상태에 대한 가장 기본적인 형태이며, 뷰 레이아웃의 현재 상태에 저장하기 위해서만 사용된다.

- `State` 속성으로 어떤 프로퍼티의 초기값을 지정했다면, 다른 값으로 재할당 불가, `@Binding` 변수를 통해서만 가능하다.

## Binding
- `Binding`은 자식 뷰의 특정 property 값이 변경되면 부모의 특정 property 값도 변경된다.
> - 바인딩을 통해 데이터를 표시하고 변경하는 뷰 간에 양방향 연결을 만드는 것
> ```swift
>@Binding var isShowing: Bool
> ```

- `State` 로 선언된 속성을 다른 뷰에서 사용하려 한다면 `Binding` 을 사용해 줄 수 있다. 사용시에는 앞에 `$`를 사용해 `Bining 변수`임을 나타낸다

- 외부에서 접근해야 하기 때문에 `private`은 사용하지 않는다.

