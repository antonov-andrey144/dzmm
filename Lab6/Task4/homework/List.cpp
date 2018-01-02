#include "List.h"

Node* nodeCreate(Contact contact, Node* next)
{
	return new Node{ contact, next };
}

int nodeCompareByName(Node* node1, Node* node2)
{
	return strcmp(node1->contact.name, node2->contact.name);
}

int nodeCompareByPhone(Node* node1, Node* node2)
{
	return strcmp(node1->contact.phone, node2->contact.phone);
}

List* listCreate()
{
	return new List{ 0, nullptr , nullptr };
}

List* listCreate(Node* node)
{
	return new List{ 1, node, node };
}

void listAddFirst(List* list, Node* node)
{
	node->next = list->start;
	list->start = node;
	if (node->next == nullptr)
	{
		list->last = node;
	}
	list->length++;
}

void listAppend(List* list, Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	if (list->start == nullptr)
	{
		return listAddFirst(list, node);
	}
	list->last->next = node;
	list->last = node;
	list->length++;
}

void listAppend(List* list, List* append)
{
	if (append == nullptr || append->last == nullptr)
	{
		return;
	}
	list->last->next = append->start;
	list->last = append->last;
	list->length += append->length;
	append->start = nullptr;
	append->last = nullptr;
	append->length = 0;
}

Node* listExtractFirst(List* list) 
{
	if (list == nullptr || list->start == nullptr)
	{
		return nullptr;
	}
	if (list->start == list->last) {
		list->last = nullptr;
	}
	Node* result = list->start;
	list->start = list->start->next;
	result->next = nullptr;
	list->length--;
	return result;
}

int listLength(List* list)
{
	int length = 0;
	Node* temp = list->start;
	while (temp != nullptr)
	{
		temp = temp->next;
		length++;
	}
	return length;
}

void listPrint(List* list)
{
	if (list == nullptr || list->start == nullptr)
	{
		printf("EMPTY\n");
		return;
	}
	Node* temp = list->start;
	while (temp != nullptr)
	{
		printf("%s [%s]\n", temp->contact.name, temp->contact.phone);
		temp = temp->next;
	}
}

void listDelete(List* &list)
{
	if (list == nullptr) return;
	Node* temp = list->start;
	while (temp != nullptr) 
	{
		Node* ttemp = temp;
		temp = temp->next;
		delete ttemp;
	}
	delete list;
	list = nullptr;
}