// #include<stdio.h>
// int main(){
//     char arr1[6] = {'a', 'p', 'p', 'l', 'e', '\0'};
//     char arr2[6] = "apple";
//     char arr3[] = "apple";
//     char arr4[5] = "apple";

//     printf("%s의 크기 : %d\n", arr1, sizeof(arr1));
//     printf("%s의 크기 : %d\n", arr2, sizeof(arr2));
//     printf("%s의 크기 : %d\n", arr3, sizeof(arr3));
//     printf("%s의 크기 : %d\n", arr4, sizeof(arr4));
// }


// #include<stdio.h>
// int main(){
//     char arr1[] = "Hello world";
//     printf("%s의 크기 : %d\n", arr1, sizeof(arr1));

//     char arr2[] = "Hello\0 world";
//     printf("%s의 크기 : %d\n", arr2, sizeof(arr2));
// }


// #include<stdio.h>
// int main(){
//     char str[] = "KOMPUTER";

//     printf("수정 전 %s\n", str);
//     str[0]='C';
//     printf("수정 후 %s\n", str);
// }


// #include<stdio.h>
// int main(){
//     char str[20];
//     int i, length = 0;

//     printf("띄어쓰기 없이 문자열을 20바이트 이내로 입력하시오 :");
//     scanf_s("%s", str, sizeof(str));
//     for(int i=0; str[i]!='\0'; i++){
//         length++;
//     }
//     printf("\n입력한 문자열 %s의 길이 : %d\n", str, length);
//     return 0;
// }


// #include<stdio.h>
// #include<string.h>
// int main(){
//     char str1[10] = "elephant";
//     char str2[10] = "ele\0phant"

//     printf("%s의 길이는 %d입니다.\n", str1, strlen(str1));
//     printf("%s의 길이는 %d입니다.\n", str2, strlen(str2));
// }


#include<stdio.h>
#include<string.h>
int main(){
    char str1[10] = "cat";
    char str2[10];

    //이러면 안됨
    //str2 = "cat";

    //str2 배열에 str1 배열의 문자열 복사
    strcpy(str2, str1);
    printf("%s", str2);
}