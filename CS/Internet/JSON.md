***JSON***

***

**JSON이란?**
-------------

**JavaScript Object Notation**라는 의미의 축약어로 데이터를 저장하거나 전송할 때 많이 사용되는 경량의 DATA 교환 형식이다.

- Javascript에서 객체를 만들 때 사용하는 표현식을 의미한다.
- JSON 표현식은 사람과 기계 모두 이해하기 쉬우며 용량이 작아서, 최근에는 JSON이 XML을 대체해서 데이터 전송 등에 많이 사용한다.
- JSON은 데이터 포맷일 뿐이며 어떠한 통신 방법도, 프로그래밍 문법도 아닌 단순히 데이터를 표시하는 표현 방법일 뿐이다.

***

**JSON 특징**
-------------

- 서버와 클라이언트 간의 교류에서 일반적으로 많이 사용된다.
- 자바스크립트 객체 표기법과 아주 유사하다.
- 자바스크립트를 이용하여 JSON 형식의 문서를 쉽게 자바스크립트 객체로 변환할 수 있는 이점이 있다.
- JSON 문서 형식은 자바스크립트 객체의 형식을 기반으로 만들어졌다.
- 자바스크립트의 문법과 굉장히 유사하지만 텍스트 형식일 뿐이다.
- 다른 프로그래밍 언어를 이용해서도 쉽게 만들 수 있다.
- 특정 언어에 종속되지 않으며, 대부분의 프로그래밍 언어에서 JSON 포맷의 데이터를 핸들링 할 수 있는 라이브러리를 제공한다.

***

**XML vs JSON**
---------------

데이터를 나타낼 수 있는 방식은 여러가지가 있지만, 대표적인 것이 XML이고, 이후 가장 많이 사용되는 것이 아마도 JSON일 것이다.

**XML**
데이터 값 양쪽으로 태그가 있다.
(HTML을 근본으로 했기에 태그라는 것이 없을 수가 없는데, 그 태그를 줄인다 해도 최소한 표현하려면 양쪽에 몇글자씩이 있어야 한다.)

**JSON**
태그로 표현하기 보다는 중괄호({}) 같은 형식으로 하고, 값을 ','로 나열하기에 그 표현이 간단하다.

***

**JSON 문법**
------------

```
{
  "employees": [
    {
      "name": "Surim",
      "lastName": "Son"
    },
    {
      "name": "Someone",
      "lastName": "Huh"
    },
    {
      "name": "Someone else",
      "lastName": "Kim"
    } 
  ]
}
```
- JSON 형식은 자바스크립트 객체와 마찬가지로 key / value가 존재할 수 있으며 key값이나 문자열은 항상 쌍따옴표를 이용하여 표기해야한다.
- 객체, 배열 등의 표기를 사용할 수 있다.
- 일반 자바스크립트의 객체처럼 원하는 만큼 중첩시켜서 사용할 수도 있다.
- JSON형식에서는 null, number, string, array, object, boolean을 사용할 수 있다.

***

**JSON 형식**
-------------

1. name-value형식의 쌍
  여러가지 언어들에서 object등으로 실현되었다.
  { String key : String value }

```
  {
  "firstName": "Kwon",
  "lastName": "YoungJae",
  "email": "kyoje11@gmail.com"
}
```

2. 값들의 순서화된 리스트 형식
  여러가지 언어들에서 배열(Array) 등으로 실현되었다.
  [value1, value2, ...]

```
  {
  "firstName": "Kwon",
  "lastName": "YoungJae",
  "email": "kyoje11@gmail.com",
  "hobby": ["puzzles","swimming"]
}
```

***

**JSON의 문제점**
----------------

AJAX 는 단순히 데이터만이 아니라 JavaScript 그 자체도 전달할 수 있다. 이 말은 JSON데이터라고 해서 받았는데 단순 데이터가 아니라 JavaScript가 될 수도 있고, 그게 실행 될 수 있다는 것이다. (데이터인 줄 알고 받았는데 악성 스크립트가 될 수 있다.)

위와 같은 이유로 받은 내용에서 순수하게 데이터만 추출하기 위한 JSON 관련 라이브러리를 따로 사용하기도 한다.

***

**JSON이 가져올 수 있는 데이터**
---------------------------

JSON으로 가져올 수 있는 데이터는 해당 자바스크립트가 로드된 서버의 데이터에 한정된다.

예를 들어, http://kwz.kr/json.js에서 불러올 수 있는 데이터는 kwz.kr 서버에 존재하는 것만 가능하다. (구글 데이터를 불러온다거나 네이버 데이터를 불러온다거나 할 수 없다.)

JSON은 단순히 데이터 포맷일 뿐이며 그 데이터를 불러오기 위해선 XMLHttpRequest()라는 JavaScript 함수를 사용해야 하는데 이 함수가 동일 서버에 대한 것만 지원하기 때문이다. ( JSONP 또는 프락시 역할을 하는 서버쪽 Script 파일로 가능하게도 할 수 있다.)

***

**JSON 형식 텍스트를 JavaScript Object로 변환하기**
----------------------------------------------

```
var jsonText = '{ "name": "Someone else", "lastName": "Kim" }';  // JSON 형식의 문자열
var realObject = JSON.parse(jsonText);
var jsonText2 = JSON.stringify(realObject);

console.log(realObject);
console.log(jsonText2);
```

- **JSON.parse( JSON 형식의 문자열 )** : JSON 형식의 텍스트를 자바스크립트 객체로 변환한다.
- **JSON.stringify( JSON 형식의 문자열로 변환할 값 )** : 자바스크립트 객체를 JSON 텍스트로 변환한다.