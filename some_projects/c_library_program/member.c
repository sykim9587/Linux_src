#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "class.h"
#pragma warning(disable:4996)

//다른 곳에서 선언된 전역변수 및 함수
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
extern void booksearch(Book* book);

//회원 등록 함수
void mReg(Member* mem) {														
	if (memIndex == msize) {																	//동적할당: 자리 부족 시 구조체 20개씩 추가
		msize += 5;
		mem = (Member*)realloc(mem, sizeof(Member) * msize);
		if (mem == NULL) {
			printf("Sorry there is no more space left! \n");
			return;
		}
		printf("More space allocated! with realloc-> now %d members can be registered.\n", msize);
	}
	printf("========Member registration=======\n");
	char Mname[50];
	getchar();
	printf("Name: ");
	fgets(Mname, sizeof(Mname), stdin);												//fgets 해야 중간에 space 입력 가능
	Mname[strlen(Mname) - 1] = '\0';													//fgets 함수는 마지막 엔터까지 저장이 되어서 지워야 한다. 
	strcpy((mem + memIndex)->name, Mname);									//입력한 이름을 구조체에 입력

	printf("memberID: ");
	scanf("%d", &mem[memIndex].MemberID);

	(mem + memIndex)->booknum = 0;												//회원 가입이니까 booknum =0 초기화
	for (int i = 0; i < 3; i++) {																	//Mem 구조체 안에 있는 Book 구조체 배열의 제목 모두 "0"으로 초기화
		strcpy((mem + memIndex)->rent[i].title, "0");
	}

	printf("Name: %s\n", (mem + memIndex)->name);
	printf("Member ID:  %d\n", (mem + memIndex)->MemberID);
	printf("Member registered!\n");
	numberofMems += 1;																			//실제 등록된 회원수 index 증가 (회원 삭제시 감소하는 인덱스)
	printf("Currently %d members registered.\n", numberofMems);
	memIndex++;																							//등록된 회원수 인덱스 증가  (회원 삭제시에도 유지되는 인덱스)
	printf("\n\n");
	getchar();
}

//멤버 출력 함수 
void mlist(Member* mem) {
	printf("========Member List=======\n");
	for (int i = 0; i < memIndex; i++) {															//등록된 회원수 인덱스 만큼 for loop							
		printf("Name: %s\n", (mem + i)->name);
		printf("Member ID: %d\n", (mem + i)->MemberID);
		if (((mem + i)->booknum)>0) {															//(if문)회원의 booknum이 0보다 큰 경우, 책을 빌린 것 이므로 몇 권 빌렸는지 출력
			printf("Until now, rented %d books\n", (mem + i)->booknum);
		}
		else {																									//(else문)booknum ==0 이므로 0권 빌렸다고 출력
			printf("Rented book : 0\n");															
		}
		printf("======================\n");
	}
	getchar();
}


//책 대출 함수
void bookRent(Book* book, Member* mem) {							
	int id;
	printf("member ID =");																			// ID입력받기 
	scanf("%d", &id);
	Member* mptr = mem;
	Book* bptr = book;
	for (int i = 0; i < memIndex; i++) {															//존재하는 회원수 만큰 for loop
		if (mptr->MemberID == id) {																//(if문) 아이디가 일치한다면
			if (mptr->booknum < 3) {																// (if문)빌린 책의 개수가 3개 미만이라면 (최대가 3)
				bsearchidx = -1;																			//bsearcchidx 를 -1로 다시 초기화 하고 
				booksearch(book);																		//책 검색 함수를 돌려서 bsearchidx를 변경시킨다. 
				if (bsearchidx >= 0) {																	// (if문) bsearchidx >=0 이면 : 책 찾은경우
					if (bptr[bsearchidx].rent == 0) {											//(if문) 그 책의 rent 변수가 0이라 아직 아무도 빌려가지 않았다면
						int k = mptr->booknum;
						bptr[bsearchidx].rent = 1;													//rent 변수를 1로 바꾸고 (이제 대출됨을 나타냄)
						bptr[bsearchidx].rentID = mptr->MemberID;					//MemberID를 rentID에 저장시키고
						for (int q = 0; q < k + 1; q++) {											//이 회원의 책을 저장할 수 있는 book 구조체 3칸중
							if (strcmp(mptr->rent[q].title, "0") == 0) {					//title이 0으로 되어있는 칸은 빈칸이니까 그 칸 (구조체)에 주소와 지은이를 넣는다. 
								strcpy(mptr->rent[q].title, bptr->title);
								strcpy(mptr->rent[q].author, bptr->author);
								(mptr->booknum)++;													//책을 빌렸으니까 이 회원의 booknum을 한개 증가시킨다. 
								printf("Book Rented!\n");
								return;
							}
						}
					}
					else {																						//찾은 책의 rent 가 이미 1이라 누가 빌려간 경우
						printf("The book is already rented! Sorry!\n");
						return;
					}
				
					
				}																									 //책을 못 찾은경우
				else {
					printf("Sorry!\n");
					return;
				}
			}
			else {																								//책을 벌써 3권 빌린경우
				printf("You already borrowed 3 books!\n");
				getchar();
				return;
			}
		}

		mptr++;
	}

	printf("ID does not exist.\n");
		
	getchar();
}

//책 반납 함수
void bookReturn(Book* book, Member* mem) {
	int id;
	printf("member ID =");
	scanf("%d", &id);
	Member* mptr = mem;
	Book* bptr = book;
	for (int i = 0; i < memIndex; i++) {
		if (mptr->MemberID == id) {		
			if (mptr->booknum > 0) {	
				bsearchidx = -1;		
				printf("Search the book you want to return!\n");
				booksearch(book);
				if (bsearchidx >= 0) { 
					int k = mptr->booknum;

					
					for (int j = 0; j < k; j++) { 
						if (strcmp(mptr->rent[j].title, bptr->title) == 0) { 
							strcpy(mptr->rent[j].title, "0"); 
							strcpy(mptr->rent[j].title, "0");
							printf("Book Returned!\n");
							(mptr->booknum)--;
							bptr[bsearchidx].rent = 0;
							bptr[bsearchidx].rentID = 0;
							return;
						}
					}
					printf("You didn't borrow that book!\n");
					return;
				}
				else {
					printf("you didn't borrow that book!\n");
					
					return;
				}
			}
			else {
				printf("You didn't borrow any books yet!\n");
				getchar();
				return;
			}
		}
		mptr++;
	}
	printf("ID does not exist.\n");
	getchar();
	return;

}
