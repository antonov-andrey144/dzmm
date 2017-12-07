#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Node
{
	int data = 0;
	Node* next = nullptr;
};

struct List
{
	Node* start = nullptr;
};

Node* newNode(int data, Node *next = nullptr)
{
	Node* result = new Node();
	result->data = data;
	result->next = next;
	return result;
}

Node* last(List& list, int element)
{
	if (list.start == nullptr)
	{
		return nullptr;
	}

	Node* node = list.start;
	while (node->next != nullptr)
	{
		node = node->next;
	}

	return node;
}

int countElements()
{
	int len = 0;
	FILE* file = fopen("list.txt", "r");
	int element = 0;
	while (!feof(file))
	{
		fscanf(file, "%d", &element);
		++len;
	}
	fclose(file);
	return len;
}

void addElement(List& list, int element)
{
	Node* previousNode = last(list, element);
	if (previousNode != nullptr)
	{
		previousNode->next = newNode(element, previousNode->next);
	}
	else
	{
		list.start = newNode(element, list.start);
	}
}

void printList(List& list)
{
	Node* node = list.start;

	if (node == nullptr)
	{
		printf("EMPTY\n");
	}
	else
	{
		while (node != nullptr)
		{
			printf("%d ", node->data);
			node = node->next;
		}
		printf("\n");
	}
}

void deleteList(List& list)
{
	while (list.start != nullptr)
	{

		Node* node = list.start;
		list.start = list.start->next;
		delete node;
	}
}

void initList(List &list, int len)
{
	int element = 0;
	FILE* file = fopen("list.txt", "r");
	for (int i = 0; i < len; ++i)
	{
		fscanf(file, "%d", &element);
		addElement(list, element);
	}
	fclose(file);
}

int maxCount (List list)
{
	Node* tempNode = list.start;
	int count = 0;
	int maxCount = 0;
	while (tempNode != nullptr)
	{
		while (tempNode->next != nullptr &&(tempNode->data < tempNode->next->data ))
		{
			++count;
			tempNode = tempNode->next;
		}
		++count;
		tempNode = tempNode->next;
		if (count > maxCount)
		{
			maxCount = count;
		}
		count = 0;
	}
	return maxCount;
}

int findeIndex(List list, int maxCount)
{
	Node* tempNode = list.start;
	int count = 0;
	int index = 0;
	while (tempNode->next != nullptr)
	{
		while (tempNode->next != nullptr && (tempNode->data < tempNode->next->data))
		{
			++count;
			++index;
			tempNode = tempNode->next;
		}
		++count;
		++index;
		if (count == maxCount)
		{
			index -= count;
			return index;
		}
		tempNode = tempNode->next;
		count = 0;
	}
	return 0;
}

void initNewList(List list, List& newList, int index, int maxCount)
{
	Node* tempNode = list.start;

	for (int i = 0; i < index; ++i)
	{
		tempNode = tempNode->next;
	}
	for (int i = 0; i < maxCount; ++i)
	{
		addElement(newList, tempNode->data);
		tempNode = tempNode->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	List list;
	int len = countElements();
	initList(list, len);

	printf("Лист:\n");
	printList(list);

	int mostCount = maxCount(list);
	int index = findeIndex(list, mostCount);
	List newList;
	if (index != 0)
	{
		initNewList(list, newList, index, mostCount);
		printf("Новый лист:");
		printList(newList);
	}
	else 
	{
		printf("Лист пуст");
	}

	deleteList(list);
	deleteList(newList);
	int pause = 0;
	printf("\nВведите что-нибудь для выхода из программы\n");
	scanf("%d", &pause);
	return 0;
}