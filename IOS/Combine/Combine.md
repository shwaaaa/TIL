# Combine

## Combine이란?
`Combine`은 2019년에 Apple에서 만든 새로운 프레임워크이다

```
Combine 프레임워크는 시간 경과에 따라 변경되는 값을 내보내는 Publisher와 이를 수신하는 Subscriber로 시간 경과에 따른 값 처리를 위한 선언적 Swift API
```

***

## Combine을 쓰는 이유
`Combine`이 없어도 `Delegate 패턴`, `콜백 함수`, `completion` 클로저 등을 활용해서 비동기 프로그래밍을 구현할수있다.

비동기로 구현할 때 아주 깊은 콜백 함수나 delegate가 여러 개가 되는 경우 코드도 지저분해지고 예외 처리도 까다로워진다.

이떄 `Combine`을 사용하면 깔끔하게 처리할 수 있다

***

## Combine의 구성 요소
- Publisher
> - Publisher는 하나 혹은 여러 개의 Subscriber 객체에 시간의 흐름에 따라 값을 내보낼 수 있는 타입을 선언하기 위한 프로토콜
> - Output, Failure 타입이 제네릭으로 구현

- Subscriber
> - Subscriber는 Publisher에게 값을 받을 수 있는 타입을 선언하기 위한 프로토콜
> - Input, Failure 타입이 제네릭으로 구현

- Operator
> - Operator는 Publisher를 반환하는 Publisher 프로토콜에 정의된 메서드들
> - 여러 종류의 Operator를 Combine 하여 사용하여 Publisher가 내보내는 값을 처리
> - Upstream, DownStream이라고 하는 Input, Output을 가지고 있다.

- Subscription
> - Subscription은 Publisher와 Subscriber의 연결을 나타내는 프로토콜
> - Publisher + Operator + Subscriber로 이뤄진 하나의 작업이 Subscription

***

## Publihser와 Subscriber 동작 방식

1. `publisher`에 딸린 `subscribe(_:)` 함수를 통해 `subscriber`의 구독을 요청
![image](https://miro.medium.com/v2/resize:fit:4800/format:webp/1*YQXzgdmc19lyfxx3wjG8VQ.png)

2. `subscribe(_:)` 의 구현부에서는 `receive(subscriber:)`라는 함수를 호출한다. 이 함수는 `Publisher` 라면 모두 구현(implement)해야하는 함수로서 `protocol Publisher`에 정의되어 있다.
![image](https://miro.medium.com/v2/resize:fit:1400/format:webp/1*jvuDUqKbbgdbj3V3rSjLdg.png)

3. `receive(subscriber:)` 에서 `publisher`와 `subscriber`을 연결해준다
> - subscription을 만든 후 만들어진 subscription을 subscriber에게 전달하기 위해 subscriber의 receive(subscription:)을 호출한다. 이렇게 publisher와 subscriber는 subscription 을 통해 연결

4. `receive(subscription:)` 에서는 `protocol Subscription` 에 정의된 `request(_:)`을 호출하여 값을 최대로 얼만큼 받을 것인지 설정
> - 함수의 parameter type은 Demand

![image](https://miro.medium.com/v2/resize:fit:1348/format:webp/1*mBUMVKaeQxmp0nZDUph5NQ.png)
> 3개 이상으로 값이 들어올 수 없다

5. `subscriber`의 `receive(_:)`를 통해 `publisher`가 방출하는 새로운 값들을 전달할 수 있다. 따라서 이 함수는 여러번 호출 될 수 있다.

    `parameter` 타입과 `receive(_:)` 의 반환 타입은 둘 다 `Demand` 이다. 이를 통해서 처음에 `subscriber`가 받을 수 있는 최대 개수를 정하더라도 새 값을 받을 때마다 최대 값을 조절할 수 있다. 

6. 만약 `publisher`가 더 이상 값을 생성하지 않거나 `error`가 발생한다면 `subscriber`의 `receive(completion:)`을 호출을 통해 종료를 알린다.

***

## 흐름도

![image](https://miro.medium.com/v2/resize:fit:1400/format:webp/1*5ubY9OGbJBLfWEjMGpWp9w.png)

