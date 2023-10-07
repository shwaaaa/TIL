# @ObservedObject & @Published

## @ObservedObject란?
- `ObservedObject`는 위에서 `ObservableObject`를 채택한 클래스나, 구조체를 뷰에서 관찰할수 있도록 인스턴스화 할때, 해당 객체는 `ViewModel`을 계속해서 관찰하고 있다고 알려주는 `property wrapper type`이다
> ObservableObject
> - 프로토콜
> - 해당프로토콜을 어떠한 Object(객체) 가 채택하게 되면, 해당 객체는 Publisher를 가지게 된다.
> - Publisher는 해당객체에 어떠한 변화를 감지하게 되면, 해당 오브젝트를 바라보고있는, 뷰에 이벤트를 방출하게 되고, 뷰는 refresh된다.

- 즉 MVVM패턴을 사용할 때 `ObservedObject`로 래핑한 인스턴스는, `ObservableObject`로 선언된, `ViewModel`을 계속해서 관찰하고 있으며 해당 뷰 모델값이 변경될때, View를 리프레시 해준다.

- `@State`같은 경우에는 특정 view에서만 사용하는 프로퍼티였다면 ,
`@ObservedObject`는 더 복잡한 프로퍼티 대신 `@ObservedObject`를 사용한다.
> - 복잡한 프로퍼티: 여러 프로퍼티나 메소드가 있거나, 여러 view에서 공유할 수 있는 커스텀 타입이 있는 경우

***

## ObjervedObject와 @StateObject 차이점
여기서 !!

`@ObservedObject`와 `@StateObject` 모두 기본적으로 뷰 내부에서 관찰 가능한 객체의 인스턴스를 저장하기 위해 사용된다.

그렇다면 이 둘의 차이점은 뭘까?

***

**데이터 변화**

> @ObservedObject: 데이터 변화가 있을 때 뷰를 처음부터 다시 그린다.

> @StateObject: 데이터 변화가 있을 때 변화가 있는 부분의 뷰만 다시 그린다.

**생명주기**

> @ObservedObject: 뷰가 사라지고 다시 그려짐에 따라, 인스턴스도 사라지고 다시 생성된다.

> @StateObject: 초기에 인스턴스가 생성되고 뷰와 상관없이 유지된다.

**사용**

> @ObservedObject: 보통 다루는 데이터가 달라지는 하위 뷰에서 사용한다.

> @StateObject: 보통 데이터를 유지해야하고 초기에 생성되는 상위 뷰에서 사용된다.

***

## @Published란?
- `@Published`로 표시된 프로퍼티 값이 바뀌면 외부로 바뀐 값을 퍼블리시하는 타입이라고 정의되어 있다

- `@Published` 속성으로 프로퍼티를 게시하면, 그 타입에 대한 퍼블리셔가 생성된다

- 그 퍼블리셔에 접근하려면 `$`사인을 붙여야한다

