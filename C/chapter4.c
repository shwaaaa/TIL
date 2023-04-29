// #include<stdio.h>
// int main(){
//     int x;
//     printf("정수 입력 :");
//     scanf("%d",&x);
//     if(x==10){
//         printf("정답!!\n");
//         printf("종료");
//     }
//     else
//     printf("종료");
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int x;
//     printf("정수 입력 :");
//     scanf("%d",&x);
//     if(x>0)
//     printf("절대값은 %d입니다",x);
//     else if(x<0)
//     printf("절대값은 %d입니다",-x);
//     return 0;
// }

// #include <stdio.h>
// int main(){
//     int x,y,z;
//     printf("3개의 정수 입력 : ");
//     scanf("%d %d %d",&x, &y, &z);
//     int sum=x+y+z;
//     if((sum%10)>5||x%5==0){
//     printf("sum=%d\n",sum);
//     printf("종료");
//     }
//     else if((sum%10)<5)
//     printf(" ");
//     return 0;
// }

// #include <stdio.h>
// int main(){
//     char x;
//     printf("문자를 입력하시오 : ");
//     scanf("%c",&x);
//     if(x<91&&x>64){
//         printf("%c는 대문자",x);
//     }
//     else if(x<123&&x>96)
//         printf("%c는 소문자",x);
//     else if(x<58&&x>47)
//         printf("%c는 숫자",x);
//     else
//         printf("%c는 기타문자입니다",x);
    
// }

// #include <stdio.h>
// #include<time.h>
// #include <stdlib.h>
// int main(){
//     int x,y;
//     srand(time(NULL));
//     y=(rand()%10+1);
//     printf(">>>숫자 맞추기 게임<<<\n\n\n");
//     printf("1부터 10까지 숫자를 입력하세요 :");
//     scanf("%d",&x);
//     if(y==x){
//         printf("정답입니다");
//     }
//     else if(y!=x){
//         printf("틀렸습니다. 정답은 %d입니다.",y);
//     }
//     return 0;
// }

