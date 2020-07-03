#include <stdio.h>
#include <string.h> //strtok
#include "book.h"

/*book list
	1. get list
	2. print
	3. search
	4. insert
	5. remove book
*/

int main(void)
{
	Book bookList[10];
	int count = 0;
	
	
	FILE *fin;
	fin = fopen("bookList.dat", "r");
	
	char buf[1024];
	char *delimiter = "@\n";
	char * token;
	while(fgets(buf, 1024, fin)!=NULL){ ; //\n also read	
		
		if(count==0){
			token = strtok(buf, delimiter);
			strcpy(bookList[count].title,token);
		}
		else{
			token = strtok(buf, delimiter);
			strcpy(bookList[count].title,token);
		}
		token = strtok(NULL, delimiter);
		strcpy(bookList[count].author,token);
		token = strtok(NULL, delimiter);
		strcpy(bookList[count].publisher,token);
		token = strtok(NULL, delimiter);
		strcpy(bookList[count].date,token);
		token = strtok(NULL, delimiter);
		strcpy(bookList[count].isbn,token);
		
		++count;
	}
	
	int i =0;
	
	for(i=0; i<count; ++i){
		printf("%s %s %s %s %s\n", bookList[i].title, bookList[i].author,
		bookList[i].publisher, bookList[i].date,bookList[i].isbn);
	}
	
	
	
	fclose(fin);
	return 0;
}
