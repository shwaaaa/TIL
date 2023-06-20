// #include <stdio.h>
// int main(){
//     int a = 5;
//     char b = 'e';
//     float c = 0.3;

//     //포인터 변수 선언할 때
//     //포인터가 가리키는 데이터 자료형과 일치하도록 자료형 선언
//     int* ap = &a; //포인터를 선언과 동시에 초기화
//     char* bp = &b;
//     float* cp = &c;

//     printf("a의 주소 :%p\n", ap);
//     printf("b의 주소 :%p\n", bp);
//     printf("c의 주소 :%p\n", cp);

//     printf("ap의 크기 :%d\n", sizeof(ap));
//     printf("bp의 크기 :%d\n", sizeof(bp));
//     printf("cp의 크기 :%d\n", sizeof(cp));

//     printf("a의 값 :%d\n", *ap);
//     printf("b의 값 :%c\n", *bp);
//     printf("c의 값 :%.1f\n", *cp);
// }


// //10-1
// #include<stdio.h>
// void get_sum_diff(int x, int y, int* p_sum, int* p_diff);
// int main(){
//     int sum = 0, diff = 0;
//     get_sum_diff(100, 200, &sum, &diff);
//     printf("합 = %d\n", sum);
//     printf("차 = %d\n", diff);
//     return 0; 
// }
// void get_sum_diff(int x, int y, int* p_sum, int* p_diff){
//     *p_sum = x+y;
//     *p_diff = x-y;
//     return;
// }


//10-2
// #include<stdio.h>
// void get_int(int* px, int* py);
// int main(void){
//     int x, y;
//     get_int(&x, &y);
//     printf("정수의 합은 %d\n", x+y);
//     return 0;
// }
// void get_int(int* px, int* py){
//     scanf("%d %d", px, py);
// }


// #include <stdio.h>
// int main(){
//     int a[] = {1, 2, 3, 4, 5};
//     printf("%d\n");

//     for(int i=0; i<5; i++){
//         printf("값 = %d,주소 = %d\n", a[i], &a[i]);
//         printf("값 = %d, 주소 = %d\n",*(a+i),a+i);
//     }
// }

// #include <stdio.h>
// int main() {
//     //포인터에 배열을 대입했을 경우
//     int a[] = {10, 20, 30, 40, 50};
//     int* p = a;

//     //a++ 절대 X
//     //p++ 가능
//     //포인터를 사용해서 배열 데이터 출력하기
//     printf("주소 : %d\n", p);
//     printf("데이터 : %d\n", *p);

//     //반복문 사용해서 배열 전체 데이터 출력하기
//     for (int i=0; i<5; i++){
//         printf("주소 : %d, 데이터 : %d\n", p+i, *(p+i));
//         printf("주소 : %d, 데이터 : %d\n", &p[i], p[i]);
//         printf("\n");
//     }
// }


// //p.11 21-1번
// #include <stdio.h>
// int main(){
//     int a[5] = {1, 2, 3, 4, 5};
//     int result = 0, i = 0;
//     int* p = a;
//     for(i=0; i<5; i++) {
//         result = result + *(p+i);
//     }
//     printf("배열의 합 = %d", result);
// }


// #include <stdio.h>'
// #include <string.h>
// int main(){
//     //1. 배열로 문자열 처리
//     char a[] = "apple";
//     char b[10];
//     strcpy(a, "hello");
//     strcpy(b, a);
//     printf("%s\n", a); //apple
//     printf("%s\n", b);

//     //strlen()함수 문자길이 변환
//     char c[] = "icecream";
//     printf("%s의 길이 : %d\n", c, strlen(c));

//     //strcmp 함수
//     //같으면 0
//     //뒤가 더 크면 음수
//     //앞이 더 크면 양수
//     char d[] = "abzd";
//     char e[] = "abgd";
//     printf("%d\n", strcmp(d,e));

//     //strcat(s1, s2) 함수 : s1 끝에 s2 결합,
//     //s1의 문자열 크기 주의
//     char f[20] = "ice";
//     char g[] = "cream";
//     strcat(f,g);
//     printf("%s\n", f);


// }


//     //2. 포인터로 문자열 처리
//     // c언어 모든 변수는 데이터 세그먼트 영역에 저장
//     // -> 읽기, 쓰기 다 가능

//     //"hello"는 문자열 상수
//     //문자열 상수는 텍스트 세그먼트 영역에 저장
//     // -> 읽기만 가능

//     char* p = "hello";
//     // 문자열 상수는 읽기 전용이기 때문에 쓰기 안됨
//     // p[0] = 'A'
//     p = "apple";
//     printf("%s의 주소 : %p, 크기 : %d\n", p, p, sizeof(p));

//     p = "how are you";
//     printf("%s의 주소 : %p, 크기 : %d", p, p, sizeof(p));

// }


// // p.11 21-2번
// #include <stdio.h>
// #include <string.h>
// int StringPointer(char* s);
// int main(){
//     int len;
//     char string[100] = "";

//     printf("문자열 입력");
//     gets(string);// enter 입력 전까지 모두 입력받음, 공백포함

//     printf("문자열 길이: %d\n", StringPointer(string));
// }
// int StringPointer(char* s){
//     int len = 0;
//     while(*s !='\0'){
//         len++;
//         s++;
//     }
//     return len;
// }


// // p.11 21-3번
// #include <stdio.h>
// void Stringcopy(char* pa, char* pb);
// int main() {
//     char a[20] = "I LOVE YOU";
//     char b[20];
//     Stringcopy(a, b);
//     printf("a 배열 : %s\n", a);
//     printf("b 배열 : %s\n", b);
// }

// void Stringcopy(char* pa, char* pb){
//     while(*pa != '\0'){
//         *pb++ = *pa++;
//     }
// }