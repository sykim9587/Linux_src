#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//circular queue
int main(void)
{
	Queue q1, q2;
	
	initStack(&q1,10);
	initStack(&q2,100);
	
	push(&q1,100);
	push(&q1,200);
	
	printf("q1: 1st pop(): %d\n", pop(&q1));
	
	push(&q1,300);
	printf("q1: 2nd pop(): %d\n", pop(&q1));
	printf("q1: 3rd pop(): %d\n", pop(&q1));
	
	push(&q2,500);
	push(&q2,600);
	
	printf("q2: 1st pop(): %d\n", pop(&q2));
	
	push(&q2,700);
	printf("q2: 2nd pop(): %d\n", pop(&q2));
	printf("q2: 3rd pop(): %d\n", pop(&q2));

	cleanupStack(&q1);
	cleanupStack(&q2);
	
	return 0;
}
