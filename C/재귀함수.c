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



#include<stdio.h>
int power(int a,int b);
int main() {
    int result;
    result = power(2, 5);
    printf("result = %d\n",result);
    return 0;
}

int power(int a, int b) {
    if (b <= 1)
        return a;
    else
        return a*power(a,b-1);
}


