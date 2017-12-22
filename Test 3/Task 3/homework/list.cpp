#include <iostream>
#include "list.h"

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