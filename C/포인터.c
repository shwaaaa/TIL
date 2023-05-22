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

#include <stdio.h>
int main() {
    //포인터에 배열을 대입했을 경우
    int a[] = {10, 20, 30, 40, 50};
    int* p = a;

    //a++ 절대 X
    //p++ 가능
    //포인터를 사용해서 배열 데이터 출력하기
    printf("주소 : %d\n", p);
    printf("데이터 : %d\n", *p);

    //반복문 사용해서 배열 전체 데이터 출력하기
    for (int i=0; i<5; i++){
        printf("주소 : %d, 데이터 : %d\n", p+i, *(p+i));
        printf("주소 : %d, 데이터 : %d\n", &p[i], p[i]);
        printf("\n");
    }
}