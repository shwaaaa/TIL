# Sheet & FullScreenCover
ZStack과 Overlay처럼 뷰를 중첩하기 위한 방법

***

사용 방법

![image](https://cdn.discordapp.com/attachments/1085478329760616539/1162628822777200701/2023-10-14_2.51.46.png?ex=653ca177&is=652a2c77&hm=6a3e6cf2d7192abbe34ed76f2c67f740ec20ec72a9ecb1d97b80d656c0cb8cad&)

![image](https://velog.velcdn.com/images/page/post/05952c59-a8a2-402a-b089-5f41ee9f9445/image.png)

content에는 뷰를 넣고, isPresented는 Bool 값을 넣어준다.

```swift
struct sheet: View {
    @State private var isShownSheet = false
    @State private var isShownFullScreenCover = false
    
    var body: some View {
        VStack {
            Button {
                self.isShownSheet.toggle()
            } label: {
                Text("Sheet")
            }.sheet(isPresented: $isShownSheet) {
                destinationView()
            }
            
            Button {
                self.isShownFullScreenCover.toggle()
            } label: {
                Text("FullScreenCover")
            }.fullScreenCover(isPresented: $isShownFullScreenCover) {
                destinationView()
            }

        }
    }
}
```

***

## Sheet
`Sheet`는 화면을 모두 채우지 않는다. 그래서 `Sheet`는 화면 아래로 스크롤을 통해 이전의 뷰로 돌아갈 수 있다.

![image](https://cdn.discordapp.com/attachments/1098858102582956064/1162630975151407175/2023-10-14_3.00.21.png?ex=653ca379&is=652a2e79&hm=489ff57ff8dc44ec25e131af4d5145f1ce363ea3b0eb2128b13c9795a76e08af&)

***

## FullScreenCover
`Full Screen Cover`는 화면을 모두 채운다. 그래서 `Full Screen Cover`는 바인딩 값을 처리해주지 않으면 이전으로 돌아갈 수 없다.

![image](https://cdn.discordapp.com/attachments/1098858102582956064/1162631023763410944/2023-10-14_3.00.33.png?ex=653ca384&is=652a2e84&hm=592072f178da0b5c7d8bc8644b29ad79b8c26ce7181108bbe344c43e70aa8a91&)