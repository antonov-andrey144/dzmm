#include "BiList.h"

struct Node
{
	Element data;
	Node* prev;
	Node* next;
};

struct BiList
{
	Node* start;
	Node* end;
	int length;
};

Node* createNode(Element data, Node* prev = nullptr, Node* next = nullptr)
{
	return new Node{ data, prev, next };
}

BiList* listCreate()
{
	return new BiList{ nullptr, nullptr, 0 };
}

void listDelete(BiList* list)
{
	while (list->start != nullptr)
	{
		Node* temp = list->start;
		list->start = list->start->next;
		delete temp;
	}
	list->end = nullptr;
	delete list;
}

Node* listGetPos(BiList* list, int pos)
{
	if (pos < 0)
	{
		return list->start;
	}
	if (pos >= 0 && pos < list->length)
	{
		if (pos > list->length / 2)
		{
			Node* result = list->end;
			for (int i = list->length; i > pos; --i)
			{
				result = result->prev;
			}
			return result;
		}
		else
		{
			Node* result = list->start;
			for (int i = 0; i < pos; ++i)
			{
				result = result->next;
			}
			return result;
		}
	}
	if (pos >= list->length)
	{
		return nullptr;
	}
}

void listAddToPos(BiList* list, int pos, Element data)
{
	if (list->length == 0)
	{
		list->start = list->end = createNode(data);
	}
	else
	{
		Node* next = listGetPos(list, pos);
		if (next == nullptr)
		{
			list->end->next = createNode(data, list->end);
			list->end = list->end->next;
		}
		else if (next == list->start)
		{
			list->start = createNode(data, next->prev, next);
			list->start->next->prev = list->start;
		}
		else
		{
			next->prev = createNode(data, next->prev, next);
			if (next->prev->prev != nullptr)
			{
				next->prev->prev->next = next->prev;
			}
		}
	}
	++list->length;
}

void listRemoveFromPos(BiList* list, int pos)
{
	if (list->length == 0)
	{
		return;
	}
	if (pos <= 0)
	{
		Node* temp = list->start;
		list->start = temp->next;
		if (list->start == nullptr)
		{
			list->end = nullptr;
		}
		else
		{
			list->start->prev = nullptr;
		}
		delete temp;
	}
	else if (pos >= list->length - 1)
	{
		Node* temp = list->end;
		list->end = temp->prev;
		if (list->end == nullptr)
		{
			list->start = nullptr;
		}
		else
		{
			list->end->next = nullptr;
		}
		delete temp;
	}
	else
	{
		Node* temp = listGetPos(list, pos);
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
	}
	--list->length;
}

void listPrint(BiList* list)
{
	if (list->length == 0)
	{
		printf("EMPTY\n");
	}
	else
	{
		printf("[%d] : {", list->length);
		Node* temp = list->start;
		while (temp != nullptr)
		{
			printf("%d", temp->data);
			if (temp->next != nullptr)
			{
				printf(", ");
			}
			temp = temp->next;
		}
		printf("}\n");
	}
}

void listPrintReverse(BiList* list)
{
	if (list->length == 0)
	{
		printf("EMPTY\n");
	}
	else
	{
		printf("[%d] : {", list->length);
		Node* temp = list->end;
		while (temp != nullptr)
		{
			printf("%d", temp->data);
			if (temp->prev != nullptr)
			{
				printf(", ");
			}
			temp = temp->prev;
		}
		printf("}\n");
	}
}