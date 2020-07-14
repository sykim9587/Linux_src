#ifndef LIST_H
#define LIST_H
#include <iostream>
class Node {
friend class List; //only List can approach class Node

private:
	int data;
	Node *next;
	Node(int data, const Node *next);
public:
	//main code can't approach these functions anyways since only List can create 'NODE'
	//Node* operator&();
	//const Node* operator&() const;
	//Node(const Node& rhs);
	//Node& operator=(const Node& rhs); //created but nothing inside
	//~Node();
	
	
	int getData() const;
	const Node* getNext() const;
};

class List {
friend std::ostream& operator<<(std::ostream& out, const List& rhs);

private: //some people write private at the end	
	Node *ptr;

	List(const List& rhs);
	List& operator=(const List& rhs);
	
	//void print(std::ostrea& out) const; //another method -> helper function

public:	
	List();
	~List();

//	void print();

	void insertFirstNode(int data);
	void insertNode(int prevData, int data); //insert data after prevData
	void deleteNode(int data); // delete the data

};


#endif
