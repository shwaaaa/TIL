# GeometryReader

## GeometryReader란?

`GeometryReader`는 그 자체로 `View`이며 상위뷰의 컨테이너의 크기를 통해서 하위뷰의 위치 및 크기를 선언하는데 사용한다

***

## GeometryProxy
`container view`의 크기 및 좌표공간에 대한 엑세스를 위한 `proxy(대리인)`이다

- 속성
> - frame(in:): 특정좌표계를 기준으로 한 프레임 정보를 제공

> - size: geometry reader의 크기를 반환

> - safeAreaInsets: geometry read가 사용된 환경에서의 안전영역에 대한 크기를 반환
