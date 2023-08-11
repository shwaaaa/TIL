// #include <stdio.h>
// void Recursive(int num);

// int main(void) {
//     Recursive(5);
//     return 0;
// }

// void Recursive(int num) {
//     if (num <= 0)
//         return;
//     printf("Recursive %d\n", num);
//     Recursive(num - 1);
// }


//팩토리얼 계산
// #include <stdio.h>
// int Fact(int);
// int main() {
//     int input, result;

//     printf("정수 입력:");
//     scanf("%d", &input);

//     result = Fact(input);
//     printf("\n>>결과 %d != %d\n", input, result);
// }

// int Fact(int n) {
//     if (n <= 1)
//         return 1;
//     else {
//         printf(">>수행 %d! : %d * (%d-1)\n", n, n, n);
//         return n * Fact(n - 1);
//     }
// }


//누적 합계 출력 함수
// #include<stdio.h>
// int Sum (int);
// int main() {
//     int input, result;

//     printf("정수 입력:");
//     scanf("%d", &input);

//     result = Sum(input);
//     printf(">>결과 : 1부터 %d까지 합 = %d\n", input, result);
// }

// int Sum(int n) {
//     int sum = 0;
//         if (n <= 1)
//             return 1;
//         else{
//             sum += n;
//             return sum + Sum(n - 1);

//     }
// }


//
// #include <stdio.h>
// int sum (int);
// int main() {
//     int input, result;
//     printf("정수 입력:");
//     scanf("%d", &input);

//     result = sum(input);
//     printf("결과 = %d\n", result);
// }

// int sum(int n) {
//     if (n <= 1)
//         return 1;
//     else {
//         return n * n * n + sum(n - 1);
//     }
// }


//각 자릿수 출력
// #include<stdio.h>
// void show_digit(int n);

// int main() {
//     int input;
//     printf("정수 입력:");
//     scanf("%d", &input);

//     show_digit(input);
//     printf("\n");
// }

// void show_digit(int n) {
//     if (n <= 0)
//         return;
//     else {
//         show_digit(n / 10);
//         printf("%d ", n % 10);
//     }

// }


//제곱
// #include<stdio.h>
// int power(int a,int b);
// int main() {
//     int result;
//     result = power(2, 5);
//     printf("result = %d\n",result);
//     return 0;
// }

// int power(int a, int b) {
//     if (b <= 1)
//         return a;
//     else
//         return a*power(a,b-1);
// }


//gcd함수 유클리드 호제법

//반복함수
// #include <stdio.h>
// int main(){
//     int a=16;
//     int b=4;
//     int n=a%b;
//     do {
//         if(n==0)
//         printf("result=%d",b);
//         a=b;
//         b=n;
//     }while(n=0);
//     return 0;
// }

//재귀함수
//#include <stdio.h>
// int GCD(int a,int b);
// int main(){
//     int result;
//     result = GCD(16,4);
//     printf("result=%d\n",result);
//     return 0;
// }
// int GCD(int a, int b) {
//     int n = a % b;
//     do {
//         if (n == 0)
//             return b;
//         a = b;
//         b = n;
//     } while (n = 0);
//     return b;
//}


//피보나치

//반복함수
//#include<stdio.h>
// int fibo(int a);
// int main(){
//     int x;
//     printf("정수 입력:");
//     scanf("%d",&x);
//     printf("%d번째 피보나치 항 = %d\n",x,fibo(x));
//     return 0;
// }
// int fibo(int a) {
//     int sum, temp = 0;
//         int temp2 = 1;
//         if (a == 0)
//             return 0;
//
//         else if (a == 1)
//             return 1;
//
//         else {
//             for (int i = 1; i <= a; i++) {
//                 sum = temp + temp2;
//                 temp2 = temp;
//                 temp = sum;
//             }
//            return sum;
//         }
// }


//재귀함수
// #include<stdio.h>
// int fibo(int a);
// int main(){
//     int x;
//     printf("정수 입력:");
//     scanf("%d",&x);
//     printf("%d번째 피보나치 항 = %d\n",x,fibo(x));
//     return 0;
// }
// int fibo(int a){
//     if(a<=1)
//       return a;
//     else
//       return fibo(a-1)+fibo(a-2);
// }

#include <stdio.h>
int prime(int n)
{
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            j++;
    }
    if (j == 2)
        printf("%d는 소수입니다.", n);
    else
        printf("%d는 소수가 아닙니다.", n);
}

int main()
{
    int a;
    printf("정수를 입력하시오:");
    scanf("%d", &a);
    prime(a);
    return 0;
}