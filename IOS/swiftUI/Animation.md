# Animatipn

## 애니메이션 방법

애니메이션을 줄 수 있는 방법으론 2가지가 있다!

- `withAnimation` (명시적인 애니메이션)
> - 안에 넣은 코드를 통해 변경사항이 있는 뷰에 변화를 일으킨다.
> - `transition`은 사용할 수 있지만 `withAnimation`안에 `animation`을 사용하면 안된다.

- `animation` (암시적인 애니메이션)
> - 뷰의 속성중 하나가 변경되면 자동으로 그 속성이 변경될때마다 애니메이션을 적용한다.
> - 컨테이너뷰에 애니메이션을 넣으면 안된다.
> - 기존의 `animation`은 `animation modifier`가 붙은 화면만 애니메이션 처리를 해줬다면 `withAnimation`은 `{}`안에 들어가는 변화되는 값에 영향을 받는 모든 것에 애니메이션 처리를 한다.

### 그렇다면 transition은?

- 사라지고, 나타날때를 정의할때 사용한다

- `withAnimation`과 함께 사용하고 `animation`에선 동작하지 않는다.

***

## animation (암시적인 애니메이션)

animation의 파라미터
- 해당 파라미터는 animation의 속도에 관련된 파라미터
> - default : 애플에서 정해준 컴포넌트의 애니메이션
> - linear : 선형적으로 처음부터 끝까지 동일한 속도의 애니메이션
> - easeIn : 처음에는 느렸다가 갈수록 빨라지는 애니메이션
> - easeOut : 속도는 빨랐다가 점점 느려지며 멈추게 되는 애니메이션
> - spring : 스프링처럼 움직이는 느낌의 애니메이션

- 스프링 파라미터는 
> - respond : 스프링애니메이션이 작동하는 시간, duration과 동일하다
> - dampingFraction : 스프링의 강도를 의미한다.