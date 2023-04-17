// #include<stdio.h>
// int EVEN(int a);
// int ODD(int b);
// int main(){
//     int result,result2;
//     result2=ODD(100);
//     result=EVEN(100);
//     printf("홀수의 합:%d, 짝수의 합:%d",result2,result);
// }
// int ODD(int b){
//     int sum2=0;
//     for(int i=1; i<=b; i++){
//     if(i%2!=0)
//     sum2+=i;
//     else
//     continue;}
//     return sum2;
// }
// int EVEN(int a){
//     int sum=0;
//     for(int i=1; i<=a; i++){
//     if(i%2==0)
//     sum+=i;
//     else
//     continue;}

//     return sum;
// }


#include <stdio.h>
int Power(int a);
int main(){
    int x;
    int result;
    scanf("%d",&x);
    result = Power(x);
    printf("%d",result);
    return 0;
}
int Power(int a){
    int sum=1;
    for(int i=1; i<=a; i++){
        sum=sum*2;
    }
    return sum;
}