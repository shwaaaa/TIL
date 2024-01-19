# CoreData란?
Core Data는 앱에서 모델 계층 개체를 관리하는 데 사용하는 프레임워크이다.

***

# Core Data의 기능
- Persistence(영속성)
> Core Data는 객체를 저장소에 매핑하는 세부 정보를 추상화하여 DB를 직접 관리하지 않고도 Swift 데이터를 쉽게 저장할 수 있다. 아래 그림은 앱이 영구 저장소에 데이터를 저장하고 데이터를 로드하는 과정을 보여주는 그림이다.
![Alt text](https://blog.kakaocdn.net/dn/nJqFb/btq2pkB605o/axkEaSso5qY5x3UhjLx6xK/img.png)

- 개별, 일괄 변경 사항 Undo, Redo
> Core Data의 실행 취소 관리자는 변경 사항을 추적하고 개별적으로나 그룹적으로 한 번에 롤백할 수 있어 앱에 `Undo` 및 `Redo`를 쉽게 추가할 수 있다. 아이폰에서 메모나 메시지를 쓰다가 흔들면 글자가 사라지는 기능이 있는데, 아래 그림은 그러한 제스처를 사용하여 실행 취소를 하는 것을 보여주는 그림이다.
> `undo`: 실행 취소
> `redo`: 다시 하다
![Alt text](https://blog.kakaocdn.net/dn/buWM6c/btq2kDbtOkf/5rZxsYWjJZGq4dJrKxwS6k/img.png)

- 백그라운드 데이터 작업
> 백그라운드에서 JSON을 객체로 구문 분석하는 것과 같은 데이터 작업을 수행한다. 그런 뒤 결과를 캐시 하거나 저장하여 서버에 갔다 오는 횟수를 줄일 수도 있다. 아래 그림은 UI를 업데이트하기 전에 백그라운드에서 개체를 채우는 End Point의 데이터를 보여주는 그림이다.
![Alt text](https://blog.kakaocdn.net/dn/nykVK/btq2pj4g6Ru/bXvfk6uYwgOvUy14YJyKPk/img.png)

- 동기화
> Core Data는 테이블, 컬렉션 뷰에 대한 Data Source를 제공하여 뷰와 데이터를 동기화 상태로 유지하는데 도움을 줍니다.

- 버전 관리 및 Migration
> Core Data에는 데이터 모델의 버전을 관리하고 앱이 발전함에 따라 사용자 데이터를 `마이그레이션`하는 메커니즘이 있습니다.
> `마이그래이션(Migration)`: 마이그레이션(migration)이란 한 종류의 데이터베이스에서 다른 종류의 데이터베이스로 데이터를 옮기는 것을 의미

***

# Core Data Stack 
Core Data는 다음과 같은 스택 구조를 갖는다
![Alt text](https://blog.kakaocdn.net/dn/ojW5x/btrElbnMvQ0/aSW99WBtUoIakX6v06HHZ0/img.png)

- Model(NSManagedObjectModel)
> - Core Data에서 관리하는 객체들과 그 객체들 사이의 관계를 표현한 데이터모델 (객체 그래프) 파일을 의미한다.

- Context(NSManagedObjectContext)
> - Persistence Store뷰에 해당하는 객체이다.
> - 해당 객체를 통해서 원하는 데이터를 가져오고 조작하고, 원하면 Persistence store에 반영할 수 있다.

- Store Coordinator(NSPersistenceStoreCoordinator)
> - Model에 의해 정의된 데이터들이 실제로 저장된 Persistance store 을 관리하는 객체이다. Persistence store에서 데이터를 가져오고, 저장될 때 데이터가 올바른지 검증하는 역할 또한 수행한다.

- Persistence Container(NSPersistenceContainer) - iOS 10이상
> - 위 3개의 요소를 간편하게 사용할 수 있도록 추상화 시켜 놓은 객체이다.
> - iOS 10 이전에는 위 3개 요소를 개발자가 직접 초기화해서 사용했지만, iOS 10 이상부터는 NSPersistenceContainer 를 이용해서 간단하게 3개 요소를 한꺼번에 초기화할 수 있게 됐다.

