/*
제목: 도서관 책관리 프로그램
작성자 : 김소영
작성일 : 2020 / 05 / 27 - 2020/05/29

<프로그램 특징>
1. 함수 13개 
		-main 에서 쓰이는 함수 4개
		-book 과 관련된 함수 5개 (book.c 에 따로 저장)
		-member 와 관련된 함수 4개 (member.c에 따로 저장)
2. 구조체 2개 (구조체 포인터 선언 - 동적할당)
		-Book : 책 제목, 지은이, 대여상태, 대여한 회원의 회원번호 
		-Member: 이름, 회원번호, 현재 대여한 책 권수, 대여한 책의 정보 저장하는 Book 구조체 배열 (크기 3)
		-동적할당으로 구조체크기 20개씩 할당. 부족하면 20개씩 추가

3. 손님메뉴와 직원메뉴
		while(1){
			switch문 - 고객매뉴
				1.책 리스트출력
				2.책 검색 (제목 또는 지은이)
				3.회원가입
				4.책 대여
				5.책 반납
				6.직원 메뉴
					    비밀번호 입력 함수->참이면
							while(1){
							10.새 책 등록
							11.책 삭제
							12.멤버 리스트 출력 (회원정보, 책 대여 개수)
							13.Library DB.txt로 책 리스트 출력 (책 정보, 대여 상태 및 대여 회원번호)
							14.고객메뉴로 돌아가기
							15.끝내기
							}
				7.끝내기
		}
		//각 함수 실행하고 계속 하는 여부 묻기 (14번 고객메뉴로 돌아가는 함수만 빼고)
		//잘못입력하면 다시 메뉴 출력

4. 실행 시나리오
	- 멤버 3명 등록, 책 5권 등록 
	- 비밀번호 실수, 입력
	- 파일 출력 & 리스트 멤버, 책 모두 출력
	- 책 삭제 후 출력
	- 멤버 한명이 3개 대여, 한명이 2개 대여
	-  3권 빌린 멤버가 대여 하려고 할때 (벌써 3권!)
	- 책 반납, 안 빌린 책 반납, 없는 책 반납
	- 누가 빌려간 책 대여 시도 
	- 중간 중간 출력

5. 나중에 추가하고 싶은/ 고치고 싶은 부분
	- 파일 저장하고 프로그램종료후에도 저장 -> 불러와서 다음 실행시 다시 구조체에 저장 
	- 저장 공간이 차서 realloc 할때 내용이 들어오지 않아서 쓰레기값이 나옴. 다시 시도 또는 새로운 포인터에 그 전 내용 복사하는 법
	- 책 삭제 후 그 자리를 낭비하지 않고 그 자리에 저장하기. (회원이 책 3권 빌린 후 한 권을 반납한 뒤 그 자리에 새 책 빌리는 로직 이용하면 될듯)
*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "class.h"
#include "init.h"
#pragma warning(disable:4996)



//함수선언
int password();																								//직원 메뉴로 들어갈 때 비밀번호 입력&비교하는 함수													
int askcont();																									//계속 while loop안에 있을건지 물어보는 함수
void staffmenu();																							//직원 메뉴 출력
void customermenu();																					//회원 메뉴 출력

//다른 source file에 정의되어있는 함수들
extern void bookReg(Book* book);												//책등록
extern void blist(Book* book);														//책 리스트 출력
extern void bdelete(Book* book);												//책 삭제
extern void booksearch(Book* book);											//책 검색	
extern void mReg(Member* mem);												//회원등록
extern void mlist(Member* mem);												//회원리스트 출력		
extern void writefile(Book* book);												//텍스트파일로 내보내기			
extern void bookRent(Book* book, Member* mem);				//책 대여			
extern void bookReturn(Book* book, Member* mem);			//책 반납

int main() {
	//동적할당
	mem = (Member*)malloc(sizeof(Member)*msize);
	book = (Book*)malloc(sizeof(Book) * size);

	if (book == NULL || mem == NULL) {
		printf("Malloc fail\n");
		return 0;
	}
	int choice = 0;									// 회원메뉴에서의 switch문 변수
	int staffchoice = 0;							    //직원메뉴에서의 switch문 변수
	while (1) {											//회원메뉴 무한루프 시작
		system("cls");									//메뉴 출력시 그 전 화면 지우기
		customermenu();
		printf("menu = ");
		scanf("%d", &choice);

		switch (choice) {								//회원메뉴 switch문 시작
		case BLIST:
			blist(book);
			cont = askcont();
			if (cont == 0) {
				return 0;
			}
			break;
		case BSEARCH:
			booksearch(book);
			cont = askcont();
			if (cont == 0) {
				return 0;
			}
			break;
		case MREGISTER:
			mReg(mem);
			cont = askcont();
			if (cont == 0) {
				return 0;
			}
			break;
		case RENT:
			bookRent(book, mem);
			cont = askcont();
			if (cont == 0) {
				return 0;
			}
			break; 
		case RETURN:
			bookReturn(book, mem);
			cont = askcont();
			if (cont == 0) {
				return 0;
			}
			break; 
		case STAFF:										//직원메뉴 시작
		{
			int flag = password();               //패스워드 맞으면 1, 틀리면 0 => 1이면 직원메뉴 무한루프 시작
			while (flag) {
				system("cls");
				staffmenu();
				printf("menu = ");
				scanf("%d", &staffchoice);
				switch (staffchoice) {
				case BREG:
					bookReg(book);
					cont = askcont();
					if (cont == 0) {
						return 0;
					}
					break;
				case BDELETE:
					bdelete(book);
					cont = askcont();
					if (cont == 0) {
						return 0;
					}
					break;
				case MLIST:
					mlist(mem);
					cont = askcont();
					if (cont == 0) {
						return 0;
					}
					break; 
				case BMFILE: 
					writefile(book);
					cont = askcont();
					if (cont == 0) {
						return 0;
					}
					break; 
				case GOBACK:												//회원메뉴로 돌아가기 위해 flag 0으로 변경- 무한루프 탈출
					flag = 0;
					break;
				case FINISH:													//프로그램 종료 위해서 return 0
				{
					printf("Program End! Thank you!\n");
					return 0;
				}
				default:
				{
					printf("Wrong input, choose again!\n");
					break;
				}
				}//switch 끝

			} //while 끝
			break;
		}
		case END:																	//프로그램 종료 위해서 return 0
		{
			printf("Program End! Thank you!\n");
			return 0;
		}
		default:
		{
			printf("Wrong input, choose again!\n");
		}
		}

	} //while 끝
	free(book);																			//동적할당 해제
	free(mem);
	return 0;
} // main 함수 끝

int askcont() {																 //계속 진행 여부 확인
	char select;
	do {																			//맞게 입력하게 하기위해 do while
		printf("Do you want to continue? (y/n) =");
		scanf("%c", &select);
		getchar();
	} while (select != 'y' && select != 'n');
	if (select == 'y') {
		return 1;
	}
	else {
		return 0;
	}
}

int password() {															//staff메뉴에 들어가기전 비밀번호 확인
	int password = 9587;
	int pw;
	getchar();
	printf("This is only for the staff. type the password: ");
	scanf("%d", &pw);
	if (password == pw) {
		printf("Correct! \n");
		return 1;
	}
	else {
		printf("Wrong!\n");
		return 0;
	}
}

void customermenu() {													//customer 메뉴 
	printf("====== Library ======\n");
	printf("1.book list\n2.book search\n3.member register\n4.book rent\n");
	printf("5.book return\n6.STAFF menu\n7.end\n");
	printf("======================\n");
}

void staffmenu() {															//customer 메뉴
	printf("====== STAFF menu======\n");
	printf("10.book register\n11.book delete\n12.member list\n13.write data to FILE\n");
	printf("14.go back to customer menu\n15.end\n");
	printf("======================\n");
}

