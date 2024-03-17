# URL Loading System

## URL Loading System
`URL Loading System`은 https 같은 표준 프로토콜이나 직접 만든 커스텀 프로토콜을 사용한 URL로 구별되는 리소스에 접근하는 것을 제공한다.

로딩(Loading)은 비동기적(asynchronously)으로 수행되기 때문에 앱의 응답 속도를 저하시키거나 정지 시키지 않는다.

또한, 데이터나 오류가 도착하는대로 처리할 수 있다.

`URLSessionTask` 인스턴스는 데이터를 가져와서 앱에 반환하거나 파일을 다운로드하고, 데이터 및 파일을 업로드할 수 있다.

URLSession 인스턴스를 통해 URLSessionTask 인스턴스를 여러 개 만들 수 있다.

---

Session을 설정할 때는 `URLSessionConfiguration` 객체를 사용한다.

이 객체는 캐시나 쿠키를 어떻게 사용할지, 셀룰러 네트워크 연결을 허용할 것인지 같은 옵션을 구성할 수 있다.

Task를 생성하기 위해 하나의 세션을 계속해서 사용하는 것도 가능하다.

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FtRCjS%2FbtrGJNSBJby%2FxfwAK42Gq5HtbUSD8FSOF0%2Fimg.png)

예를 들어, 웹 브라우저에는 Default browsing과 Private browsing을 위한 별도의 세션이 존재하며

Private 브라우징에서는 데이터 캐싱을 이용하지 않는다.

각 세션은 주기적인 업데이트 또는 오류를 수신하는 `delegate`와 연결되어 있습니다.

기본 delegate는 개발자가 제공하는 completion handler 블록을 호출하며 Custom delegate는 이 블록이 호출되지 않는다.

세션은 백그라운드에서 돌아갈 수 있도록 설정할 수 있으며

이 경우 앱이 Suspended 상태에 들어가더라도 시스템이 대신 데이터를 다운로드하고

앱이 깨어난 뒤에 결과를 받을 수 있다.