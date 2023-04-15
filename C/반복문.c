#include <stdio.h>
int main() {
	int x;
	for (int i = 2; i<=9; i++) {
		for(x=1; x<10; x++){
            if(i==2)
				printf("%d * %d = %d",i,x,i*x);
        }
	}
return 0;
}