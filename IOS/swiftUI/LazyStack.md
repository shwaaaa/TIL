# LazyStack


## LazyStack이란?
- ScrollView와 Stack을 같이 쓸 때, ScrollView에 담겨있는 뷰를 처음에 모두 렌더링할 필요 없는 경우 효율성을 위해서 사용한다

- 즉 아이템들이 화면에 렌더링 될 때 생성된다!

***

## LazyVStack과 VStack의 차이점

- LazyVStack과 LazyHStack의 차이점은 배열이 수평으로 되는지 수직으로 되는지의 차이밖에 없기떄문에 LazyVStack으로 설명 해보겠다!

- LazyVStack과 VStack이 다른점은 ScrollView를 보면 한 눈에 확인할 수 있다

```swift
var body: some View {
    ScrollView(.vertical) {
            VStack {
                ForEach(1...100, id: \.self) {
                      Text("Column \($0)")
                    }
            }
        }
    }
```

이렇게 그냥 VStack을 사용하면

![image](https://cdn.discordapp.com/attachments/1098858102582956064/1139476493135777812/2023-08-11_5.32.28.png)

스크롤바가 글자 바로 옆에 생기는 걸 볼 수 있다!

이번엔

```swift
var body: some View {
        ScrollView(.vertical) {
            LazyVStack {
                ForEach(1...100, id: \.self) {
                      Text("\($0)")
                    }
            }
        }
    }
```

이렇게 LazyVStack을 사용하면

![image](https://cdn.discordapp.com/attachments/1098858102582956064/1139476023583461458/2023-08-11_5.30.35.png)

이 맨 끝에 스크롤바가 생기는걸 볼 수 있다!

<br>

이 이유는 LazyStack은 자동으로 유연한 선호 너비를 가져서 일반 스택과 달리 여유 공간을 차지하기 떄문이다!

![image](https://cdn.discordapp.com/attachments/1111221955165687869/1139479342167097384/2023-08-11_5.43.52.png)

![image](https://cdn.discordapp.com/attachments/1098858102582956064/1139479620522090526/2023-08-11_5.45.05.png)