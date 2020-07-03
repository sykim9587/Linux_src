#include <stdio.h>
//#include <stdlib.h>
#include "queue.h"

//5th queue -> generic
int main(void)
{
	Queue q1, q2;
	int i;
	double d;
	
	initStack(&q1,10, sizeof(int));
	initStack(&q2,100, sizeof(double));
	
	i=100; push(&q1,&i);
	i=200; push(&q1,&i);	
	i=300; push(&q1,&i);

	pop(&q1, &i); printf("q1: 1st pop(): %d\n", i);
	pop(&q1, &i); printf("q1: 2nd pop(): %d\n", i);
	pop(&q1, &i); printf("q1: 3rd pop(): %d\n", i);
	
	d=1.1; push(&q2,&d);
	d=2.2; push(&q2,&d);
	pop(&q2, &d); printf("q2: 1st pop(): %lf\n", d);	
	d= 3.3; push(&q2,&d);
	pop(&q2, &d); printf("q2: 2nd pop(): %lf\n", d);
	pop(&q2, &d); printf("q2: 3rd pop(): %lf\n", d);
	
	cleanupStack(&q1);
	cleanupStack(&q2);
	
	return 0;
}
