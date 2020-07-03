#include <stdio.h>

int main(void)
{
	int kor, eng, mat;
	
	scanf("%d %d %d", &kor, &eng, &mat);
	
	int sum;
	sum = kor + eng + mat;
	
	double average;
	average = sum/3.0;
	
	printf("sum: %d\taverage: %.2f\n", sum, average);
	
	return 0;
}
