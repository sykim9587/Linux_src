#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

static Node *createNode(int data, Node *next) //only list.c functions can access
{
	Node *ptr = malloc(sizeof(Node));
	assert(ptr );
	ptr->data = data;
	ptr->next = next;
	
	return ptr; //returning pointer that is created in HEAP. not common
}


void initList(List *pList){
	//pList->ptr = malloc(sizeof(Node)); //creating dummy node
	//assert(pList->ptr);
	//pList->ptr->data = ?? //doesn't matter
	//pList->ptr->next = NULL;
	pList->ptr = createNode(-1, NULL);
}

void cleanupList(List *pList){
	Node *ptr = pList->ptr; // creating a pointer that points at Node type!
	while(ptr ){
		Node *tmp = ptr; // to delete without interfering with free 
		ptr = ptr->next; 
		free(tmp);
	}
}

void printList(const List *pList){
	Node *ptr = pList->ptr->next; //pointing first real value
	printf("[");
	while(ptr ){
		printf("%d%s", ptr->data, (ptr->next)? ", ":"");
		ptr=ptr->next;
	}
	printf("]\n");
	
}

void insertFirstNode(List *pList, int data){
	//Node *ptr = malloc(sizeof(Node));
	//assert(ptr );
	//ptr->data = data;
	//ptr->next = pList->ptr->next; //putting dummy node's next into this
	//pList->ptr->next = ptr; //ptr's address in dummy node next
	pList->ptr->next = createNode(data, pList->ptr->next);
}

void insertNode(List *pList, int prevData, int data){
	Node *ptr =pList->ptr->next; //looking at the real value node
	while(ptr ){
		if(ptr->data == prevData)
			break; 
		ptr=ptr->next;
	}
	
	if(ptr ) { //if not NULL, it is found!
		//Node *tmp = malloc(sizeof(Node));
		//assert(tmp );
		//tmp->data = data;
		//ptr is currently pointing at the previous node 
		//tmp->next = ptr->next;
		//ptr->next = tmp;
		ptr->next = createNode(data, ptr->next);
	}
	//if not found, nothing happens
}

void deleteNode(List *pList, int data){
	Node *ptr1 = pList->ptr->next; //going first
	Node *ptr2 = pList->ptr; //following, now pointing dummy
	
	while(ptr1 ){
		if(ptr1->data == data)
			break;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;	
	}
	
	if(ptr1 ){ //found the value
		ptr2->next = ptr1->next; //skipping the deleted node
		free(ptr1);	
	}
}
