'use strict';

//Variable 변수

let name = 'ellie';
console.log(name);
name = 'hello';
console.log(name);


//constants 한 번 지정하면 절대 변하지않는 변수

const daysInWeek=7;
const maxNumber=5;

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

17:43