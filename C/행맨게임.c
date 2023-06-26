#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    //1. 영어 단어들을 저장하는 포인터 배열 선언
    char* dic[] = {"dog", "lion", "fox", "horse", "tiger", "raccoon", "bear", "dolphin", "elephant"};

    //2. 랜덤한 단어 하나 선택해서 word 포인터 변수에 저장
    srand(time(NULL));
    int num = rand() % 8;
    char* word = dic[num];
    //printf("%s\n", word);

    //3. word 포인터 변수가 가리키는 단어의 길이를 len 변수에 저장
    int len = strlen(word);

    //4. 포인터 변수 pword를 선언하여 동적 메모리 할당(len+1 크기 할당) + 데이터를 모두 '_'로 채우기
    char* pword; //포인터를 선언하여 동적 메모리 주소로 사용
    pword = (char*)malloc(sizeof(char) * (len+1));
    for(int i = 0; i < pword; i++){
        printf("_");
    }
    //단어 마지막 끝에 null문자 넣기
    char null[] = "\0";
    strcat(dic,null);

    int cnt = 0; //카운트 변환
    int user = 0; 
    char ch; //사용자 문자 하나 입력받는 변수
    printf("\n<< 행맨 게임 만들기 >>\n\n");

    while(1){
        cnt++;
        printf("\n현재 문자 출력 : %s\n", pword);
        printf("문자 한개 입력 :");
        scanf("%c", &ch);
        rewind(stdin); //입력 버퍼 초기화 fflush(stdin)

        for(int i = 0; i<5; i++){
            if(pword[i]==ch){
                word[i]=ch;
            }
    }
}
}