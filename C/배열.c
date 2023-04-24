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


// #include <stdio.h>
// int main(){
//     int car[11]={0};
//     char x;
//     for(;;){
//     printf(">>자동차 모델을 선택하시겠습니까? (Y/N):");
//     scanf(" %c",&x);
//     int b;

//     if(x!='Y' && x!='y' && x!='N' && x!='n'){
//         printf("알파벳 입력 오류입니다.\n 알파벳은 대소문자 구별 없이 Y 또는 N만 허용합니다.\n 알파벳을 다시 입력하세요.\n");
//     }

//     if(x=='Y' || x=='y'){
//         printf("자동차 모델 번호: 1 2 3 4 5 6 7 8 9 10\n");
//         printf("자동차 모델 현황: %d %d %d %d %d %d %d %d %d %d\n",car[1],car[2],car[3],car[4],car[5],car[6],car[7],car[8],car[9],car[10]);
//         printf("자동차 모델 선택:");
//         scanf("%d",&b);
//         if(car[b]==0){
//             car[b]+=1;
//             printf("예약 완료되었습니다.\n");
//         }
//         else{
//             printf("%d모델은 이미 선택된 모델입니다. 다시 입력하세요.",b);
//         }
//     }
    
//     else if(x=='n'||x=='N'){
//         for(int i = 1; i <= 10; i++){
//             if(car[i] != 0){
//                 printf("자동차 모델 No.%d 예약 완료\n", i);
//             }
//         }
//         break;
//     }

    
//     }
//     return 0;
// }



#include <stdio.h>
#define STUDENT 5
void SCANF (int sum[]);
float SUM(int sum[]);
int CHECK(int num[],int num1);


int main(){
    int score[STUDENT];
    SCANF(score);

    float result = (float)SUM(score)/STUDENT;
    printf("평균 = %.2f\n\n",result);

    int x=100;
    int key = CHECK(score, x);
    if(key == 1){
        printf("배열 안에 %d가 존재",x);
    }
    else{
        printf("배열 안에 %d가 없음",x);
    }
    return 0;
}
void SCANF (int sum[]){
    int a,b,c,d,e;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    sum[0] = a;
    sum[1] = b;
    sum[2] = c;
    sum[3] = d;
    sum[4] = e;
}

float SUM(int sum[]){
    float count = sum[0] + sum[1] + sum[2] + sum[3] + sum[4];
    return count;
}

int CHECK(int num[],int num1){
    for(int i=0; i<5; i++){
        if(num[i] == num1){
            return 1;
        }
    }
    return 0;
}