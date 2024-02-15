# keychain

## keychain service

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FxmOqF%2FbtrKFBBU1nn%2FRNTMlbD3rDyruahNyAN4n0%2Fimg.png)

`Keychain service`란 사용자 대신 작은 데이터 덩어리(small chunks of data)를 안전하게 저장하기 위한 기능이다.

사용자는 자신의 비밀 데이터를 저장하고 싶을 때, `Keychain`이라 불리는 **암호화된 데이터베이스**에 정보를 저장할 수 있다.

이게 왜 필요할까? 사용자가 비밀번호 등의 데이터를 일일이 기억하는 것이 번거롭기 때문이다.

Keychain service API는 앱에게 작은 데이터를 Keychain에 저장할 수 있는 메커니즘을 제공한다.

**작은 데이터**란 비밀번호, 신용카드 정보, 짧은 메모 등의 기밀 정보, 그리고 사용자가 인지하지 못하는 암호키 (cryptographic keys), 인증서 등을 말한다.

***

## Keychain Item

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbN1zzU%2FbtrKHbvbhi8%2FPRxrcvveJK1AfFAWUIyDeK%2Fimg.png)

`Keychain`에 비밀번호와 같은 정보를 저장하기 위해서는 `keychain item`을 사용해야 한다.

`Keychain item`을 사용할때는,

저장하려고 하는 정보와 함께 `item`에 접근성을 제어하고 검색 가능하게끔 하는 공개된 여러 특성들을 함께 제공해야 한다

**Item = Data + Attributes**

### Attributes
`Attributes` 는 크게 3개의 정보를 갖고 있다.

1. 어떤 종류의 비밀정보인가? (위에서 언급한 4가지의 경우) - Item Class Keys and Values
2. Item은 어떠한 속성을 갖고 있는가? - Item Attribute Keys and Values
3. 저장해둔 Keychain을 다시 찾기 위해서 어떤 고유값을 가져야 하는가? - Item Attribute Keys and Values

물론 크게 3개의 정보를 갖고 있다고 생각을 하는 것이지 이는 해석에 따라 달라질 수 있다.

먼저 어떤 종류를 가지는지는 여러 특성키를 통해 나타내게 된다.
- kSecClassGenericPassword - 비밀번호
- kSecClassInternetPassword - 인터넷 비밀번호
- kSecClassCertificate - 인증서
- kSecClassIdentity - ID
- kSecClassKey - 암호화된 키

이 5개가 위에서 말한 어떤 종류의 비밀정보인가를 나타내게 된다.