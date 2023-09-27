# URL Loading System

## URL Loading System이란?
- URL을 통해 네트워크에 존재하는 서버와 통신하는 기술이다.

- `URL Loading System`은 `https` 같은 표준 프로토콜이나 직접 만든 커스텀 프로토콜을 사용한 URL로 구별되는 리소스에 접근하는 것을 제공한다.

- `로딩(Loading)`은 `비동기적(asynchronously)`으로 수행되기 때문에 앱의 응답 속도를 저하시키거나 정지 시키지 않는다.

- 또한, 데이터나 오류가 도착하는대로 처리할 수 있다.

- **이에 포함된 프레임워크는 높은 수준의 API를 제공하기 때문에 이것만으로 서버연동, 다운로드, 업로드 기능을 구현할 수 있다.**

***

## URLSession
URLSession은 네가지 Session 타입을 가진다
> - Shared : 기본 설정을 기반으로 단순한 네트워크 요청을 수행할 수 있다.

> - Default : 세션을 직접 구성할 수 있다. `Degation`을 제공하기 때문에 세부적인 제어도 가능하다. 해당 세션을 통해 전송된 응답은 `Disk` 및 `Memory`에 캐싱된다.

> - Ephemeral : `Default`와 유사하지만 캐싱처리가 `Memory`에만 수행된다. 주로 `private`한 처리를 하려할 때 사용된다.

> - Background : 백그라운드 전송을 구현할 때 사용한다. 앱 실행상태와 관련없이 데이터를 다운로드하고 업로드할 수 있다.

- Shared Session을 제외한 모든 세션은 Session Configuration 객체를 통해 생성한다.

***

## Task
- `URLSession`에 전달하는 개별요청이다.

- 데이터 전달방식 및 목적에 따라 4가지 Task 타입을 사용한다.
> - DataTask : API 서버와 통신하기 적합하다. 가장 많이 사용되는 Task

> - DownloadTask / UploadTask : 파일 전송(다운로드, 업로드)에 적합

> - StreamTask : 채팅과 같은 TCP 프로그램을 구현할 때 사용하는 Task

- `URLSession.shared.task()`와 같은 형식으로 손쉽게 `Task`를 생성할 수 있으나

- 하지만 이는 `suspended` 상태로 생성되기 때문에 `resume 메서드`를 호출해야 작업을 시작합니다.
