//#include <stdio.h>
//int main() {
//    int a[3][5] = { {1, 2, 3, 4, 5},
//        {6, 7, 8, 9, 10},
//        {11, 12, 13, 14, 15} };
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 5; j++) {
//            printf("%d ",a[i][j]);
//        }
//        printf("\n");
//    }
//}


//#include<stdio.h>
//int main() {
//    int arr1[2][3] = { 1, 2, 3, 4, 5, 6 };
//    int arr2[2][3] = { {1, 2, 3}, {4, 5, 6} };
//
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < 3; j++) {
//            printf("%3d", arr1[i][j]);
//        }
//        printf("\n");
//    }
//}


//#include <stdio.h>
//int main() {
//    int arr3[][3] = { {1,2,3},{4,5,6} };
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < 3; j++) {
//            printf("%3d", arr3[i][j]);
//        }
//        printf("\n");
//    }
//}


//#include <stdio.h>
//int main() {
//    int x;
//    printf("배열 크기 입력:");
//    scanf("%d", &x);
//    int b[50][50] = { 0 };
//    int cnt = 0;
//    for (int i = 0; i < x; i++) {
//        for (int j = 0; j < x; j++) {
//            cnt++;
//            b[i][j] = cnt;
//            printf("%d", cnt);
//        }
//        printf("\n");
//    }
//    return 0;
//}


// #include<stdio.h>
// int main() {
//     int x;
//     printf("배열 크기 입력 : ");
//     scanf("%d", &x);
//     int b[50][50] = { 0 };
//     int cnt = 0;
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < x; j++) {
//             cnt++;
//             b[i][j] = cnt;
//         }
//     }

//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < x; j++) {
//             printf("%3d", b[j][i]);
//         }
//         printf("\n");
//     }
// }


// #include <stdio.h>
// int main(){
//     int arr[3][3]={{1,2,3},{3,4},{5}};
//     for(int i=0; i<3; i++){
//         for(int j=0; j<3; j++){
//             printf("%3d",arr[i][j]);
//         }
//         printf("\n");
//     }
// }


// #include <stdio.h>
// #define SIZE 5
// int main(){
//     int b[SIZE][SIZE]={0};
//     int cnt=1;
//     for(int i=0; i<SIZE; i++){
//         if(i%2==1){
//          for(int j=0; j<SIZE; j++){
//             b[i][j]=cnt++;
//             }
//         }
//         else{
//          for(int j=SIZE-1; j>=0; j--){
//             b[i][j]=cnt++;
//         }
//         }
//     }

//     for(int i=0; i<SIZE; i++){
//         for(int j=0; j<SIZE; j++){
//             printf("%3d ",b[i][j]);
//         }
//         printf("\n");
//     }
// }


// #include <stdio.h>
// #define SIZE 5
// int main(){
//     int b[SIZE][SIZE]={0};
//     int cnt=1;
//     for(int j=0; j<SIZE; j++){
//         if(j%2==1){
//          for(int i=SIZE-1; i>=0; i--){
//             b[i][j]=cnt;
//             cnt++;
//             }
//         }
//         else{
//          for(int i=0; i<SIZE; i++){
//             b[i][j]=cnt;
//             cnt++;
//         }
//         }
//     }

//     for(int i=0; i<SIZE; i++){
//         for(int j=0; j<SIZE; j++){
//             printf("%3d ",b[i][j]);
//         }
//         printf("\n");
//     }
// }


// #include <stdio.h>
// int main(){
// int A[3][3]={{1,2,3},
//             {4,5,6},
//             {7,8,9}};
// int B[3][3]={{9,8,7},
//             {6,5,4},
//             {3,2,1}};
// int C[3][3]={{0},
//             {0},
//             {0}};
//             int cnt=0;
// for(int i=0; i<3; i++){
//     for(int j=0; j<3; j++){
//         A[i][j]+B[i][j]=C[i][j];
//     }
// }
// for(int i=0; i<3; i++){
//         for(int j=0; j<3; j++){
//             printf("%3d ",C[i][j]);
//         }
//         printf("\n");
// }
// }


// #include <stdio.h>
// int main(){
//     int grade[3][5]={0};
//     int sub_sum=0, sum=0;

//     for(int i=0; i<3; i++){
//         printf("학급 %d 성적 입력(5명):",i+1);
//         for(int j=0; j<5; j++){
//             scanf("%d",&grade[i][j]);
//             sub_sum+=grade[i][j];
//         }
//         printf("학급 %d 성적 평균 : %.2f\n\n",i+1,sub_sum/5.0);
//         sum+=sub_sum;
//         sub_sum=0;
//     }
//     printf("\n전체 성적 평균:%.2f\n",sum/15.0);
// }

#include<stdio.h>
int data[] = { 8, 5, 2, 7, 9, 3 };
void dataPrint(int len);
int main() {
    int temp;
    int len = sizeof(data) / sizeof(data[0]);
    dataPrint(len);
    for (int i = 0; i < len; i++) {
        for (int k = 1; k < len; k++) {
            if (data[k - 1] > data[k]) {
                temp = data[k - 1];
                data[k - 1] = data[k];
                data[k] = temp;
            }
        }
        dataPrint(len);
    }
    return 0;
}
void dataPrint(int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}