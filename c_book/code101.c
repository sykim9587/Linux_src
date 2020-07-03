#include <stdio.h>

int main(void){
	
	int a = 20, b = 3;
	double res;
	
	res = ((double)a)/((double)b);
	printf("a = %d, b = %d\n", a, b);
	printf("a/b result : %.1lf\n", res);
	
	a = (int)res;
	printf("(int) %.1lf result: %d\n", res, a);
	
	


	return 0;
}
