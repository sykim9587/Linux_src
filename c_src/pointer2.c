#include <stdio.h>

int main(void)
{
	int a;
	int nums[10];
	int *p;
	p = &a;
	*p = 100;
	// just *p = 100 ; segmentation error occurs (core dumped)
	printf("%d\n", a);
	return 0;
}
