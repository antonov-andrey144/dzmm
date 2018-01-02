#pragma once
#include <string>

struct Contact
{
	char name[15];
	char phone[15];
};

struct Node
{
	Contact contact;
	Node* next;
};

struct List
{
	int length;
	Node* start;
	Node* last;
};

Node* nodeCreate(Contact contact, Node* next = nullptr);

int nodeCompareByName(Node* node1, Node* node2);

int nodeCompareByPhone(Node* node1, Node* node2);

List* listCreate();

List* listCreate(Node* node);

void listAddFirst(List* list, Node* node);

void listAppend(List* list, Node* node);

void listAppend(List* list, List* append);

Node* listExtractFirst(List* list);

int listLength(List* list);

void listPrint(List* list);

void listDelete(List* &list);