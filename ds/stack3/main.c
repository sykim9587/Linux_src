#include <stdio.h>
#include "stack.h"

// 3rd version, create several stacks
int main(void)
{
	Stack s1, s2;
	
	//s1.tos = 0;
	//s2.tos = 0;
	//since local var don't initialize but not good
	
	//use functions to use struct stack!!
	initStack(&s1);
	initStack(&s2); 
	
	push(&s1,100);
	push(&s1,200);
	push(&s1,300);
	
	printf("s1 1st pop(): %d\n", pop(&s1));
	printf("s1 2nd pop(): %d\n", pop(&s1));
	printf("s1 3rd pop(): %d\n", pop(&s1));
	
	push(&s2,900);
	push(&s2,800);
	push(&s2,700);
	
	printf("s2 1st pop(): %d\n", pop(&s2));
	printf("s2 2nd pop(): %d\n", pop(&s2));
	printf("s2 3rd pop(): %d\n", pop(&s2));	
	
	//printf("s2 4 pop(): %d\n", pop(&s2));	
	
	
	return 0;
}
