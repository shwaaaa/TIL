# URLSession이란?
URLSession은 HTTP/HTTPS를 통해 콘텐츠 및 데이터를 주고받기 위해 API를 제공하는 클래스

# Request
- URL 객체와 직접 통신하는 형태
- URLRequest 객체를 직접 만들어서 옵션을 설정해서 통신하는 형태


# Response
- Task의 `Completion Handler`를 통해서 응답 받는 방식
> completion handler를 사용하여 data task를 생성할 수 있다(`dataTask()` 호출) 이제 completion handler는 3가지 일을 해야한다.
> 1. error 파라미터가 nil인지 확인한다. 만약 nil이 아니라면 전송 에러가 발생한 것으로 에러를 처리하고 종료시켜준다.
> 2. response 파라미터를 확인하여 성공을 나타내는 상태 코드를 확인하고 MIME 타입이 원하는 값인지 확인해야한다. 만약 아니라면 서버 에러를 처리하고 종료한다.
> 3. data 인스턴스를 필요에 따라 사용하면 된다.

- `URLSessionDelegate`의 메소드를 통해서 응답 받는 방식

***

# URLSession API는 총 3가지 유형의 Session을 제공
- URLSession은 request를 보내고 받는 주요 객체인데 이건 `URLSessionConfiguration`을 통해서 생성할 수 있다.
1. Default Session (기본 세션)
> 디스크가 포함된 글로벌 캐시, 자격 증명 및 쿠키 저장소 개체를 사용하는 개체 생성

2. Ephemeral Session (임시 세션)
> 캐시, 쿠키 또는 credential과 같이 영구 저장소를 사용하지 않는 세션 구성 개체 생성
 
3. Background Session (백그라운드 세션)
> HTTP 및 HTTPS 업로드 또는 다운로드를 백그라운드에서 수행할 수 있는 세션 구성 개체를 생성

***

# URLSession Task 
1. URLSessionDataTask
> 서버에서 메모리로 데이터를 받아오는 작업 수행

2. URLSessionUploadTask
> 데이터를 파일로 변환 후 업로드하는 작업 수행

3. URLSessionDownloadTask
> 데이터를 파일로 변환 후 다운로드하는 작업 수행

***

# URLSession 통신 단계
1. Create a URL
2. Create a URLSession
3. Give URLSession a task
4. Start a task