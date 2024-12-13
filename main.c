#include "overflow.h"
int main(){
	int x, y;
	printf("Put two integers to add.\n");
	scanf("%d %d", &x, &y);

	addover(x,y);

	printf("Put two integers to sub.\n");
	scanf("%d %d", &x, &y);
	
	subover(x,y);

	return 0;
}
