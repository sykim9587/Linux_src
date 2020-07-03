#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int lotto[7] = {0};
	srand(time(NULL));
	//1-45, 7 numbers
	int flag=1;
	//printf("%d\n",rand()%45 +1);
	for(int i=0; i<7; i++){	
		while(flag>0){
			flag=0;
			lotto[i] = rand()%45+1;
			for(int j=0; j<i; j++){
				if(lotto[j]==lotto[i])
					flag++;
			}
		}
		flag=1;	
	}
	for (int k=0; k<7; k++){
		printf("%d ",lotto[k]);
	}
	printf("\n");
	return 0;
}
