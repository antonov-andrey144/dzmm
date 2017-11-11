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

void killThem(CircleList& list, int m)
{
	Node* node = list.end;
	while (node->next != node)
	{
		for (int i = 0; i < m; ++i)
		{
			node = node->next;
		}
		Node* tnode = node->next;
		node->next = tnode->next;
		delete tnode;
	}
	list.start = node;
	list.end = node;
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

int main()
{
	CircleList list;
	int n = 0;
	int m = 0;

	setlocale(LC_ALL, "Russian");

	printf("¬ведите n ");
	scanf("%d", &n);
	printf("¬ведите m ");
	scanf("%d", &m);

	for (int i = 1; i <= n; ++i)
	{
		addElement(list, i);
	}

	killThem(list, m);

	printList(list);

	deleteList(list);

	system("PAUSE");
	return 0;
}