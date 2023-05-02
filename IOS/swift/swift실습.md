import Swift


var name:String="seunghwa"
let birthday = 2007

"\(birthday)에 태어난 \(name)입니다"
var language = ["swift","java","kotlin"]
var handsomeman=[
    "서강준":"김재균",
    "원빈":"정상혁",
    "박서준":"방가온",
    "강하늘":"엄지성",
]

language[0]//swift
handsomeman["서강준"]//김재균

var age = 19
var student=""

if age >= 8 && age < 14{
    student="초등학생"
} else if age < 17{
    student="중학생"
}else if age < 20{
    student="고등학생"
}else{
    student="기타"
}

"\(student)"
