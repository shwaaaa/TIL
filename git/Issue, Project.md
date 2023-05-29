**Issue & Project*`
------

**Issue란?**
> 프로젝트의 기획, 작업, 개선 사항, 버그 수정, 새로 추가될 기능 등 모든 것을 이슈 라고 한다.
GitHub 에서는 이 모든 활동에 대해 이슈를 등록하고, 그것을 기반으로 작업을 진행할 수 있다.
Jira에서 이슈를 생성해 작업을 진행하는 것과 같고, 그 외에도 이슈 **open, close** 개념은 같다.

**project란?**
> 프로젝트는 작업의 진행도를 한 눈에 볼 수 있고, 이슈들을 하나의 작업(task)로 나타내서 그 작업이 어느정도 진행되었는지 확인하고 관리할 수 있는 메뉴이다. (원하는 뷰 형식으로 사용할 수 있다. 보통은 칸반 보드 형태로 사용하는 것 같다.)

***

**project 생성**
-----
- 먼저 Project를 생성하고, 위의 칸반 보드 형태로 구성해 작업에 대한 진행도를 확인하고 관리할 수 있도록 구성해볼 것이다.
자신의 github home에서 `Projects` -> `New project`
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/2a697317-052d-4397-b804-a420eba48eaa/image.png)

- 다음으로 아래와 같은 화면이 보인다. Board 형태로 진행할 것이니 `Board`를 선택하고 `Create` 한다
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/d0c3c519-cbae-4add-a056-8f6b9ee85b2f/image.png)

- 생성이 완료되면 아래와 같이 빈 보드가 생성이 된다.
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/37f0da91-0ac4-4840-a1c8-c49b640f64c6/image.png)

- 보드 안에 들어가게 될 이슈에 해당 프로젝트를 할당하게 되면, 이슈가 연결되어 작업 진행도를 한눈에 파악할 수 있게된다.

- 또한, 보드 아래의 `+ Add item`를 하게 되면 item이 등록되고, 작업을 나타낼 수 있는것은 물론 그 자리에서 issue로 컨버팅이 가능하다.
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/1a1224e9-e7fc-450d-b5ee-2f2a91c6d84f/image.png)

***

**이슈 생성 및 할당**
-----

- 제일 먼저, 위에서 생성한 project를 레포지토리에 등록해줘야 한다.
`repository` -> `Projects` -> `Add project`
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/97ea2e37-0c41-4ab6-a9b5-2d9c2ddddaae/image.png)

- 다음으로 `issue` 등록하기 위해 이동한다.
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/1e3b3a48-ea15-47b3-833d-e0f7c5979d45/image.png)

- `Issue` -> `New issue` 를 누르면 나오는 등록 화면은 다음과 같다.
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/2966aae9-f2cf-4433-9c0a-ab26288e03ef/image.png)

- 해당 이슈에 대한 제목과 코멘트를 작성해야하고,
중요한 것은 오른쪽의 4가지 항목이다.
> - Assignees : 담당자
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/0041b6b2-f21b-4c4c-8110-701b013a8a6d/image.png)
***
> - Labels : 해당 작업의 유형
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/63fa292f-7223-4925-ae20-d9e508dcd010/image.png)
> - Label 항목에서 bug 등 기본항목을 전부 지우는 게 가능하고, 취향대로 커스터마이징이 가능하다.
***
> - Projects : 연결할 project (진행도를 한번에 볼 수 있는 메뉴)
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/4009a0cd-ee01-46b4-ae37-695f8a7b9ee1/image.png)
***
> - Milestone : 프로젝트가 도달해야하는 목표지점
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/2fcef528-d06d-426d-973b-06694796a85b/image.png)
> - Milestone을 사용하면, 한 가지의 목표에 여러 이슈가 등록되어 있을 때 해당 목표의 진행도가 얼마나 되는지 게이지 바 형태로 볼 수 있다. (위 이미지에서 [테스트] 를 선택했을 때)
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/99af0467-52d9-40a1-9134-027e9954d137/image.png)
> - 생성법 : `issue` -> `Milestones` -> `New milestone`
![Alt text](https://velog.velcdn.com/images/dohaeng0/post/80032a15-dff9-457a-9cb4-3b05afabd044/image.png)![Alt text](https://velog.velcdn.com/images/dohaeng0/post/93a6c862-df8f-4cca-a7b2-9a70b404e5e4/image.png)
