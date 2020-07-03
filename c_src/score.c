#include <stdio.h>

int main(void){
	int scores[10];
	int sum = 0;
	for(int i = 0; i<10; ++i){
		scanf("%d",&scores[i]);
		sum += scores[i];
	}
	double average = (double)sum / 10;
	
	printf("sum = %d\taverage = %.2f\n", sum, average);

	
	return 0;
}
