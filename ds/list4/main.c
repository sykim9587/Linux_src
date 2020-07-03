#include <stdio.h>
#include "list.h"

//class version with create node - generic linked list <FINAL>

void printInt(const void *pData)
{
	printf("%d", *(int *)pData); //first type casting and then use
}

void printDouble(const void *pData)
{
	printf("%f", *(double *)pData);
}

//generic linked list -> used in the interview 

int main(void){

	List list1, list2; 
	initList(&list1, sizeof(int));
	initList(&list2, sizeof(double));
	int i, j;
	
	//list 1
	i=4; insertFirstNode(&list1, &i); //since we need the address
	i=3; insertFirstNode(&list1, &i);
	i=1; insertFirstNode(&list1, &i);
	
	j=1; i=2; insertNode(&list1,&j,&i);
		
	i=3; deleteNode(&list1,&i);
	printList(&list1, printInt); //function as the argument
	
	
	//list 2
	double d,f;
	d=4.4; insertFirstNode(&list2, &d); //since we need the address
	d=3.3; insertFirstNode(&list2, &d);
	d=1.1; insertFirstNode(&list2, &d);
	
	f=1.1; d=2.2; insertNode(&list2,&f,&d);
		
	d=3.3; deleteNode(&list2,&d);
	printList(&list2, printDouble);
	
	
	cleanupList(&list1);
	cleanupList(&list2);
	return 0;
}
