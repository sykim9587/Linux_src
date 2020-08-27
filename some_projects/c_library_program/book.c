
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "class.h"
#pragma warning(disable:4996)

//main 에서 선언된 전역변수 
extern Book* book;
extern int size;
extern int msize;
extern Member* mem;
extern int bookIndex;
extern int memIndex;
extern int numberofBooks;
extern int numberofMems;
extern int cont;
extern int bsearchidx; 

void bookReg(Book* book) {
	if (bookIndex == size) {
		size += 5;
		book = (Book*)realloc(book, size*sizeof(Book));
		if (book == NULL) {
			printf("Sorry there is no more space left! \n");
			return;
		}
		printf("More space allocated! with realloc-> now %d books can be registered.\n", size);
	}
	printf("========Book registration=======\n");
	char Btitle[50];
	char Bauthor[50];
	getchar();
	printf("Title: ");
	fgets(Btitle, sizeof(Btitle), stdin);					//fgets 해야 중간에 space 입력 가능
	Btitle[strlen(Btitle) - 1] = '\0';						//fgets 함수는 마지막 엔터까지 저장이 되어서 지워야 한다. 
	strcpy((book + bookIndex)->title, Btitle);

	printf("Author: ");
	fgets(Bauthor, sizeof(Bauthor), stdin);
	Bauthor[strlen(Bauthor) - 1] = '\0';
	strcpy((book + bookIndex)->author, Bauthor);

	(book + bookIndex)->rent = 0; //not rented yet
	(book + bookIndex)->rentID = 0;

	printf("title: %s\n", (book + bookIndex)->title);
	printf("author: %s\n", (book + bookIndex)->author);
	printf("Book registered!\n");
	numberofBooks += 1;
	printf("Currently %d books available.\n", numberofBooks);
	bookIndex++;
	printf("\n\n");
	//getchar();
}

void blist(Book* book) {								
	printf("========Book List=======\n");
	for (int i = 0; i < bookIndex; i++) {
		if (strcmp((book + i)->title, "Delete") == 0) continue;												// 삭제된 책은 출력 안하기
		printf("Book title: %s\n", (book + i)->title);
		printf("Book Author: %s\n", (book + i)->author);
		printf("Is it rented? %c\n", ((book + i)->rent) == 1 ? 'y' : 'n');
		if (((book + i)->rent) == 1) {
			printf("Rented by ID number = %d\n", (book + i)->rentID);
		}
		printf("======================\n");
	}
	getchar();
}

void bdelete(Book* book) {									
	printf("========Book Delete=======\n");
	char Btitle[50];
	char Bauthor[50];
	getchar();
	printf("Title of the book you want to delete: ");
	fgets(Btitle, sizeof(Btitle), stdin);
	Btitle[strlen(Btitle) - 1] = '\0';

	printf("Author of the book you want to delete: ");
	fgets(Bauthor, sizeof(Bauthor), stdin);
	Bauthor[strlen(Bauthor) - 1] = '\0';


	for (int i = 0; i < bookIndex; i++) {
		if (strcmp((book + i)->title, Btitle) == 0 && strcmp((book + i)->author, Bauthor) == 0) {
			strcpy((book + i)->title, "Delete");
			strcpy((book + i)->author, "Delete");
			printf("Book ""%s"" is now deleted\n", (book + i)->title);
			numberofBooks -= 1;
			return;
		}
	}
	printf("Book not found.\n\n");

}

void booksearch(Book* book) {
	printf("========Book search=======\n");
	char Btitle[50];
	char Bauthor[50];
	int select;
	getchar();
	do {
		printf("How do you want to search?\n1. Title 2. Author\n==========================\n=");
		scanf("%d", &select);
		getchar();
	} while (select != 1 && select != 2);								//1이나 2아니면 다시 입력

	if (select == 1) {
		printf("Title of the book you want to find: ");
		fgets(Btitle, sizeof(Btitle), stdin);								//fgets 해야 중간에 space 입력 가능
		Btitle[strlen(Btitle) - 1] = '\0';									//	fgets 함수는 마지막 엔터까지 저장이 되어서 지워야 한다. 
		for (int i = 0; i < bookIndex; i++) {
			if (strcmp((book + i)->title, Btitle) == 0) {				//같으면 0
				bsearchidx = i;
				printf("your book [%s] is found!\n", (book + i)->title);
				printf("Author name : %s\n", (book + i)->author);
				printf("%s\n", ((book + i)->rent) == 1 ? "The book is not available!" : "The book is available!");
				return;
			}
		}
		printf("Book not found.\n\n");
		bsearchidx = -1;
	}
	else if (select == 2) {
		printf("Author of the book you want to find: ");
		fgets(Bauthor, sizeof(Bauthor), stdin);							//fgets 해야 중간에 space 입력 가능
		Bauthor[strlen(Bauthor) - 1] = '\0';								//fgets 함수는 마지막 엔터까지 저장이 되어서 지워야 한다. 
		for (int i = 0; i < bookIndex; i++) {
			if (strcmp((book + i)->author, Bauthor) == 0) {		//같으면 0
				bsearchidx = i;
				printf("your book is found!\n");
				printf("Book title : %s\n", (book + i)->title);
				printf("%s\n", ((book + i)->rent) == 1 ? "The book is not available!" : "The book is available!");
				return;
			}
		}
		printf("Book not found.\n\n");
		bsearchidx = -1;
	}
}


void writefile(Book* book) {
	FILE *fp = fopen("library_db.txt", "w");
	Book *ptr = book;
	fprintf(fp, "%50s %20s %20s %20s\n\n", "<Book Title>","<Book Author>","<Rent Status>","<member ID>");
	for (int i = 0; i < bookIndex; i++) {	
		if (strcmp(ptr->title, "Delete") == 0) ptr++;
		else {
			int a = *(ptr->author);
			fprintf(fp, "%50s %30s %20s %30d\n", ptr->title, ptr->author, a == 1 ? "yes" : "no", ptr->rentID);
			// book title, author, rent-state, rent-member-id
			ptr++;
		}
		
	}
	fclose(fp);
	printf("Wrote to Library_db.txt file!\n");
	getchar();
}