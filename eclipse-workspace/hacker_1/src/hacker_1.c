/*
 ============================================================================
 Name        : hacker_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

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
    char* tmp = "";

    for(int i=n-1; i>0; i--){
        if (strcmp(s[i-1], s[i])<0){
            strcpy(tmp,s[i]);
            strcpy(s[i],s[i-1]);
            strcpy(s[i-1],tmp);
            break;
        }
    }

    for(int i=0; i<n-1; i++){
        if(strcmp(s[i],s[i+1])<0){
            return 1;
        }
    }

    return 0;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
