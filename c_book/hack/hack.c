#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    char* tmp = calloc(11, sizeof(char));
    n=3;
    
    for(int i=n-1; i>0; i--){
		for(int j=i-1; j>=0; j--){
			if (strcmp(s[i], s[j])>0){ //should change
				if(j==0){
					printf("up\n");
					tmp=s[i];
					for(int k=i-1;k>=j; k--){
						s[k+1]=s[k];
					}
					s[j]=tmp;
					i=0;
					break;
				}
				else{
					printf("down\n");
					tmp=s[i];
					for(int k=i-1;k>=0; k--){
						s[k+1]=s[k];
					}
					s[j]=tmp;				
					i=0;
					break;
				}
				
			}		
		} 
    }



    for(int i=0; i<n-1; i++){
        if(strcmp(s[i],s[i+1])<0){         
            
            return 1;
        }
    }
    printf("%s %s %s\n",s[0],s[1],s[2]);
    fprintf(stderr,"return 0");
    return 0;
}

int main()
{
	char **s;

	s = calloc(3, sizeof(char*));
	
	s[0] = calloc(11, sizeof(char));
	s[0]="a";
	s[1] = calloc(11, sizeof(char));
	s[1]="bc";
	s[2] = calloc(11, sizeof(char));
	s[2]="cd";
	
	//fprintf(stderr,"init\n");
	do
	{
		for (int i = 0; i < 3; i++)
			printf("%s%c", s[i], i == 3 - 1 ? '\n' : ' ');
		//fprintf(stderr,"forlop\n");
	} while (next_permutation(3, s));

	return 0;
}
