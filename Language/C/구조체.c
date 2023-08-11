// #include <stdio.h>
// #include <string.h>
// struct student{
//     int number;
//     char name[10];
//     double grade;
// };

// int main() {
//     struct student s1;
//     s1.number = 1114;
//     s1.grade = 100;
//     strcpy(s1.name, "이승화");

//     printf("학번 : %d\n", s1.number);
//     printf("이름 : %s\n", s1.name);
//     printf("성적 : %.1f\n", s1.grade);

//     struct student s2 = {1112, "김얼수", 57.4};
//     printf("학번 : %d\n", s2.number);
//     printf("이름 : %s\n", s2.name);
//     printf("성적 : %.1f\n", s2.grade);

//     struct student s3;
//     scanf("%d", &s3.number);
//     scanf("%s", s3.name);
//     scanf("%lf", &s3.grade);
//     printf("학번 : %d\n", s3.number);
//     printf("이름 : %s\n", s3.name);
//     printf("성적 : %.1f\n", s3.grade);

//     struct student s4;
//     s4 = s3; //동일한 구조체일 경우
//     printf("학번 : %d\n", s4.number);
//     printf("이름 : %s\n", s4.name);
//     printf("성적 : %.1f\n", s4.grade);
// }


// //p4
// #include <stdio.h>
// #include <string.h>
// struct student{
//     char name[10];
//     int number;
//     int korean;
//     int math;
//     int english;
//     float average;
// };
// int main() {
//     struct student s1;
//     scanf("%s", s1.name);
//     scanf("%d", &s1.korean);
//     scanf("%d", &s1.math);
//     scanf("%d", &s1.english);

//     s1.average = (s1.korean+s1.math+s1.english)/3.0;

//     printf("이름 : %s\n", s1.name);
//     printf("국어점수 : %d\n", s1.korean);
//     printf("수학점수 : %d\n", s1.math);
//     printf("영어점수 : %d\n", s1.english);
//     printf("평균: %.2f", s1.average);

// }


// //p5
// #include<stdio.h>
// #include <string.h>
// struct student {
//     char name[10];
//     int year;
// };

// int main() {
//     struct student s[3] = {{"수영",22},{"윤아",20},{"서현",23}};
//     strcpy(s[2].name, "유리");
//     s[2].year = 20;
//     for(int i = 0; i<3; i++) {
//         printf("%s, %d\n", s[i].name, s[i].year);
//     }
// }


// #include<stdio.h>
// struct member {
//     char name[10];
//     char gender;
//     int age;
// };

// int main() {
//     struct member m = {"홍길동", 'b', 20};
//     struct member *p = &m;
//     printf("%s %c %d\n", (*p).name, (*p).gender, (*p).age);
//     printf("%s %c %d\n", p->name, p->gender, p->age); //별표 백만개
// }


// #include <stdio.h>
// struct date {
//     int year, month, day;
// };
// struct member{
//     char name[10];
//     int age;;
//     struct date* sd; //구조체 date를 가리키는 포인터 선언
// };

// int main(){
//     struct date d = {2023,7,11};
//     struct member m = {"이승화",20};
//     m.sd = &d;
//     printf("%s %d",m.name,m.age);
//     printf("%d %d %d",m.sd->year,m.sd->month,m.sd->day);
// }


// //p11
// #include <stdio.h>
// typedef struct date {
//     int year, month, day;
// }dd;

// typedef struct student {
//     char name[10];
//     int number;
//     struct date* sd;
// }mm;

// int main(){
//     dd d = {2002, 05, 05};
//     mm m = {"이승화", 20251234};
//     m.sd = &d;
//     printf("학번 : %d\n", m.number);
//     printf("성명: %s\n", m.name);
//     printf("%d %d %d", m.sd->year,m.sd->month,m.sd->day);

// }


//p12
#include <stdio.h>
typedef struct pummok {
    char pum[10];
    int su,dan,geum;
}pp;
int main(){
    for(int i = 0; i<3; i++) {
        
    }
}