#include <stdio.h>

int strlenf(const char *str){
	int i = 0; 
	int length = 0;
	while(str[i] != '\0'){
	
	length ++;
	i++;
	}
	
	return length;
}


int main(void){
	const char *str = "hellohello";
	int length = strlenf(str);
	printf("length: %d\n", length);
	return 0;
}
