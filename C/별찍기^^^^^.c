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

//다이아몬드 찍기
