#include "string.h"

int my_strlen(const char *str){
	
	int count = 0;
	while (*str++)
		++count;
		
	return count;

}

void my_strcpy(char *des, const char *src){
	
	while(*des++ = *src++)
		; //must include

}


void my_strcat(char *des, const char *src){
	my_strcpy(des + strlen(des), src);


}

int my_strcmp(const char *s1, const char *s2){
	while(*s1++ == *s2++)
		;
	return *s1 - *s2;
}
