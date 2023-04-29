**storyboard란?**
----

스토리보드Storyboard란 앱의 흐름을 나타내며, 시각적으로 화면을 구성하는 곳입니다. 스토리보드에서 우리는 앱의 전반적인 형태와 앱의 화면 전환, 다양한 Object들을 관리해주는 곳입니다. 여기서 Object들이란 화면에서의 Label, Button, Sliders 등 요소들을 나타내는 것입니다.

***

**view란?**
-----

view란, IOS 앱 사용자 인터페이스의 기본 구성 요소입니다. 이를 사용하여 앱의 컨텐츠를 화면에 그리거나 구성할 수 있습니다.

**View의 관리**
View의 계층을 관리하는 역할을 알아보자.

- ViewController에는 컨트롤러 내부에 모든 객체의 대장인 루트뷰 하나이다. 이 루트뷰는 일반뷰, 테이블뷰, 컬렉션뷰 등 다양한 뷰가 루트뷰로 지정해줄 수 있다.
- 스토리보드에서 ViewController 위에 배치하는 대부분의 객체들은 실제로는 모든 루트뷰에 추가되는 서브뷰라고 할 수 있다.
- 뷰들의 구조는 루트뷰의 서브뷰, 서브뷰의 서브뷰로 계층을 이루고 있다
- 우리는 개발을 할 때 항상 모든 객체를 루트뷰 혹은 그 아래에 추가해야 한다. 루트뷰 없이 곧바로 ViewController에 객체를 추가할 수는 없다.
- 루트뷰의 설정 확인 방법은 스토리보드 맨 앞에 화살표가 있으면 루트뷰가 설정되어 있는 것이다. 
![alt](https://blog.kakaocdn.net/dn/dzfozF/btriujvPSzr/xbYbIvrMjKSJMdlXPmMOsK/img.png "alt")
- ViewController에는 Root View가 연결되어 있고 그아래에 서브뷰들이 이어져있다. 이렇게 체인처럼 ViewController 부터 가장 하위의 서브뷰에 이르기까지 계층 구조를 따라 참조가 이어지고 있다.
- 이 때문에 ViewController가 하위의 모든 뷰에 대한 참조를 가지고 있지 않아도 모든 뷰에 접근할 수 있다. (체인처럼 참조가 이어지고 있어서)
- 우리는 ViewController를 통해 뷰를 통제하고 뷰가 사용자와 상호작용할 수 있도록 필요한 코드륿 뷰 컨트롤러에 작성을 한다.


***

**view controller란?**
----

뷰 컨트롤러(View Controller)란, UIKit을 사용하는 앱의 인터페이스를 관리하기 위한 도구입니다. 
viewController는 여러가지 종류가 있는데, ViewController, Navigation Controller, TableView Controller, TabBar Controller, Split ViewController, CollectionView Controller …. 등이 있다.

- **ViewController**
> - iOS에서 가장 기본이 되는 컨트롤러로서 앱의 데이터를 표시될 외형을 연결해서 하나의 동적인 화면을 만들어 낸다.
> - 내부에 뷰를 포함하므로 원하는대로 화면을 직접 구상하고 컨트롤러들을 배치할 수 있다.
> - 이 컨트롤러에 연결될 클래스는 작성하려면 반드시 UIViewController 클래스를 상속받아야 한다.

- **Navigation Controller**
> - 앱의 화면 이동에 대한 관리와 그에 연관된 처리를 담당해주는 컨트롤러
> - 내부적으로 다른 컨트롤러를 포함하여 컨트롤러끼리 화면 이동을 처리해주고 현재의 페이지 위치에 대한 네비게이션 역할을 한다.
> - 이 컨트롤러가 추가된 앱 상단에는 네비게이션 바가 추가된다.
> - 네비게이션 컨트롤러를 정의하는 UIKit 프레임워크의 클래스는 UINavigationController이다. 직접 구현하고자 한다면 클래스를 상속받아야 한다.
> - 뷰를 포함하고 있지 않으므로 하나의 화면을 담당하지 못하고, 다른 컨트롤러와 결합하여 부분적으로 화면을 구성한다.

- **TableView Controller**
- 내부에 리스트 형식의 테이블 뷰를 포함하고 있어 여러 항목이나 데이터를 화면에 나열하기 위한 목적으로 사용되는 컨트롤러이다.
- 하나의 컨트롤러가 하나의 화면을 이루는 단위 컨트롤러이다
- UIKit 프레임워크의 클래스는 UITableViewController 클래스이다. 해당 화면을 구성하기 위해서는 UITableViewController 클래스를 상속받아 추가 구현하는 작업이 필요하다.
- 대표적으로 아이폰 기본앱 중에 설정이 있는데 여러항목이 화면에 나열되어 있는 것을 볼 수 있다.

- **TabBar Controller**
- 화면을 나타내는 여러개의 탭이 있고, 탭을 터치하면 해당하는 화면이 전환되는 형태의 앱을 만들고자 할때 사용하는 컨트롤러이다.
- 탭마다 다른 뷰 컨트롤러를 연결하여 화면을 구성하며 직접 화면 전체를 나타내는 것이 아닌 복잡적으로 화면을 구성하는 역할을 한다. (네비게이션과 마찬가지)
- iOS앱에서 시계 기본앱을 키면 밑에 시계알림, 알람, 스톱워치, 타이머 탭들이 있는데 이런 구성을 하는게 TabBar Controller이다.
- 탭바 컨트롤러에 해당하는 UIKit 프레임워크의 클래스는 UITabBarController 이다.

***

**UIKIT 이란?**
------

UIKIT이란, iOS 애플리케이션의 사용자 인터페이스를 구현하고 이벤트를 관리하는 프레임워크이다.
> - UIKit 프레임워크는 제스처 처리, 애니메이션, 그림 그리기, 이미지 처리, 텍스트 처리 등 사용자 이벤트 처리를 위한 클래스를 포함한다.
> - 그리고 테이블뷰, 슬라이더, 버튼, 텍스트 필드, 얼럿 창 등 애플리케이션 화면을 구성하는 요소들을 포함한다.
> - UIKit 클래스 중 UIResponder에서 파생된 클래스나 사용자 인터페이스에 관련된 클래스는 애플리케이션의 메인 스레드(혹은 메인 디스패치 큐)에서만 사용한다.
> - UIKit은 iOS와 tbOS플랫폼에서 사용한다.

**UIKit 기능별 요소**

> **사용자 인터페이스**
> - view and Control : 화면에 콘텐츠 표시
> - view Controller : 사용자 인터페이스 관리
> - Animation and Haptics : 애니메이션과 햅틱을 통한 피드백 제공
> - Window and Screen : 뷰 계층을 위한 윈도우 제공

> **사용자 액션**
> - Touch, Press, Gesture : 제스처 인식기를 통한 이벤트 처리 로직
> - Drag and Drop : 화면 위에서 드래그 앤 드롭 기능
> - Peek and Pop : 3D터치에 대응한 미리보기 기능
> - keyboard and Menu : 키보드 입력을 처리 및 사용자 정의 메뉴 표시

**viewDidLoad()란?**
-----

```
viewDidLoad()
override func viewDidLoad() {
    super.viewDidLoad()
}
```
viewDidLoad() 메서드의 특징은 다음과 같다.
- ViewController의 모든 View가 메모리에 로드됐을 때 호출
- 메모리에 처음 로드될 때 한 번만 호출
= 보통 딱 한 번만 호출될 행위들을 이 메서드에 정의
- View와 관련된 추가적인 작업, 네트워크 호출
