#pragma once


typedef struct Book {
	char title[50];				//책 제목
	char author[50];			//책 지은이
	int rent;						//빌려진 상태면 1, 아니면 0
	int rentID;					//책을 빌린 회원의 회원번호
}Book;

typedef struct Member {
	char name[50];			//회원 이름
	int MemberID;			//회원 번호
	int booknum;			//현재 빌린 책 권수
	Book rent[3];				//빌린 책을 저장하는 크기가 3인  Book 구조체 배열
}Member;
