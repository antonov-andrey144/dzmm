#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "list.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	
	List* list;
	initList(list);
	printList(list);

	List* list2;
	Node* tempNode = list->start;

	deleteList(list);


	return 0;
}