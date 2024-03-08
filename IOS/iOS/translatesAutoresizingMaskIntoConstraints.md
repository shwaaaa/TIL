# translatesAutoresizingMaskIntoConstraints

## 왜 오토 레이아웃을 사용할 때는 translatesAutoresizingMaskIntoConstraints = false를 할까?

부모뷰가 커지거나 줄어듦에 따라 서브 뷰의 크기나 위치를 조정하는 방식을 결정하는 `Autoresizing`이라는 개념이 존재한다.

이 개념은 여러 속성을 부여하여 슈퍼뷰의 크기 변화에 따라 서브 뷰의 width, height 혹은 leading, top, trailing, bottom 영역을 유연하게 고정하거나 확장할 수 있다.

이러한 `Autosizing`은 `AutoresizingMask`를 통해 적용할 수 있는데, 슈퍼 뷰의 bounds가 변경 될 때 자신의 크기를 조정하는 방법을 결정하는 비트마스크이다.

다만 `Autoresizing`과 `AutoLayout`을 동시에 사용하고자 할 경우 주의해야한다.

View의 `AutoresizingMask`도 결국 `Auto Layout`의 `constraints`로 변환되면서 기존의 `constraints`와 레이아웃 충돌이 일어날 수 있기 때문이다.

따라서 우리는 `AutoLayout`을 사용하고자 할 때 `translatesAutoresizingMaskIntoConstraints`라는 옵션을 false로 설정해 `AutoresizingMask`를 사용한 `Constraints` 변환을 막는 것이다.