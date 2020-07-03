#include <stdio.h>

int main(void)
{
	int width, height;
	double area;
	
	//printf("width: ");
	//scanf("%d",&width);
	//printf("height: ");	
	//scanf("%d",&height);
	printf("input width and height: ");
	scanf("%d %d", &width, &height);
	
	
	area = 0.5 * width * height;
	//1.0/2.0 possible, but not 1/2 since it becomes 0 
	
	printf("area: %.1f\n", area);
	
	
	return 0;
}

