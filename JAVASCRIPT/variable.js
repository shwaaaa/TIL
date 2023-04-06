'use strict';

//Variable 변수, rw(read/write)
//let (added in ES6)
let name = 'ellie';
console.log(name);
name = 'hello';
console.log(name);


//constants 한 번 지정하면 절대 변하지않는 변수, r(read only)
//use const whenever possible.
//only use let if variable needs to change.
const daysInWeek=7;
const maxNumber=5;

//Note!
//favor immutable data type always for a few reasons:
//-security
//-thread safety
//-reduce human mistakes

//Variable types
//primitive, single item: number, string, boolean, null, undefiedn, symbol
//object, box container
//function, first-class function
const count = 17; //integer
const size = 17.1; //decimal number
console.log('value: ${count}, type: ${typeof count}');
console.log('value: ${size}, type: ${typeof size}');

//number - special numeric values: infinity, -infinity, NaN
const infinity = 1/0;
const negativeInfinity = -1/0;
const nAn = 'not a number' / 2;
console.log(infinity);
console.log(negativeUnfinity);
console.log(nAn);

//string
const char ='c';
const brendan = 'brendan';
const greeting = 'hello' + breedan;
console.log('value: ${greeting}, type: ${typeof greeting}');
const helloBob = 'hi ${brendan}!'; //template literals (string)
console.log('value: ${helloBob}, type: ${typeof helloBob}');
console.log('value: ${test}, type: ${typeof test}');

//boolean
//false: 0, null, undefined, NaN, ''
//true: ant other value
const canRead = true;
const test = 3<1; //false
console.log('value: ${canRead}, type: ${typeof canRead}');
console.log('value: ${test}, type: ${typeof test}');

//null
let nothing = null;
console.log('value: ${nothing}, type: ${typeof nothing}');

//undefined
let x = undefined;
console.log('value: ${x}, type: ${typeof x}');

//symbol, create unique identifiers for objects
const symbol1 = Symbol('id');
const symbol2 = symbol('id');
console.log(symbol1===symbol2);
const gSymbol1 = Symbol.for('id');
const gSymbol2 = Symbol.for('id');
console.log(gSymbol1===gSymbol2); //true
console.log('value: ${symbol1.description}, type: ${typeof symbol1}');

//object, real-life object, data structure
const ellie = {name: 'ellie', age: 20};
ellie.age = 21;

//Dynamic typing: dynamically typed languauge
let text = 'hello';
console.log('value: ${text}, type: ${typeof text}'); 
text = 1;
console.log('value: ${text}, type: ${typeof text}'); 
text = '7' + 5;
console.log('value: ${text}, type: ${typeof text}'); 
text = '8'/'2';
console.log('value: ${text}, type: ${typeof text}'); 

3:10 #4