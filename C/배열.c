// #include <stdio.h>
// int main(){
//     int x[5]={1, 2, 3, 4, 5};
//     for(int i=0; i<5; i++){
//         printf("%d\n",x[i]);
//     }
//     return 0;
// }

// #include <stdio.h>
// #define SIZE 11
// int main() {
//     int x;
//     int a[SIZE]={0};
//     for (;;) {
//         printf("0~10까지 숫자 입략(종료는 -1) :");
//         scanf("%d", &x);
//         switch (x) {
//         case 0:
//             a[0] += 1;
//             break;
//         case 1:
//             a[1] += 1;
//             break;
//         case 2:
//             a[2] += 1;
//             break;
//         case 3:
//             a[3] += 1;
//             break;
//         case 4:
//             a[4] += 1;
//             break;
//         case 5:
//             a[5] += 1;
//             break;
//         case 6:
//             a[6] += 1;
//             break;
//         case 7:
//             a[7] += 1;
//             break;
//         case 8:
//             a[8] += 1;
//             break;
//         case 9:
//             a[9] += 1;
//             break;
//         case 10:
//             a[10] += 1;
//             break;
//         }
//         if (x == -1)
//             break;
//     }
//     printf("값        빈도\n");
//     for (int i = 0; i < SIZE; i++) {
//         printf("%d     %d\n", i, a[i]);
//     }
// }


#include <stdio.h>
int main(){
    int car[10]={0};
    int x;
    printf(">>자동차 모델을 선택하시겠습니까? (Y/N)");
    scanf("%d",&x);
    while(x=='N'||x=='n'){
    printf(">>자동차 모델을 선택하시겠습니까? (Y/N)");
    scanf("%d",&x);
    if(x=='Y' || x=='y'){
        int b;
        printf("자동차 모델 번호: 1 2 3 4 5 6 7 8 9 10\n");
        printf("자동차 모델 현황: %d %d %d %d %d %d %d %d %d %d\n",car[0],car[1],car[2],car[3],car[4],car[5],car[6],car[7],car[8],car[9]);
        printf("자동차 모델 선택:");
        scanf("%d",&b);
        if(car[b]==0){
            car[b]+=1;
        }
        else
        printf("%d모델은 이미 선택된 모델입니다. 다시 입력하세요.",b);
        continue;
    }
    
    else
    printf("알파벳 입력 오류입니다.\n 알파벳은 대소문자 구별 없이 Y 또는 N만 허용합니다.\n 알파벳을 다시 입력하세요.");
    continue;
    }
    printf("자동차 모델 No.예약 완료 후 프로그램 종료");
}


// #include <stdio.h>
// #define STUDENT 5
// int SCANF (int sum);
// float SUM(int a,int b,int c, int d, int e);
// int CHECK(int num1,int num2);
// int main(){
//     int result;
//     int score[STUDENT];
//     SCANF(score);

//     float result = (float)SUM(score)/STUDENT;
//     printf("평균 = %.2f\n\n",result);

//     int x=100;
//     int key = CHECK(x,score);
//     if(key ==1){
//         printf("배열 안에 %d가 존재",x);
//     }
//     else{
//         priintf("배열 안에 %d가 없음",x);
//     }
//     return 0;
// }
// int SCANF (int sum){
//     int a,b,c,d,e;
//     scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
//     int sh[5]={a,b,c,d,e};
//     return;
// }

// float SUM(int a,int b,int c, int d, int e){
//     int sum=0;
//     sum=a+b+c+d+e;
//     return sum;
// }

// int CHECK(int num1,int num2){
//     for(int i=0; i<5; i++){
//         int sum=0;
//         sum=num2/num1;
//         return sum;
//     }
// }