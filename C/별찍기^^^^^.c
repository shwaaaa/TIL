//직각삼각형 찍기

//*
//**
//***
//****
//*****
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
		return 0;
	}


//역직각삼각형 찍기
//*****
//****
//***
//**
//*

#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = n; j > i ; j--) {
			printf("*");
		}
		printf("\n");
	}
		return 0;
	}


//*****
// ****
//  ***
//   **
//    *

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


//삼각형 찍기
//   *
//  ***
// *****

#include <stdio.h>
int main(){
int input;
scanf("%d", &input);
for (int i = 0; i < input; i++) {
    for (int j = 1; j < input - i; j++) {
        printf(" ");
    }

    for (int j = 0; j < 2 * i + 1; j++) {
        printf("*");
    }
    printf("\n");
}
return 0;
}


//역삼각형 찍기
// *****
//  ***
//   *

#include <stdio.h>
int main(){
    int input;
    scanf("%d",&input);
for (int i = 1; i < input; i++) {
    for (int j = 0; j < i; j++) {
        printf(" ");
    }

    for (int j = 0; j < 2 * input - (2 * i + 1); j++) {
        printf("*");
    }
    printf("\n");
}
return 0;
}


//다이아몬드 찍기
//  *
// ***
//*****
// ***
//  *

 #include <stdio.h>
int main(){
int input;
scanf("%d", &input);
for (int i = 0; i < input; i++) {
    for (int j = 1; j < input - i; j++) {
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

    for (int j = 0; j < 2 * input - (2 * i + 1); j++) {
        printf("*");
    }
    printf("\n");
}
return 0;
}