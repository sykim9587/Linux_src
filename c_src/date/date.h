#ifndef DATE_H // DATE_H_ also possible (system provided ones starts with _ like _DATA_)
#define DATE_H

typedef struct date {
	int year;
	int month;
	int day;
} Date; //capital

void printDate(const Date *pd); //pointer won't change the values inside - const

#endif
