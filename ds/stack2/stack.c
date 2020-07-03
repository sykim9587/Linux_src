static int stack[100];
static int tos =0; // top of stack

void push(int data)
{
	stack[tos] = data;
	++tos;
}

int pop(void)
{
	//int index = tos;
	--tos;
	return stack[tos]; //tos --
}
