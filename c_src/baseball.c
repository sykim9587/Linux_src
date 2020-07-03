#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int answer[3];	
	int question[3];
	
	srand(time(NULL));

	question[0] = rand()%9 +1;

	question[1] = rand()%9 +1;	//%10 doesn't work since it will create 0
	while(question[0]==question[1]){
		question[1] = rand()%9 +1;		
	}
	
	question[2] = rand()%9 +1; 
	while(question[2]==question[1]||question[2]==question[0]){
		question[2] = rand()%9 +1;		
	}		

	int i =0;
	while ( i<3){
		printf("%d ", question[i]);
		++i;	
	}
	printf("\n");
	
	int count = 0;
	int strike, ball;
	strike = ball = 0; //from right hand side 
	
	while (strike != 3){ //real game starts here
		strike = ball = 0;
		
		//input three numbers	
		printf("input three nums: ");
		scanf("%d %d %d", &answer[0], &answer[1], &answer[2]);

		
		//count #strike #ball			
		for (int i=0; i<3; ++i){
			for (int j=0; j<3; ++j){
				if(question[i] == answer[j]){
					if(i==j)
						++strike;						
					 else
						++ball;					
				}
			}	
		}
			
		printf("strike: %d\tball: %d\n", strike, ball);
		++count;
	
	}
	
	printf("Congraturation! Your count : %d\n", count);
	
	
	
	return 0;
}
