#ifndef ARRAY_H
#define ARRAY_H


class Array {
private:
	static const int ARRAYSIZE; //instead of Macro 
	
	int *pArr_;
	int size_;
	void set_arr(const int *pArr, int size); //help function - tool function
public:
	//Array * operator&();
	//const Array* operator&() const;
	
	explicit Array(int size = Array::ARRAYSIZE); //to keep the shape. arr2=10 won't work 
	Array(const int *pArr, int size);
	Array(const Array& rhs);
	~Array();
	
	Array& operator=(const Array& rhs);
	
	bool operator==(const Array& rhs) const;
	
	int size() const;
	//no set function since size and pArr are connected
	
	int &operator[](int index);
	const int &operator[](int index) const; //if array is const
	
};

#endif
