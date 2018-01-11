#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Node
{
	int data = 0;
	Node* next = nullptr;
};

struct CircleList
{
	Node* start = nullptr;
	Node* end = nullptr;
};

Node* newNode(int data, Node *next = nullptr)
{
	Node* result = new Node();
	result->data = data;
	result->next = next;
	return result;
}

void addElement(CircleList& list, int element)
{
	if (list.start == nullptr)
	{
		list.start = newNode(element);
		list.start->next = list.start;
		list.end = list.start;
	}
	else
	{
		list.end->next = newNode(element, list.end->next);
		list.end = list.end->next;
	}
}

void addElementToStart(CircleList &list, int element)
{
	if (list.start == nullptr)
	{
		list.start = newNode(element);
		list.start->next = list.start;
		list.end = list.start;
	}
	else
	{
		Node *node1 = newNode(element);
		Node *node2 = list.start;
		list.start = node1;
		list.start->next = node2;
		list.end->next = list.start;
	}
}

void printList(CircleList& list)
{
	Node* node = list.start;

	if (node == nullptr)
	{
		printf("EMPTY\n");
	}
	else
	{
		do
		{
			printf("%d ", node->data);
			node = node->next;
		} while (node != list.start);

		printf("\n");
	}
}

void deleteList(CircleList& list)
{
	list.end->next = nullptr;
	while (list.start != nullptr)
	{
		Node* node = list.start;
		list.start = list.start->next;
		delete node;
	}
	list.end = nullptr;
}

void printMenu()
{
	printf("\tМеню\n");
	printf("\t0 - Выход\n");
	printf("\t1 - заполнить список случайными значениями (размер списка и диапазон значений задаются с консоли)\n");
	printf("\t2 - развернуть список\n");
	printf("\t3 - распечатать список\n");
}

void initList(CircleList &list, int len, int a, int b)
{
	if (list.start != nullptr)
	{
		deleteList(list);
		CircleList list;
	}
	for (int i = 0; i < len; ++i)
	{
		addElement(list, rand() % (b - a) + a);
	}
}

CircleList reversList(CircleList &list, int len)
{
	CircleList result;
	Node* tempNode = list.start;
	for (int i = 0; i < len; ++i)
	{
		addElementToStart(result, tempNode->data);
		tempNode = tempNode->next;
	}
	deleteList(list);
	return result;
}

void makeChoice(int choice, CircleList &list, int &len)
{
	int a = 0;
	int b = 0;
	switch (choice)
	{
	case 1:
		printf("Введите длину списка и диапазон значений от а до b");
		scanf("%d %d %d", &len, &a, &b);
		initList(list, len, a, b);
		break;
	case 2:
		list = reversList(list, len);
		break;
	case 3:
		printList(list);
		break;
	}
}
int main()
{
	CircleList list;
	setlocale(LC_ALL, "Russian");
	int len = 0;

	int choice = 0;

	do {
		printMenu();
		printf("Ваш выбор: ");
		scanf("%d", &choice);
		makeChoice(choice, list, len);
	} while (choice != 0);

	deleteList(list);

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}