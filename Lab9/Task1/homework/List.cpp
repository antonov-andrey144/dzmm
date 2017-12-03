#include "List.h"
#include <string>

struct Node
{
	Element data;
	int count;
	Node* next;
};

struct List
{
	Node* root;
};

Node* nodeCreate(Element data, Node* next = nullptr)
{
	return new Node{ data, 1, next };
}

void nodeDelete(Node* node)
{
	delete[] node->data;
	delete node;
}

Node* nodeGet(List* list, Element key)
{
	Node* temp = list->root;
	while (temp != nullptr && strcmp(temp->data, key) != 0)
	{
		temp = temp->next;
	}
	return temp;
}

List* listCreate()
{
	return new List{ nullptr };
}

void listDelete(List* list)
{
	while (list->root != nullptr)
	{
		Node* temp = list->root;
		list->root = list->root->next;
		nodeDelete(temp);
	}
}

int listLength(List* list)
{
	Node* node = list->root;
	int result = 0;
	while (node != nullptr)
	{
		++result;
		node = node->next;
	}
	return result;
}

void listAdd(List* list, Element key)
{
	Node* node = nodeGet(list, key);
	if (node == nullptr)
	{
		list->root = nodeCreate(key, list->root);
	}
	else
	{
		delete[] key;
		++node->count;
	}
}

void listPrint(List* list)
{
	Node* temp = list->root;
	while (temp != nullptr)
	{
		printf("[%d] - %s\n", temp->count, temp->data);
		temp = temp->next;
	}
}

bool listIsEmpty(List* list)
{
	return (list->root == nullptr);
}