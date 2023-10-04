# @ObservedObject

## @ObservedObject란?
- `ObservedObject`는 위에서 `ObservableObject`를 채택한 클래스나, 구조체를 뷰에서 관찰할수 있도록 인스턴스화 할때, 해당 객체는 `ViewModel`을 계속해서 관찰하고 있다고 알려주는 `property wrapper type`이다

- 즉 MVVM패턴을 사용할 때 `ObservedObject`로 레핑한 인스턴스는, `ObservableObject`로 선언된, `ViewModel`을 계속해서 관찰하고 있으며 해당 뷰 모델값이 변경될때, View를 리프레시 해준다.

- `@State`같은 경우에는 특정 view에서만 사용하는 프로퍼티였다면 ,
`@ObservedObject`는 더 복잡한 프로퍼티 대신 `@ObservedObject`를 사용한다.
> - 복잡한 프로퍼티: 여러 프로퍼티나 메소드가 있거나, 여러 view에서 공유할 수 있는 커스텀 타입이 있는 경우

***

## ObjervedObject와 @StateObject 차이점
여기서 궁금한 점!

둘 다 `ObservableObject`를 구독하여, 이 값이 변경되면 뷰에 반영해주는 `property wrapper` 형태인데 그렇다면 둘의 차이점은 뭘까?

상태 변경이 있을땐 @ObjervedObject는 뷰를 다시 생성해서 그리지만, @StateObject는 뷰를 다시 생성하지 않고 항상 동일한 뷰가 사용 (효율)


그래서 `EnvironmentObject`는 앱의 전역 데이터 공유 및 관리에 사용되며, `ObservedObject`는 뷰 내에서 특정 상태 변경을 관찰하고 해당 뷰를 다시 렌더링하는 데 사용됩니다.