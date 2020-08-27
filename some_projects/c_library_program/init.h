#pragma once
#include "class.h"
//전역변수 선언
Member* mem;
Book* book;
int size = 20;							//책 구조체 동적할당 사이즈
int msize = 20;						//회원 구조체 동적할당 사이즈
int bookIndex = 0;				//책 등록 인덱스
int memIndex = 0;				//회원 등록 인덱스
int numberofBooks = 0;		//실제 등록되어있는 책 개수
int numberofMems = 0;		//실제 등록되어있는 회원 수
int cont;									//계속 하는지 물어보는 변수
int bsearchidx = -1;              //Book Search 함수에서 입력된 책을 찾으면 변경해주는 변수. (못찾았을땐 -1로 초기화)

enum { BLIST = 1, BSEARCH, MREGISTER, RENT, RETURN, STAFF, END };			//customer 메뉴 열거형
enum { BREG = 10, BDELETE, MLIST, BMFILE, GOBACK, FINISH };	