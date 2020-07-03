#include <stdio.h>
#include "list.h"

//Linked list -> used in the interview 

int main(void){

	List list; // creating a pointer that points at the Node
	initList(&list);
	
	insertFirstNode(&list, 4);	//[4]
	printList(&list);
	insertFirstNode(&list, 3);//[3,4]
	printList(&list);
	insertFirstNode(&list, 1);//[1,3,4]
	printList(&list);
	
	insertNode(&list,1,2); //[1,2,3,4]
	printList(&list);
	
	deleteNode(&list,3);	//[1,2,4]
	printList(&list);
	
	cleanupList(&list);
	return 0;
}
