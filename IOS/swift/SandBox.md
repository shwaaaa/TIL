# SandBox

## SandBox란?
`SandBox`는 보호된 영역 안에서 프로그램을 작동시키는 보안 모델이다.

iOS의 모든 앱들이 이 `SandBox` 모델을 따른다

iOS는 기본적으로 앱 마다 별도의 파일을 생성하여 공유되지 않도록 한다. 

외부의 공격으로부터 앱이 손상된 경우, 시스템과 사용자 데이터의 피해를 최소화한다.

추가로 앱스토어를 통해 배포되는 모든 앱들은 `App SandBox`를 적용해야 한다.

***

## App SandBox를 안 쓴다면?

만약 SandBox가 아닌 앱이 있다면?

그 앱은 해당 앱을 실행하는 사용자에 대해 모든 권한을 갖고, 사용자가 엑세스 할 수 있는 모든 리소스에 엑세스 할 수 있다.

이렇게 모든 권한과 리소스에 접근할 수 있다면, 많은 기능을 수행할 수 있고 자유로울 것이다.

이러한 일을 사전에 방지하고자, iOS의 정책은 사용자 앱의 모든 리소스나 데이터에 접근이 불가능하도록 한다.

***

## App SandBox의 원칙

`App Sandbox`는 각 앱마다 취약한 리소스에 대한 액세스를 제한함으로써 공격자로 인한 사용자 데이터의 도난, 손상 또는 삭제 또는 시스템 하드웨어 해킹에 대한 마지막 방어선을 제공한다.

예를 들어, SandBox 앱은 다음 리소스를 사용하기 위해서는 그 의도를 명시해야 한다.

- 하드웨어 (카메라, 마이크, USB, 프린터)
- 네트워크 연결 (인바운드 또는 아웃바운드)
- 앱 데이터 (캘린더, 위치, 연락처)
- 사용자 파일 (다운로드, 사진, 음악, 영화, 사용자 선택 파일)

***

## App SandBox의 구조

![image](https://velog.velcdn.com/images/gnwjd309/post/050bc7e2-ba03-4505-94c7-654fa2572829/image.png)

위의 그림을 보면 각각의 앱이 하나의 SandBox화 되어있다.

즉, SandBox라는 하나의 바구니에 앱이 하나씩 들어있다.

SandBox는 앱에 대한 파일, 네트워크 리소스, 환경설정, 하드웨어 등에 대한 앱의 접근을 제한하는 세분화된 제어 집합이라고 할 수 있다.

각각이 개별적으로 존재하기 때문에 한 앱을 사용하는 사용자는 그 앱의 데이터에만 접근이 가능하다.

외부에 있는, SandBox 밖의 데이터에 접근하기 위해서는 SandBox 정책에 따라 접근 권한을 부여받아야 한다.

SandBox 내부는

![image](https://velog.velcdn.com/images/gnwjd309/post/a7a6d125-a6e4-4a0c-883e-c351ece5ed3a/image.png)

이렇게 생겼는데

앱을 설치하는 시점에 각각의 SandBox 디렉토리에 위치시키며, 이 디렉토리는 각 앱의 홈 디렉토리가 된다.

홈 디렉토리는 각각의 역할을 가진 컨테이너 디렉토리들을 하위 디렉토리로 가진다.

### Bundle Container

앱의 Bundle을 보유하는 컨테이너이다.

실행 가능 파일, plist, Resources(이미지, 사운드 등)등을 함께 그룹화 한다.

읽기 전용, 수정이 필요한 경우에는 Data Container로 옮겨서 작업한다.

### Data Container

하위 디렉토리로 Documents, Library, Temp, System Data가 있다.
> (이때 System Data 디렉토리는 iOS11 부터 생김!)
> - Documents: 앱을 통해 생성한 문서나 데이터 등을 저장
> - Library: 유저 데이터 파일 및 임시 파일을 제외한 모든 파일을 관리
> - Temp: 현재 앱을 실행하는 동안만 필요하고 다음 앱 실행시까지 유지할 필요 없는 임시 파일 저장 공간

사용자가 직접 디렉토리나 파일을 추가할 수 없으며, 하위 디렉토리를 통해 관리한다.

### iCloud Container

런타임에 접근을 요청할 수 있는 추가 컨테이너 디렉토리이다.