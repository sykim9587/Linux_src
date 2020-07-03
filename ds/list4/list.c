#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h> //memcpy 
#include "list.h"


static Node *createNode(int eleSize,const void *pData, Node *next) //only list.c functions can access
{
	Node *ptr = malloc(sizeof(Node)+eleSize);
	assert(ptr );
	memcpy(ptr+1, pData, eleSize);
	ptr->next = next;	
	return ptr; 
}

void initList(List *pList, int eleSize){

	//const void *pdata;	
	pList->eleSize = eleSize;
	pList->ptr = createNode(0, NULL,NULL); //pdata NULL possible
	
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
	Node *ptr = pList->ptr->next; 
	printf("[");
	while(ptr ){
		(print)(ptr+1);
		printf("%s",(ptr->next)? ", ":"");
		ptr=ptr->next;
	}
	printf("]\n");	
}

void insertFirstNode(List *pList, const void *pData){
	
	pList->ptr->next = createNode(pList->eleSize, pData, pList->ptr->next);
}

void insertNode(List *pList, const void *pPrevData, const void *pData){
	Node *ptr =pList->ptr->next; //looking at the real value node
	while(ptr ){
		if(memcmp(ptr+1,pPrevData, pList->eleSize)==0)
			break; 
		ptr=ptr->next;
	}
	
	if(ptr ) { //if not NULL, it is found!
		ptr->next = createNode(pList->eleSize,pData,ptr->next);
	}
}

void deleteNode(List *pList, const void *pData){
	Node *ptr1 = pList->ptr->next;
	Node *ptr2 = pList->ptr; 
	
	while(ptr1 ){
		if(memcmp(ptr1+1, pData, pList->eleSize)==0)
			break;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;	
	}
	
	if(ptr1 ){ 
		ptr2->next = ptr1->next; 
		free(ptr1);	
	}
}
