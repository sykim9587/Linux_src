#include <stdio.h>

int main(void){

	double weight, height, BMI;
	
	scanf("%lf %lf", &weight, &height);
	BMI = weight/(height*height);
	
	printf("%s \n",(BMI>20.0 && BMI<25.0) ? "average":"need to loose weight"); 

	return 0;
}
