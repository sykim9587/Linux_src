#include <stdio.h>

int main(void)
{
	int score[10] = {0};
	int try[2];
	int flag = 0, pflag = 0,strike = 0;
	for(int i=0; i<10; i++){
		int sum =0,tmp = 0, try1 = 0, try2 = 0, pas1 =0, pas2 = 0;
		
		for(int j=0; j<2; j++){
			do{printf("no.%d, try %d : ", i+1,j+1);	//entering score
			scanf("%d",&tmp);
			while ((getchar())!='\n');
			}while((tmp!=9&&tmp!=8&&tmp!=7&&tmp!=6&&tmp!=5&&tmp!=4&&
			tmp!=3&&tmp!=2&&tmp!=1&&tmp!=10) || sum+tmp>10);
			
			sum +=tmp;
			if(j==0){
				try1 = tmp;
				if(pflag == 2) strike = try1;
			}
			else if(j==1){		
				try2 = tmp;
			}
			
			pflag = flag;
			if(sum==10 || tmp==10){				//strike or spare
				score[i]=sum;
				
				if(tmp == 10) flag = 2;
				else flag = 1;
				
				break;
			}
			
			if(j==1 && i !=9){					//two tries finished
				score[i]=sum;
				flag =0;
			}
			if(i==9 && j==1){					//only for 10th try
				if(sum<10){
					do{printf("no.%d, try %d : ", i+1,j+2);
					scanf("%d",&tmp);
					}while(tmp<0 || tmp >10 || sum+tmp>10);
					sum +=tmp;
					score[i]=sum;
				}
			}
		}
		//printf("flag = %d\n", flag);
		//printf("pflag = %d\n", pflag);
		//printf("strike = %d\n", strike);
		if(pflag == 1){
		score[i-1] += try1;}
		if(pflag == 2){
		score[i-1] += (try1 + try2);}
		if(pflag == 2 && strike != 0){
		score[i-2] += strike;
		}
		
		int total =0;
		for(int q = 0; q <10 ; q++){
		printf("frame %d: %d\n",q, score[q]);
		total += score[q];
		}
		printf("total : %d\n", total);
	}
	

	return 0;
}
