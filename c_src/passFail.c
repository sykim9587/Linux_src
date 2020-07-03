#include <stdio.h>

int main(void)
{
	int score;
	printf("input score: ");
	scanf("%d", &score);
	
	printf("Score: %d ---", score);
	if (score >= 60){
		printf("Pass\n");
	} 
	else {
		printf("Fail\n");	
	
	}

	return 0;
}
