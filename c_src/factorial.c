#include <stdio.h>

long long factorial(int);
int main(void)
{
	for (int i =1; i<=100; ++i)
		printf("%d! = %lld\n", i, factorial(i));
	return 0;
}

long long factorial(int n){
	long long result = 1LL;
	
	for(int i = 2; i <= n; ++i)
		result *= i;
	
	return result;
}

//int -> up to 13!
//double -> up to 20!
// big integer library -> to use bigger integer
