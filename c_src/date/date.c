#include "date.h" //for structure
#include <stdio.h>

void printDate(const Date* pd)
{
	printf("(%d/%d/%d)\n",(*pd).year, (*pd).month, (*pd).day);
	// pd->year, pd->month, pd->day possible
}
