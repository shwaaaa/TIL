# Hot Observable과 Cold Observable

## Observable

<aside>
💡 특정 형태의 데이터를 전달하는 이벤트를 비동기적으로 생성할 수 있는 객체.

</aside>

**Observable**은 **Hot Observable, Cold Observable** 두가지 종류로 구분될 수 있다.

`Hot Observable`과 `Cold Observable`을 **구분하는 기준**은 다음과 같다.

- **이벤트 발생이 시작되는 시점(구독시 vs 구독과 관계 없이)**
- 구독했을 때 이벤트 시퀀스를 **처음부터 관찰할 수 있는가**(있다 vs 없다)

---

## **Hot Observable**

`Hot Observable`은 **구독 여부에 상관 없이 이벤트를 발생**시키기 때문에 일단 동작하기 시작하면 리소스를 사용하게 된다.

따라서 구독했을 때 이벤트 시퀀스를 **처음부터 관찰하지 못할 수 있다**.

구독하는 시점에 따라서 전달받는 요소가 다르다.

또한 이 동작을 시작하는 시점을 조절할 수 있는 메소드를 제공한다(RxSwift의 connect()).

Hot Observable에는 `Subject`가 있다. 

예를 들어 API 호출 테스크를 진행할 때 여러 부분에서 이 결과가 필요하다면 그 때마다 API를 호출하기 보다 그 결과를 공유한다면 더 효과적일 것이다. 

이럴 때 `Hot Observable`이 사용되게 된다.

---

## **Cold Observable**

`Cold Observable`은 **구독과 동시에 무조건 동작**하며 그 이전에는 연산 자원을 소모하지 않는다.

**구독했을 때 시퀀스를 처음부터 관찰**할 수 있다.어느 시점에서 구독을 하든지 같은 결과를 받는다.

Cold Observable은 일반적으로 사용해오던 Observable 이다.

of, just, from 등이 속한다. 구현을 해도 구독하지 않았다면 방출되지 않는다.

---

Hot Observable은 여러 Observer가 하나의 **Observable을 공유**할 수 있다. 

지만 Cold Observable은 Observer마다 **별도의 Observable 인스턴스**를 가지게 된다.

만약 시퀀스를 만들어 내는 과정이 오래 걸리는 경우, Cold Observable은 구독이 일어날 때 마다 그 과정을 거쳐야 한다.