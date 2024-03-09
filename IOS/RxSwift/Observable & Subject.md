# **Observable와 Subject**

# **Observable**

```swift
Observable → 관찰 가능한, 관찰할 수 있는하나의 Sequence(수열)이며 async하다.
```

`Observable`이 이벤트를 발생 시키는 것을 `emit`한다고 표현한다.

---

## **just, of, from**

- just - 하나의 파라미터를 받아 하나의 이벤트를 발생 시킨다
- of - 파라미터의 타입을 전달, 배열이라면 배열 자체를 전달하는 것
- from - 배열 타입을 전달받아 배열 안에 있는 요소들을 꺼내 sequence를 생성한다. (array, dictionary, set포함)
    - 타입이 다른 요소를 넣을 경우 error
    - 타입 추론을 Any로 한다면 된다.
    

```swift
let observable1 = Observable.just(1) // Observable<Int>

let observable2 = Observable.of(1, 2, 3) // Observable<Int>

let observable3 = Observable.of([1, 2, 3]) // Observable<[Int]>

let observable4 = Observable.from([1, 2, 3]) // Observable<Int>
출처: https://min-i0212.tistory.com/7 [민이의 일상:티스토리]
```

---

## **subscribe**

`subscribe()`는 `NotificationCenter`에서 `addObserver()` 대신 사용되는 것이라고 생각하면 된다.

다른점이라면 NotificationCenter에서는 `.default`를 이용해 싱글톤을 사용했지만

Rx에서는 Observable은 `subscriber`가 없다면발생한 이벤트를 전송하지 않는다.

```swift
// from
observable4.subscribe { event in
    print(event)
    if let ele = event.element {
        print(ele)
    }
}
/*
 print(event) 일 경우 (optional?)
 next(1)
 next(2)
 next(3)
 completed
 .next와 .completed 이벤트 발생

 if let ele = event.element {
       print(ele)
 }  일 경우
 1
 2
 3
 엘리멘트로 접근 가능
 */
```

```swift
// of + Array
observable3.subscribe { event in
    print(event)
    if let ele = event.element {
        print(ele)
    }
}

/*
 print(event) 일 경우 (optional)
 next([1, 2, 3])
 completed

 if let ele = event.element {
     print(ele)
 } 일 경우
 [1, 2, 3]
 */
```

```swift
// from
observable4.subscribe(onNext: { element in
    print(element)
})
/*
1
2
3
 */
```

onNext를 사용하게 되면 next이벤트에 대해서만 emit하므로 따로 바인딩하지 않아도 된다.

---

## **Disposable**

subscribe()는 `Disposable`을 리턴한다.

Observable의 사용이 끝나면 메모리를 해제해야하는데 그때 사용하는 것이 `Dispose()`

```swift
let subscription1 = observable4.subscribe(onNext: { element in
	print(element)
})
subscription1.dispose()
```

DisposeBag은 `deinit()`이 실행될 때 모든 메모리를 해제한다.

subscribe가 리턴하는 Disposable 인스턴스를 넣어준다.

```swift
let disposeBag = DisposeBag()

Observable.of("A", "B", "C")
    .subscribe {
        print($0)
}.disposed(by: disposeBag)
/*
 next(A)
 next(B)
 next(C)
 completed
 */
```

---

# **Subject**

`Subject`는 `Observable`을 `subscribe`(구독)할 수 있고 다시 `emit`(방출)할 수 있다.

혹은 새로운 Observable을 emit할 수 있다.

- PublishSubject
- BehaviorSubject
- ReplaySubject
- ~~Variable~~ - deprecated!
- BehaviorRelay

---

## PublishSubject

`PublishSubject`는 `subscribe` 전의 이벤트는 emit하지 않고,

subscribe 이후의 이벤트만 emit에러 이벤트가 발행한다면 그 이후 이벤트는 emit하지 않는다.

