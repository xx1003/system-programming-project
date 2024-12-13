#include <stdio.h>

void subover(int x, int y){
	int result = x-y;

	if(x>0 && y<0 && result<x){
		printf("overflow!\n");
	}
	else if(x<0 && y>0 && result>x){
		printf("overflow!\n");
	}
	else printf("diff = %d\n", result);
}
