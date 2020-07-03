#include <stdio.h>

int main(void){
	int i = 100;
	void *p;
	
	p = &i;
	*(int*)p = 200; //dereferencing not possible
	printf("i = %d\n", i);
	
	double d = 3.14;
	p = &d;
	
	*(double*)p = 2.718;
	printf("d: %f\n", d);
	return 0;
}