```swift
let subject1 = PublishSubject<String>()
subject1.onNext("First")

subject1.subscribe { event in
    print(event)
}
// 이때는 프린트 되는 것이 없다. -> subscribe이전에 이벤트가 발생했기 때문에!

subject1.onNext("Second")
subject1.onNext("Third")
/*
 next(Second)
 next(Third)
 completed
 */
```

만약 이 상황에서 `dispose`나 `onCompleted`, `onError`를 추가하고 **"Fourth"**를 추가하면 Fourth가 프린트 될까?

```swift
subject1.dispose()
// subject1.onCompleted()
// subject1.onError(Error.self as! Error)
subject1.onNext("Fourth")
```

정답은 찍히지 않는다.

`dispose()`할 경우 그대로 이벤트가 종료되고 `onCompleted()`의 경우 completed가 프린트 되고

onError를 할 경우 에러가 어쩌구라고 프린트 된다.

---

## BehaviorSubject

`BehaviorSubject`는 PublishSubject와 거의 같지만 BehaviorSubject는 반드시 초기화 해줘야한다

```swift
let subject2 = BehaviorSubject(value: "Initial value")
subject2.subscribe { event in
    print(event)
}
subject2.onNext("Second value")
// next(Initial value)
// next(Second value)
```

만약 subscribe되기 전 subject2에 "Last value"를 이벤트를 emit하면 어떻게 될까?

```swift
let subject2 = BehaviorSubject(value: "Initial value")
subject2.onNext("Last Value")
subject2.subscribe { event in
    print(event)
}
subject2.onNext("Second value")
// next(Last Value)
// next(Second value)
```

subscribe되기 전 emit이 되면 Initial value는 last value로 변해 방출되게 된다

---

## ReplaySubject

`ReplaySubject`는 미리 정해진 사이즈 만큼 가장 최근의 이벤트를 최근의 subscriber에게 전달한다.

`createUnbounded`는 무한!(모든이벤트) <- 메모리 관리에 유의하기!

```swift
let subject3 = ReplaySubject<String>.create(bufferSize: 2)

subject3.onNext("First")
subject3.onNext("Second")
subject3.onNext("Third")

subject3.subscribe { print($0) }
/*
 next(Second)
 next(Third)
 */

subject3.onNext("Fourth")
subject3.onNext("Fifth")
subject3.onNext("Sixth")

print("- Second subscribe")

subject3.subscribe { print($0) }
/*
 next(Second)
 next(Third)
 next(Fourth)
 next(Fifth)
 next(Sixth)
 - Second subscribe
 next(Fifth)
 next(Sixth)
 */
```

버퍼 사이즈 만큼 마지막 값이 `replay`된다.

만약 `buffersize`가 1이라면 제일 마지막의 `Sixth`만 방출된다.

---

## BehaviorRelay

`BehaviorRelay`는 `RxCocoa`에 포함되어 있다.

`PublishSubject`와 `BehaviorSubject`를 래핑한 것이라고 보면 된다.

그래서 subscribe할 때 `.asObservable()`을 사용한다.

근데 `.asObservable()` 안써도 subscribe가 된다..?

```swift
let relay = BehaviorRelay(value: "Initial value")

relay.asObservable()
    .subscribe {
        print($0)
}
// next(Initial value)
```

이런 식으로 `emit`해준다.

```swift
let relay2 = BehaviorRelay(value: [String]())

relay2.accept(["Number 1"])

relay2.asObservable()
    .subscribe {
        print($0)
}
//next(["Number 1"])
```

`String`만 subscribe를 하게 되면

[]으로 뜨게 되고, accept로 이벤트를 emit 할 수 있다.

```swift
let relay3 = BehaviorRelay(value: ["Number 1"])

relay3.accept(["Number 2"])

relay3.asObservable()
    .subscribe {
        print($0)
}
// next(["Number 2"])
```

`BehaviorSubject`와 마찬가지로 subscribe 되기 전에 값이 emit 된다면,

구독 시에도 값은 마지막 값이 된다.