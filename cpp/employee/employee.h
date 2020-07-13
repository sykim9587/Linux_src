#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "string.h"

class Employee {
private:
	int id_;
	String name_;
	Employee *pManager_;
	
	Employee();
	Employee(const Employee& rhs);
	Employee& operator=(const Employee& rhs);
public:

	// ~Employee();
	// Employee* operator&();
	// const Employee* operator&() const;
	
	Employee(int id, String name, const Employee *pManager);
	//~Employee();
	
	int getId() const;
	String getName() const;
	Employee* getManager() const;
	
	void setManager(const Employee* pManager);
	
	bool isDirector() const;
};

#endif
