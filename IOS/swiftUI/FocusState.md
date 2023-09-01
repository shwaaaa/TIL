# FocusState

## FocusState란?
- `@FocusState`는 현재 포커스(커서) 위치 또는 상태를 나타낸다.

- `@FocusState` 변수에 값을 대입하면 그 값에 대응하는 특정 뷰로 포커스가 이동하게 된다.

- 사용자가 임의로 포커스를 다른 뷰로 이동시키면 `@FocusState` 변수값도 자동으로 바뀌게 된다.

- `FocusState`값은 `Hashable`한 값이 와야하며, `enum`으로 `FocusState`값이 될 타입을 선언한다
> ```swift
> enum FocusType: Hashable {
>        case id
>        case password
>    }

- 그리고 `focused()`를 통해서 각 텍스트필드마다 지정해준다.
- 포커스를 관리하는 데 사용되며, `$focusedField`는 보고 있는 것이 무엇인지 알고, `equals: .username`은 그것이 무엇과 같은지에 대한 여부이다.
> ```swift
>TextField("이름", text: $username)
>    .focused($focusedField, equals: .username)
>
>TextField("비밀번호를 입력해주세요", text: $password)
>    .focused($focusedField, equals: .password)
>```

***

## 변화를 감지할 때
- `onSubmit` : 리턴버튼 클릭시에 실행되는 구문
- `onChange` : 텍스트필드 포커스시 실행되는 구문

