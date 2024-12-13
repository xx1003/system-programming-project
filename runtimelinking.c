#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int main(){
	void *handle;
	void (*addover)(int, int);
	void (*subover)(int, int);
	char *error;
	handle = dlopen("./libmine.so", RTLD_LAZY);
	if(!handle){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	
	int x,y;
	printf("Put two integers to add.\n");
	scanf("%d %d", &x, &y);
	addover = dlsym(handle, "addover");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	addover(x,y);

	int a,b;
	printf("Put two integers to sub.\n");
	scanf("%d %d", &a, &b);
	subover = dlsym(handle, "subover");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	subover(a,b);

	if(dlclose(handle) < 0){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	return 0;
}
