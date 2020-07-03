#include <stdio.h>

int main(void)
{
	int age;
	double height;
	
	printf("insert: ");
	scanf("%d%lf", &age, &height);
	printf("age: %d, height: %.1lfcm\n", age, height);


	return 0;
}
