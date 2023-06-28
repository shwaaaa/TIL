#include <stdio.h>
#include <string.h>

// void get_sum_diff(int x, int y, int* p_sum, int* p_diff);
// int main(void)
// {
//     int sum = 0, diff = 0;
//     get_sum_diff(100, 200, &sum, &diff);
//     printf("합 = %d\n", sum);
//     printf("차 = %d\n", diff);
//     return 0;
// }

// void get_sum_diff(int x, int y, int* p_sum, int* p_diff)
// {
//     *p_sum = x+y;
//     *p_diff = x-y;
// }


// void get_int(int* px, int* py);
// int main(void)
// {
//     int x,y;
//     get_int(&x, &y);
//     printf("정수의 합을 %d\n", x + y);
//     return 0;
// }
// void get_int(int* px, int* py){
//     scanf("%d %d", px, py);
// }


// 주소 = 10, 값 = 100, value = 0
// 주소 = 10, 값 = 101, value = 101
// 주소 = 14, 값 = 200, value = 200
// 주소 = 18, 값 = 300, value = 300
// 주소 = 18, 값 = 301, value = 301
// 주소 = 22, 값 = 100, value = 0


// // 2, 3, 5, 2
// int main() {
//     int a[] = {1, 2, 3, 4, 5, 6};
//     int* p = a;
//     int* q = a+3;

//     printf("%d\n",*(a+1));
//     printf("%d\n",*(p+2));
//     printf("%d\n",*(q+1));
//     printf("%d\n",p[1]);
// }


// //21-1
// int main() {
//     int a[5] = {1, 2, 3, 4, 5};
//     int result = 0, i = 0;
//     for (i = 0; i < 5; i++){
//         result = result + *(a+i);
//     }
//     printf("배열의 합 = %d", result);
// }


// //22-2
// int StringPointer(char* s);
// int main(){
//     int len;
//     char string[100] = "";

//     printf("문자열 입력: ");
//     gets(string);

//     printf("문자열 길이: %d\n", StringPointer(string));
// }

// int StringPointer(char* s){
//     int len = 0;
//     while(*s != '\0'){
//         len++;
//         s++;
//     }
//     return len;
// }


// //21-3
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


// //p12
// int main(){
//     char a[4][10] = {"you", "house", "home", "school"};
//     char temp[10];

//     strcpy(temp, a[0]);
//     int max = strlen(a[0]);

//     for(int i =1; i<4; i++){
//         if(max<strlen(a[i])){
//             max = strlen(a[i]);
//             strcpy(temp, a[i]);
//         }
//     }
//     printf("%s", temp);
// }


int main(){
    char* p[4]= {"you", "house", "home", "school"};
    char *temp = p[0];

    int max = strlen(p[0]);

    for(int i =1; i<4; i++){
        if(max<strlen(p[i])){
            max = strlen(p[i]);
            temp = p[i];
        }
    }
    printf("%s", temp);
}