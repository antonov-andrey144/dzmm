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

Node* lastLess(List& list, int element)
{
	if (list.start == nullptr || list.start->data >= element)
	{
		return nullptr;
	}

	Node* node = list.start;
	while (node->next != nullptr && node->next->data < element)
	{
		node = node->next;
	}

	return node;
}

void addElement(List& list, int element)
{
	Node* previousNode = lastLess(list, element);
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

void removeElement(List& list, int element)
{
	if (list.start == nullptr)
	{
		return;
	}

	Node* node = lastLess(list, element);

	if (node == nullptr)
	{
		while (list.start != nullptr && list.start->data == element) //���� ����� ������ �� ��� ����������, � ���� �� if ������ while
		{
			Node* tnode = list.start;
			list.start = list.start->next;
			delete tnode;
		}
	}
	else
	{
		while (node->next != nullptr && node->next->data == element) //���� ����� ������ �� ��� ����������, � ���� �� if ������ while
		{
			Node* tnode = node->next;
			node->next = tnode->next;
			delete tnode;
		}
	}
}

void printMenu()
{
	printf("\t����\n");
	printf("\t0 - �����\n");
	printf("\t1 - �������� �������� � ������������� ������\n");
	printf("\t2 - ������� �������� �� ������\n");
	printf("\t3 - ����������� ������\n");
}

void makeChoice(int choice, List &list)
{
	char searchName[20] = "";
	char searchNumber[20] = "";
	int element = 0;
	switch (choice) {
	case 1:
		printf("������� ������� ");
		scanf("%d", &element);
		addElement(list, element);
		break;
	case 2:
		printf("������� ������� ");
		scanf("%d", &element);
		removeElement(list, element);
		break;
	case 3:
		printList(list);
		break;
	}
}

int main()
{
	List list;

	setlocale(LC_ALL, "Russian");
	int choice = 0;

	do {
		printMenu();
		printf("��� �����: ");
		scanf("%d", &choice);
		makeChoice(choice, list);
	} while (choice != 0);

	deleteList(list);

	system("PAUSE");
	return 0;
}