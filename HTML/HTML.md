***HTML 문서 기본 구조***
----------------------------
- **< !DOCYTPE>**: 현재 문서의 HTML타입을 정의하며 HTML5의 경우 < DOKTYPE html>로 명시함

- **< HTML>**: HTML 문서의 시작과 끝을 표시

- **< head>**: 웹 페이지 문서에 대한 정보로 메타데이터(metadata)를 정의
>- < style>,< meta>,< link>,< script>,< base> 태그 등 정의
>- < title>: HTML 문서 제목(title) 정의

- **< body>**: 내부에 웹 페이지의 실제적인 내용(content)을 작성
>- < h1>~< h6>: 제목(heading) 정의
>- < p>: 단락(paragraph) 정의

***

***태그 사용 방법***
------------------------
<태그> 내용 </태그>

- title 태그
>웹사이트 제목

- H1~H6 태그
>1부터 6까지의 숫자는 글자의 크기의 차이를 의미(1이 가장 큼)
```
<h1>H1</h1>
<h2>H2</h2>
<h3>H3</h3>
<h4>H4</h4>
<h5>H5</h5>
<h6>H6</h6>
```

- pre 태그
>텍스트 그대로 화면에 표시할 때 사용하는 태그

- p 태그
>문단을 넣을 때 사용되는 태그

- input 태그
>입력창을 의미, 내용이 없기 떄문에 닫는 태그 불필요

```
<input type="text">
```

**type**라고 보이는 이 부분은 해당 태그의 속성
type=text라는 뜻은 type이라는 속성의 값이 text임을 의미

- botton 태그
>말 그대로 버튼
```
<botton style="width:250px; height:100px; front-size: 50px;">버튼</botton>
```

  html의 태그들은 style 속성으로 외형을 커스터마이징 할 수 있음
 ```
 <input type="text" style="width: 500px; height: 100px; front-sixe: 90px;">
 ```
 >디테일한 스타일링은 css파일을 따로 만들어서 작성

- 버튼 두개 출력
 ```
 <input type="text" style="width: 500px; height: 100px; front-sixe: 90px;">
 <botton style="width:250px; height:100px; front-size: 50px;">버튼</botton>
 <botton style="width:250px; height:100px; front-size: 50px;">버튼2</botton>
 ```

 - div 태그
 >여러개의 태그들을 구역으로 묶거나 나눌 떄 사용하는 태그
  ```
  <div>
  <botton style="width:250px; height:100px; front-size: 50px;">버튼</botton>
  <botton style="width:250px; height:100px; front-size: 50px;">버튼2</botton>
  </div>
  ```

  - br 태그
 >줄 바꿈
 >종료태그가 없음

 - hr 태그
 >수평선을 표시하는 태그
 >마찬가지로 종료태그가 없음
  
  - strong 태그
 >텍스트 강조

 - a 태그
 >다른 웹사이트로 가는 링크를 걸어주는 태그(href속성에 링크 넣기)
 ><a href="링크 주소">링크</a>

 - IMG 태그
 >이미지 담당(src속성 안에 이미지 주소 넣기)

 - ul 태그 & ol 태그
 >둘 다 리스팅에 사용
 > **ul** ul 태그 안에 li 태그를 넣고 그 안에 내용 넣기
 > **ol** ol도 사용방법 동일하지만 ol은 앞에 자동으로 넘버링이 붙음

 - dl 태그
 >정의 리스트(definitionlist)
 ><dl>태그를 사용하여 전체 리스트 표현
 >각 항목은 <dt> 태그를 사용하며 각 설명은 <dd>태그를 사용
 
 - table 태그
 >주로 표를 만들 때 사용됨
 > table 태그 안에 내용이 되는 태그들을 집어넣어야함
 > tr(테이블의 한 행)
 > 첫 행에는 th 즉 테이블 헤더를 칸 수에 맞게 배치
 > 그리고 다음 tr 안에는 td 태그로 테이블의 내용을 헤더 칸에 맞게 배치
 > 마지막으로 caption 태그로 테이블의 이름 정해주기

 - form 태그
  >회원가입이나 로그인 같이 특정 정보들을 묶어서 하나의 폼으로 제출해야 할 때 사용되는 태그
   ```
   <form>
   <input type="text" style="front-size: 30px;">
   <input type="email" style="front-size: 30px;">
   <input type="password" style="front-size:30px;">
   <input type="date" style="front-size: 30px;"><br/>
   <input type="checkbox" style="front-size: 30px;">체크박스</input><br/>
   </form>
   ```
  **type**은 이 입력창이 어떤 정보를 받아들일지에 대한 속성이다.

 - select 태그
 >항목 선택을 위한 태그
 >여러 선택지 중에 하나를 골라야 할 때 자주 사용됨
 >select태그가 여러 개의 option 태그들을 감싸는 형태
 ```
 <select name="이름">
 <option value="값">
 ```

***

**HTML 주석(Comments)**
-------------------------
```
<!-- 주석 -->
```
- 주석은 웹 브라우저가 해석하지 않으며 사용자에게도 보여지지 않음
- 코드의 설명을 위해 작성

***

**HTML 문서 작성 규칙**
------------------------
```
<html>
<title>공백 처리 예제</title>
<body>
  공             백
  줄바꿈
  줄바꿈
</body>
</html>
```
>- content 내의 연속된 공백 또는 줄 바꿈은 하나의 공백으로 처리
>- 여러 개의 공백이나 탭,줄 바꿈 등은 다른 특수문자를 사용하여 표현
>- 각 태그의 시작 태그와 종료 태그 쌍이 서로 교차되면 안됨
>- 태그는 포함관계를 들여쓰기를 통해 표시하여 작성

***

**텍스트 서식 태그**
---------------------

```
<b>~</b> : 굵게(bold)
<i>~</i> : 이텔릭(italic)
<ins>~</ins> : 밑줄(insert)
<del>~</del> : 가운데 선
<mark>~</mark> : 하이라이트
<strong>~</strong> : 중요
<code>~</code> : 코드
<em>~</em> : 강조(emphasized text)
<sup>~</sup> : 위 첨자(superscript)
<sub>~</sub> : 아래 첨자(subscript)
```