# Async/await

swift 개발에서 `Closure` 및 `completion handlers`를 사용하는 `asynchronous(비동기)` 프로그래밍을 많이 한다.

이러한 이유로 많은 비동기 작업 / 오류 처리 / 비동기 호출간의 제어 흐름이 복잡할 때 문제가 된다.

***

1. 많은 비동기 작업
일련의 비동기 작업에는 deeply-nested closures가 필요

```swift
func processImageData1(completionBlock: (_ result: Image) -> Void) {
    loadWebResource("dataprofile.txt") { dataResource in
        loadWebResource("imagedata.dat") { imageResource in
            decodeImage(dataResource, imageResource) { imageTmp in
                dewarpAndCleanupImage(imageTmp) { imageResult in
                    completionBlock(imageResult)
                }
            }
        }
    }
}

processImageData1 { image in
    display(image)
}
```

***

2. 오류 처리
콜백은 오류처리를 어렵고 매우 장황하게 만든다

``` swift
func processImageData2c(completionBlock: (Result<Image, Error>) -> Void) {
    loadWebResource("dataprofile.txt") { dataResourceResult in
        switch dataResourceResult {
        case .success(let dataResource):
            loadWebResource("imagedata.dat") { imageResourceResult in
                switch imageResourceResult {
                case .success(let imageResource):
                    decodeImage(dataResource, imageResource) { imageTmpResult in
                        switch imageTmpResult {
                        case .success(let imageTmp):
                            dewarpAndCleanupImage(imageTmp) { imageResult in
                                completionBlock(imageResult)
                            }
                        case .failure(let error):
                            completionBlock(.failure(error))
                        }
                    }
                case .failure(let error):
                    completionBlock(.failure(error))
                }
            }
        case .failure(let error):
            completionBlock(.failure(error))
        }
    }
}

processImageData2c { result in
    switch result {
    case .success(let image):
        display(image)
    case .failure(let error):
        display("No image today", error)
    }
}
```

`Swift.Result`가 Swift 5.0에서 추가되면서 error를 처리하는게 더 쉬워졌지만, 여전히 closure 중첩 문제는 남아있다.

***

3. 비동기 호출간의 제어 흐름이 복잡
예를들어, 이미지를 얻은 후 `swizzle`해야한다고 할 때,

1. 이미지가 있으면 바로 swizzle
2. 이미지가 없으면 decode후 swizzle

그렇기 떄문에 아래와 같은 코드가 필요하다
```swift
func processImageData3(recipient: Person, completionBlock: (_ result: Image) -> Void) {
    let swizzle: (_ contents: Image) -> Void = {
      // ... continuation closure that calls completionBlock eventually
    }
    if recipient.hasProfilePicture {
        swizzle(recipient.profilePicture)
    } else {
        decodeImage { image in
            swizzle(image)
        }
    }
}
```

이 패턴은 함수의 자연스러운 하향식 구성을 반전시키며,

swizzle closure가 completion handler에서 사용되므로 capture에 대해 신중하게 생각해야한다.

***

4. 실수하기 쉽다

```swift
func processImageData4a(completionBlock: (_ result: Image?, _ error: Error?) -> Void) {
    loadWebResource("dataprofile.txt") { dataResource, error in
        guard let dataResource = dataResource else {
            return // ⚠️ <- forgot to call the block 
        }
        loadWebResource("imagedata.dat") { imageResource, error in
            guard let imageResource = imageResource else {
                return // ⚠️ <- forgot to call the block 
            }
            ...
        }
    }
}
```

completionBlock을 호출하지 않고 그냥 return하고 잊어버리면 디버깅하기 어렵다.

***

이러한 문제를 해결하기 위해  async-await proposal은 Swift에 코루틴(coroutine) 모델을 도입했다.
> 비동기 함수의 semantics 정의 But 동시성을 제공하지는 않음. 

***

## 비동기함수(async/await)를 사용하면?

- 비동기 코드를 마치 동기 코드인것 처럼 작성 할 수 있다
> 프로그래머가 동기 코드에서 사용할 수 있는 동일한 언어 구조를 최대한 활용 가능

- 비동기 코드의 성능 향 (better performance for asynchronous code)

- 코드를 디버깅, 프로파일링 및 탐색하는 동안 보다 일관된 경험을 제공하기 위한 더 나은 도구 (better tooling to provide a more consistent experience while debugging, profiling, and exploring code)

- 작업 우선 순위 및 취소와 같은 동시성 기능을 위한 기반(a foundation for future concurrency features like task priority and cancellation)

***

## 사용법
아까 봤던

```swift
func processImageData1(completionBlock: (_ result: Image) -> Void) {
    loadWebResource("dataprofile.txt") { dataResource in
        loadWebResource("imagedata.dat") { imageResource in
            decodeImage(dataResource, imageResource) { imageTmp in
                dewarpAndCleanupImage(imageTmp) { imageResult in
                    completionBlock(imageResult)
                }
            }
        }
    }
}

processImageData1 { image in
    display(image)
}
```

이 코드를 `async/await`를 사용하여 리팩토링하면,

```swift
func loadWebResource(_ path: String) async throws -> Resource
func decodeImage(_ r1: Resource, _ r2: Resource) async throws -> Image
func dewarpAndCleanupImage(_ i : Image) async throws -> Image

func processImageData() async throws -> Image {
  let dataResource  = try await loadWebResource("dataprofile.txt")
  let imageResource = try await loadWebResource("imagedata.dat")
  let imageTmp      = try await decodeImage(dataResource, imageResource)
  let imageResult   = try await dewarpAndCleanupImage(imageTmp)
  return imageResult
}
```

이렇게 마치 동기적으로 일어나는 것 처럼 코드를 작성할 수 있게 된다. 

***

## async
- 함수를 비동기 함수로 만들겠다. 

특징
1. 프로토콜에서도 요구 가능하다.
```swift
protocol SomeDelegate {
    func process() async
}
```

2. async와 throws를 같이 쓸 수 있다.
```swift
func getData() ✅ async throws ✅ -> Data {
    let url = URL(string: "https://zeddios.tistory.com")!
    let data = try Data(contentsOf: url)
    return data
}
```
주의할 점은 반드시 async 키워드가 throws키워드 보다 먼저 선언되어야 한다. 

***

## await
비동기 함수 호출시 potential suspension point(잠재적인 일시 중단 지점) 지정

```swift
func process() async {
   let data = await self.getData()
   let contents = await self.decode(data: data)
   print(contents)
}
```

예를 들어, getData(), decode()를 호출하는 동안 작업이 일시 중단 되어야한다.

따라서 각 비동기 함수 호출 지점에는 potential suspension point(잠재적인 일시 중단 지점)이 있어야 하고 그것을 await로 할 수 있다.