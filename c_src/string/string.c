#include "string.h"

int my_strlen(const char *str){
	int i=0;
	while(str[i] != '\0'){
		++i;
	}
	return i;

}

void my_strcpy(char *des, const char *src){
	int i=0;
	while(src[i] != '\0'){
		des[i] = src[i];
		++i;
	}
	des[i] = src[i];	


}


void my_strcat(char *des, const char *src){
	int i=0;
	while(des[i] != '\0'){
		++i;
	}
	int k=0;
	while(src[k] != '\0'){
		des[i] = src[k];
		++k;
		++i;
	}
	des[i] = src[k];	


}

int my_strcmp(const char *s1, const char *s2){
	int i;
	while(s1[i] != '\0'|| s2[i] != '\0'){
		if(s1[i] != s2[i]) return 1;
		++i;
	}
	return 0;

}
