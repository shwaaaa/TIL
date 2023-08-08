# Gradients

- SwiftUI에서는 배경색을 그라데이션으로 지정해 줄 수 있습니다.

## LinearGradient
- colors: 색상 입력
- startPoint: 시작 지점
- endPoint: 종료 지점

```swift
LinearGradient(gradient: Gradient(colors: [.green, .white]), startPoint: .top, endPoint: .bottom)  
```
```swift
Rectangle()
    .fill( 
        LinearGradient(gradient: Gradient(colors: [.green, .white]), startPoint: .top, endPoint: .bottom))
    .frame(width:200,height:200)
```
![image](https://cdn.discordapp.com/attachments/1098858102582956064/1138410911019839529/2023-08-08_6.58.27.png)

***

## RadialGradient(원형 그라데이션)
- colors: 색상 입력
- center: 중앙 지점
- startRadius: 시작 각도
- endRadius: 종료 각도

```swift
RadialGradient(gradient: Gradient(colors: [.green, .white]), center: .center, startRadius: 20, endRadius: 200)
```
![image](https://cdn.discordapp.com/attachments/1098858102582956064/1138411981582372916/2023-08-08_7.02.43.png)

## Angular Gradient
- colors: 색상 입력
- center: 중앙 지점

```swift
AngularGradient(gradient: Gradient(colors: [.red, .orange, .yellow, .green, .blue, .purple, .red]), center: .center)
```
![image](https://cdn.discordapp.com/attachments/1098858102582956064/1138412426056978523/2023-08-08_7.04.27.png)

## Text 배경에 적용시키기 `.background`
```swift
Text("치즈 베이글")
    .frame(width:300,height:100)
    .background(
        LinearGradient(gradient: Gradient(colors [.yellow, .white]), startPoint: .leading, endPoint: .trailing))
```
![image](https://cdn.discordapp.com/attachments/1098858102582956064/1138414591546773504/2023-08-08_7.13.04.png)

## 도형 안에 그라데이션 채우기 `.fill( )`
```swift
Circle()
    .fill(
        AngularGradient(colors: [.blue, .green, .purple, .blue], center: .center))
```
![image](https://cdn.discordapp.com/attachments/1098858102582956064/1138415957354745916/2023-08-08_7.18.29.png)

## 도형 테두리에 그라데이션 채우기 `.strokeBorder( )`
```swift
Circle()
    .strokeBorder(
        AngularGradient(colors: [.blue, .green, .purple, .blue], center: .center))
```
![image](https://cdn.discordapp.com/attachments/1098858102582956064/1138416722320293938/2023-08-08_7.21.01.png)