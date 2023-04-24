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


// #include <stdio.h>
// int main() {
//     int x;
//     printf("배열 크기 입력:");
//     scanf("%d", &x);
//     int b[50][50] = { 0 };
//     int cnt = 0;
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < x; j++) {
//             cnt++;
//             b[i][j] = cnt;
//             }
//         }
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < x; j++) {
//             printf("%d", b[j][i]);
//         }
//         printf("\n");
//     }
// }


#include <stdio.h>
int main(){
    int arr[3][3]={{1,2,3},{3,4},{5}};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
}