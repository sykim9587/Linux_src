#include <stdio.h>

int main(void){

	int seats =70, audience =65;
	double rate;
	
	rate = (double)audience/(double)seats*100;
	printf("rate : %.1lf%%\n", rate);

	return 0;
}
