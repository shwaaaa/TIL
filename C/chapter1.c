// #include <stdio.h>
// int main(){
//     printf("학교 : 광주소프트웨어마이스터고\n");
//     printf("학번_이름 : 1114_이승화\n");
//     printf("성별 : 여\n");
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     printf("  *\n");
//     printf(" ***\n");
//     printf("*****\n");
//     return 0;
// }

// #include <stdio.h>
// int main(){
//     printf("내 키는 %d입니다.\n",188);
//     printf("당신은 %d년생으로 %d살입니다.",2007,17);
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     printf("%d\n",12345);//12345
//     printf("%10d\n",12345);//.    12345
//     printf("%010d\n",12345);//0000012345

//     printf("%f\n",123.823);//123.823000
//     printf("%.2f\n",123.823);//123.82
//     printf("%10.2f\n",123.823);//.   123.82
//     printf("%-10.2f\n");//123.82
//     printf("%010.2f\n",123.823);//0000123.82
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int a=10,b=20;
//     int c=a+b;
//     printf("%d + %d =%d",a,b,c);
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int x=7,y=3,z;
//     printf("교환 전 x=%d, y=%d",x,y);
//     z=y;
//     y=x;
//     x=z;
//     printf("교환 후 x=%d, y=%d",x,y);
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     printf("char형의 크기 : %d\n",sizeof(char));
//     printf("int형의 크기 : %d\n",sizeof(int));
//     printf("float형의 크기 : %d\n",sizeof(float));
//     printf("double형의 크기 : %d\n",sizeof(double));
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int x=100;
//     float y;
//     y=(float)5/9*(x-32);
//     printf("%.2f",y);
//     return 0;
// }

// #include<stdio.h>
// #define INCH 2.54
// int main(){
//     float x=1.467;
//     printf("%.2finch==%.2fcm",x,INCH*x);
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     const float INCH=2.54;
//     float x= 1.467;
//     printf("%.2finch==%.2fcm",x,INCH*x);
//     return 0;
// }

// #include <stdio.h>
// #define SEC_PER_MINUTE 60
// int main(){
//     int minute=1000;
//     printf("%d초는 %d분 %d초입니다",minute,minute/SEC_PER_MINUTE,minute%SEC_PER_MINUTE);
//     return 0;
// }

#include<stdio.h>
#define user 10000
#define price 3200
int main(){
    int change=user-price;
    printf("----거스름돈 돌려주기 프로그램----\n");
    printf("물건 값 : %d\n",price);
    printf("사용자가 낸 돈 : %d\n\n",user);

    printf("오천원권 : %d장\n",change/5000);
    printf("천원권 : %d장\n",(change%5000)/1000);
    printf("오백원 동전 : %d개\n",(change%6000)/500);
    printf("백원 동전 : %d개\n",(change%6500)/100);
    return 0;
}

