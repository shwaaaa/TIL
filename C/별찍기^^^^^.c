//역삼각형 찍기

#include <stdio.h>
int main(){
int x, y;
for (x = 5; x > 0; x--) {
	for (y = 1; y < x+1; y++)
		printf("*");
	printf("\n");
}
return 0;
}

#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);
    for (int i = 1; i <=x; i++) {
        for (int j = x; j >= i; j--) {
            printf("*");
        }
        printf("\n");
    }
	return 0;
}

#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);
    for (int i = 1; i <=x; i++) {
        for (int j = 1; j <= i-1; j++) {
            printf(" ");
        }
        for (int j = x; j >= i; j--) {
            printf("*");
        }
        printf("\n");
    }
	return 0;
}

//다이아몬드 찍기
  int input;
    scanf("%d", &input);
    for (int i = 0; i < input; i++) {
        for (int j = 1; j <input- i; j++) {
            printf(" ");
        }

        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i < input; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }

        for (int j = 0; j < 2*input-(2*i+1); j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
