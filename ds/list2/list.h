#ifndef LIST_H
#define LIST_H

typedef struct node {
	//int data; void pointer is complex, saving 4 space is easier
	struct node *next;
} Node;

typedef struct {
	Node *ptr;
	int eleSize;
} List;

void initList(List *pList, int eleSize);
void cleanupList(List *pList);

void printList(const List *pList, void (*print)(const void *pData));

void insertFirstNode(List *pList, const void *pData); // to get the address of any data
void insertNode(List *pList, const void *pPrevData, const void *pData); //insert data after prevData
void deleteNode(List *pList, const void *pData); // delete the data
#endif
