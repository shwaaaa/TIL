# scene delegate

## scene delegate

화면에 표시되는 내용(Windows 또는 Scenes)들을 처리하고 앱이 표시되는 방식을 관리한다

- Scene Session은 앱에서 생성한 모든 scene의 정보를 관리함
```swift
optional func scene(_ scene: UIScene,
      willConnectTo session: UISceneSession,
            options connectionOptions: UIScene.ConnectionOptions)
```

- UISceneSession 에서 호출되는 첫번째 메소드
- 새 UIWindow 를 만들고 루트 뷰 컨트롤러를 설정
```swift
optional func sceneWillEnterForeground(_ scene: UIScene)
```

- Scene 이 시작되려고 할 때 호출된다
```swift
optional func sceneDidBecomeActive(_ scene: UIScene)
```

- WillEnterForeground 메서드 바로 다음에 호출
- scene이 설정, 표시되고 사용할 준비를 마친다
```swift
ptional func sceneWillResignActive(_ scene: UIScene)
optional func sceneDidEnterBackground(_ scene: UIScene)
```

- 앱이 백그라운드로 스테이징 될 때 호출
```swift
optional func sceneDidDisconnect(_ scene: UIScene)
```

- Scene 이 백그라운드로 갈 때 마다 iOS 는 리소스를 확보하기 위해 Scene을 삭제하는 것을 결정할 수 있음
- 앱이 종료되거나 실행되지 않음을 의미하지는 않지만 scene만 세션에서 연결 해제되고 활성화되지 않는다
- iOS는 사용자가 특정 scene을 다시 foreground로 가져올 때 이 scene을 scene 세션에 다시 연결하도록 결정할 수 있다
- 이 방법은 더 이상 사용되지 않는 리소스를 삭제하는 데 사용할 수 있다.