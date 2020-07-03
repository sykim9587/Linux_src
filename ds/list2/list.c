#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h> //memcpy 
#include "list.h"



void initList(List *pList, int eleSize){
	pList->ptr = malloc(sizeof(Node)); //creating dummy node
	assert(pList->ptr);
	pList->eleSize = eleSize;
	pList->ptr->next = NULL;	
}

void cleanupList(List *pList){
	Node *ptr = pList->ptr; // creating a pointer that points at Node type!
	while(ptr ){
		Node *tmp = ptr; // to delete without interfering with free 
		ptr = ptr->next; 
		free(tmp);
	}
}

void printList(const List *pList,void (*print)(const void *pData))
{
	Node *ptr = pList->ptr->next; //pointing first real value
	printf("[");
	while(ptr ){
		(print)(ptr+1);//giving (function name)(argument)
		printf("%s",(ptr->next)? ", ":"");
		ptr=ptr->next;
	}
	printf("]\n");	
}

void insertFirstNode(List *pList, const void *pData){
	Node *ptr = malloc(sizeof(Node)+pList->eleSize); //creating bigger space
	assert(ptr );
	//ptr->data = data;
	memcpy(ptr+1, pData, pList->eleSize); //(unsigned char *)ptr+ pList->eleSize
	ptr->next = pList->ptr->next; //putting dummy node's next into this
	pList->ptr->next = ptr; //ptr's address in dummy node next
}

void insertNode(List *pList, const void *pPrevData, const void *pData){
	Node *ptr =pList->ptr->next; //looking at the real value node
	while(ptr ){
		if(memcmp(ptr+1,pPrevData, pList->eleSize)==0)
			break; 
		ptr=ptr->next;
	}
	
	if(ptr ) { //if not NULL, it is found!
		Node *tmp = malloc(sizeof(Node)+pList->eleSize);
		assert(tmp );
		//tmp->data = data;
		memcpy(tmp+1, pData, pList->eleSize);
		//ptr is currently pointing at the previous node 
		tmp->next = ptr->next;
		ptr->next = tmp;
	}
	//if not found, nothing happens
}

void deleteNode(List *pList, const void *pData){
	Node *ptr1 = pList->ptr->next; //going first
	Node *ptr2 = pList->ptr; //following, now pointing dummy
	
	while(ptr1 ){
		if(memcmp(ptr1+1, pData, pList->eleSize)==0)
			break;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;	
	}
	
	if(ptr1 ){ //found the value
		ptr2->next = ptr1->next; //skipping the deleted node
		free(ptr1);	
	}
}
