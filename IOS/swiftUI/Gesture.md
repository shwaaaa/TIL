# Gesture
SwiftUI는 간편하고 직관적인 방식으로 다양한 제스처를 지원한다.

## TapGesture

- `TapGesture`는 화면을 짧게 탭하여 콘텐츠와 버튼과 같은 상호 작용을 구현하는 데 사용된다.

- 탭 동작은 화면을 짧게 터치하는 하나 이상의 손가락을 감지한다.

- 이러한 제스처에 사용되는 손가락은 초기 터치 지점에서 크게 움직여서는 안 되며, 손가락이 화면을 터치해야 하는 횟수를 구성할 수 있다.

- 탭 제스처는 `Gesture`라는 수정자를 사용하고 `TapGesture`라는 구조체를 추가하여 뷰에 직접 적용하면 된다.

```swift
@State private var showName = false

var body: some View {
    Text(showName ? "승황" : "")
        .frame(maxHeight: 200)
        .background(Color.green)
        .gesture(TapGesture().onEnded({ _ in 
            withAnimation { 
                showName.toggle() 
            } 
        }))
     } 
```

***

## LongPressGesture

사용자가 지정한 시간 이상 View를 누르고 있는 경우를 인식한다.

```swift
@State private var isCompleted: Bool = false
    @State private var isSuccess: Bool = false
    
    var body: some View {
        VStack {
            Rectangle()
                .fill(Color.green)
                .frame(maxWidth: isCompleted ? .infinity : 0)
                .frame(height: 55)
                .background(.gray)
            
            Text("Click Click")
                .foregroundStyle(Color.white)
                .background(Color.green)
                .onLongPressGesture(minimumDuration: 1.0, maximumDistance: 50) { isPressing in
                        if isPressing {
                            withAnimation(.easeInOut(duration: 1.0)) {
                                isCompleted.toggle()
                            }
                        } else {
                            DispatchQueue.main.asyncAfter(deadline: .now() + 0.1) {
                                if !isSuccess {
                                    withAnimation(.easeInOut) {
                                        isCompleted = false
                                    }
                                }
                            }
                        }
                    } perform: {
                        withAnimation(.easeInOut) {
                            isSuccess = true
                        }
                }
        }
    }
```

***

## DragGesture

`DragGesture`는 `TapGesture`와 함께 가장 자주되는 제스처 중 하나이며 특정 오브젝트를 `move`, `drag`, `swipe`하는 데 사용되는 제스처이다.

***

## Rotation Gesture

`rotationGesture`는 사용자가 화면에서 두 손가락으로 회전 동작을 수행할 때 발생하며, 주로 이미지나 뷰의 회전에 활용된다. 

```swift
State private var rotation: Angle = .degrees(40)

    var body: some View {
        Image(systemName: "arrow.right.circle")
            .rotationEffect(rotation)
            .gesture(
                RotationGesture()
                    .onChanged { value in
                        rotation = value
                    }
                )
        }
```

***

## Magnification Gesture

핀치 제스처를 감지하는 제스처로 주로 특정 오브젝트의 스케일을 조정, 확대 및 축소 효과를 보이도록 구현한다.

```swift
 @State private var currentAmount: CGFloat = 0
        var body: some View {
            VStack(spacing: 10) {
                HStack {
                    Circle().frame(width: 35, height: 35)
                    
                    Text("2is.hwa")
                    
                    Spacer()
                    
                    Image(systemName: "ellipsis")
                }
                .padding(.horizontal)
                
                Rectangle().frame(height: 300)
                    .frame(height: 300)
                    .scaleEffect(1 + currentAmount)
                    .gesture(
                        MagnificationGesture()
                            .onChanged { value in
                                currentAmount = value - 1
                            }
                            .onEnded { value in
                                currentAmount = 0
                            }
                    )
                HStack {
                    Image(systemName: "heart.fill")
                    Image(systemName: "text.bubble.fill")
                    
                    Spacer()
                }
                .padding(.horizontal)
                .font(.headline)
                
                Text("🐙")
                    .frame(maxWidth: .infinity, alignment: .leading)
                    .padding(.horizontal)
            }
        }
```