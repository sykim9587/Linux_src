#include <stdio.h>
#include <stdlib.h>

//need to improve getting 300 as the total score -> 10 when it's strike or spare

int main(void)
{
	int score[10] = {0};
	int try[10][2] = {0};
	int totalp[10] = {0};
	int flag = 0, pflag = 0,strike = 0;
	for(int i=0; i<10; i++){
		int sum =0,tmp = 0, try1 = 0, try2 = 0, pas1 =0, pas2 = 0, try3=0;
		
		for(int j=0; j<2; j++){
			do{printf("no.%d, try %d : ", i+1,j+1);	//entering score
			scanf("%d",&tmp);
			while ((getchar())!='\n');
			if(i==9 && j==1 && tmp >=0 && tmp <=10) break;
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
				if(i != 9){
				break;
				}
			}
			
			if(j==1 && i !=9){					//two tries finished
				score[i]=sum;
				flag =0;
			}
			if(i==9 && j==1){					//only for 10th try
				if(sum==10){	//spare 		
					do{printf("no.%d, try %d : ", i+1,j+2);
					scanf("%d",&tmp);
					}while(tmp<0 || tmp >10);
					try3=tmp;
					sum +=tmp;
					score[i]=sum;
				}
				else if(sum == 20){ //two strike
					do{printf("no.%d, try %d : ", i+1,j+2);
					scanf("%d",&tmp);
					}while(tmp<0 || tmp >10);
					try3=tmp;
					sum +=tmp;
					score[i]=sum;
				}
				else{ //fail after two tries
					score[i]=sum;
					try3=0;
					break;
				}
			
			}
		}
	
		if(pflag == 1){
		score[i-1] += try1;}
		if(pflag == 2){
		score[i-1] += (try1 + try2);}
		if((try[i-2][0]+try[i-2][1])==10 && pflag == 2 && strike != 0){
		score[i-2] += strike; strike = 0;
		}

		try[i][0]= try1;
		try[i][1]= try2;
		//printing table
		system("clear");
		int total =0;
		printf("============================================================================\n");
		printf("1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
		printf("============================================================================\n");
		for(int q = 0; q <10 ; q++){
			//strike
			if(try[q][0]==10){
				if(q==9){
				if(try[q][1] == 10 && try3 == 10){ //three strike
					printf("%c %c %c\t",'X','X','X');
				}
				else if (try[q][1] == 10 && try3 != 10){ //2 strike
					printf("%c %c %d\t",'X','X',try3);
				}
				else {	//1 strike
					printf("%c %d %d\t",'X',try[q][1],try3);
				}
				
				}
				else printf("%c %c\t",'X',' ');
			}
			
			//spare
			else if(try[q][0]+try[q][1] == 10){
				if(q==9){
				printf("%d %c %d\t", try[q][0] ,'/',try3);
				}
				else printf("%d %c\t",try[q][0], '/');
			}
			//normal
			else {
				if(q==9){
				printf("%d %d %c\t",try[q][0] , try[q][1],' ');
				}
				else printf("%d %d\t",try[q][0], try[q][1]);
			}
		}
		printf("\n");
		total = 0;
		for(int q = 0; q <10 ; q++){
		printf("%d\t",score[q]);
		total += score[q];
		}
		printf("\n");
		//totalp[i] = total;
		//for(int q = 0; q <10 ; q++){
		//printf("%d\t",totalp[q]);
		//}
		printf("total : %d\n", total);
		printf("============================================================================\n");
	}
	

	return 0;
}
