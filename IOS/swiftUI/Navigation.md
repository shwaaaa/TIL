# Navigation

## NavigationView 및 NavigationLink

`NavigationView`를 사용하여 탐색을 설정할 수 있으며, `NavigationLink`를 사용하여 다른 뷰로 이동하는 링크를 생성할 수 있다.

```swift
NavigationView {
      NavigationLink("Navigate") {
        Text("안녕하세요")
      }
    }
```

- `NavigationView`는 최상위에 위치해야한다.

***

## NavigationBarItems /  NavigationTitle

navigationTitle
- `NavigationTitle`은 `NavigationView`의 괄호 바깥에서 지정하는 게 아닌, 안쪽에서 지정해야 한다.

- `NavigationView`에 `navigationTitle`을 지정하면 고정적인 타이틀을 지정하는 의미
![image](https://cdn.discordapp.com/attachments/1098858102582956064/1162270264223076474/2023-10-13_3.06.57.png?ex=653b5388&is=6528de88&hm=40881a4c481add81a97b848d7ca10db23d0330282e28a23ef3c9e4069ec8b999&)

NavigationBarItems의 종류
- leading
- trailing

```swift
NavigationView {
    Text("서근 개발블로그")
        .navigationBarTitle("스위프트UI", displayMode: .inline)
        .navigationBarItems(leading:
                                Button("스터디")
                                { /*code*/  }
                            ,trailing: Button("화이팅")
                                { /*code*/ } )
    }
```

![image](https://cdn.discordapp.com/attachments/1098858102582956064/1162269019622088765/2023-10-13_3.02.04.png?ex=653b5260&is=6528dd60&hm=5513519cace140ec0f93d08f54bb5174a900faee74143c46f215a2ecdc6738bd&)

***

## NavigationStack

`NavigationStack`은 iOS 16+ 부터 사용할 수 있기 때문에, 앱의 `Deployment Targe`t이 16+ 이상인경우에만 진행하는게 좋다

기존 `NavigationView`를 사용할때는
```swift
NavigationView { 
    /* content */
}
.navigationViewStyle(.stack)
```

이런식으로 `NavigationViewStyle`을 `stack`으로 주었지만 `NavigationStack`을 사용한다면 

```swift
NavigationStack {
    /* content */
}
```

이렇게만 사용하면 된다