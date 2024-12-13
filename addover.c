#include <stdio.h>
void addover(int x, int y){
	int max=0;

	if(x>y) max = x;
	else max = y;

	int result = x+y;
	if(x>0 && y>0 && result<max){
		printf("overflow!\n");
	}
	else if(x<0 && y<0 && result>max){
		printf("overflow!\n");
	}
	else printf("sum = %d\n", result);
}
