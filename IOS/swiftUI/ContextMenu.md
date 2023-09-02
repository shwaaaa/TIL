# context menu

- SwiftUI는 앱에서 `팝업(popup)` 메뉴를 만들기 위한 `ContextMenumodifier`를 제공한다.

- `iOS`에서는 일반적으로 `3D Touch`를 사용해서 처리되지만, `macOS`에서 우측 클릭하는 것과 같은 동작이다.

- `context menu`는 버튼 컬렉션에 내장되어 있으며, 각각 고유한 동작, 텍스트, 아이콘으로 되어 있다.

- 암시적으로 `HStack`을 제공할 것이 때문에, 텍스트와 아이콘은 버튼 내부에 직접 제공될 수 있습니다. 

```swift
Text("Options")
    .contextMenu {
        Button {
            // action
        } label: {
            Image(systemName: "heart")
            Text("하트")
        }

        Button {
            //action
        } label: {
            Image(systemName: "star")
            Text("star")
        }
    }
```

![image](https://cdn.discordapp.com/attachments/1098858102582956064/1147453579905466429/2023-09-02_5.50.49.png)