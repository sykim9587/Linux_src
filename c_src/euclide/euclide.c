#include <stdio.h>

int gcd(int a, int b)
{
	int c=(a>b)?a:b;
	int d=(c==a)?b:a;
	int k=-1;

	while(k!=0){
		k=c%d;
		c=d; 
		d=k;
	}
	return c;
}

int main(void)
{
	int a,b;
	scanf("%d %d", &a, &b);	
	printf("gcd : %d\n", gcd(a,b));	
	return 0;
}
