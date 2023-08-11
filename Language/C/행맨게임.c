

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* dic[] = { "dog","lion","fox","horse","tiger","raccoon","bear","dolphin","elephant" };

    srand(time(NULL));
    int num = rand() % (sizeof(dic) / sizeof(dic[0]));
    char* word = dic[num];

    int len = strlen(word);

    char* pword;
    pword = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++) {
        pword[i] = '_';
    }

    pword[len] = '\0';

    int cnt = 0;
    char ch;
    printf("\n<<행맨 게임 만들기>>\n\n");

    while (1) {
        if (!strcmp(word, pword)) {
            printf("\n%d번만에 성공!", cnt);
            free(pword);
            return 0;
        }
        cnt++;
        printf("\n현재 문자 출력 : %s\n", pword);
        printf("문자 한 개 입력 : ");
        scanf(" %c", &ch);
        getchar(); // 개행 문자 제거

        for (int i = 0; i < len; i++) {
            if (word[i] == ch) {
                pword[i] = ch;
            }
        }
    }
}
