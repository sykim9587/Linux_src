
static int seed; //static global - so main can't change it

void my_srand(int s) //initaliaing seed
{
	seed = s;
}

int my_rand(void) //generating random numbers
{
	seed= seed * 1103515245 + 12345;
  	return((unsigned)(seed/65536) % 32768);
}

