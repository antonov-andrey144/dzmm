#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void swap(int &a, int &b) 
{
	int c = a;
	a = b;
	b = c;
}

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
	Node* node;

	while (list.start != nullptr)
	{
		node = list.start;
		list.start = list.start->next;
		delete node;
	}
}

void reverse(List* list)
{
	Node* temp = list->start->next;
	Node* newstart = list->start;
	newstart->next = nullptr;
	while (temp != nullptr)
	{
		Node* ttemp = temp;
		temp = temp->next;
		ttemp->next = newstart;
		newstart = ttemp;
	}
	list->start = newstart;
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

int main()
{
	setlocale(LC_ALL, "Russian");

	List list;
	int len = countElements();
	initList(list, len);

	printf("Лист до:\n");
	printList(list);

	reverse(&list);

	printf("\nЛист после:\n");
	printList(list);

	deleteList(list);
	system("Pause");
	return 0;
}