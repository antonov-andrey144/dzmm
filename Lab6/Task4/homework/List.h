#pragma once
#include <string>

struct Contact
{
	char name[15];
	char phone[15];
};

struct Node;

struct List;

/* создание ноды с заданным контактом и указателем на следующую ноду*/
Node* nodeCreate(Contact contact, Node* next = nullptr);

/* сравнение двух нод по имени контакта*/
int nodeCompareByName(Node* node1, Node* node2);

/* сравнение двух нод по номеру телефона контакта*/
int nodeCompareByPhone(Node* node1, Node* node2);

/* создание пустого списка */
List* listCreate();

/* создание списка с заданной первой нодой*/
List* listCreate(Node* node);

/* возвращение длины списка*/
int listLength(List* list);

/* добавление ноды в начало списка*/
void listAddFirst(List* list, Node* node);

/* добавление ноды в конец списка*/
void listAppend(List* list, Node* node);

/* склеивание двух списков*/
void listAppend(List* list, List* append);

/* извлечение первого элемента из списка*/
Node* listExtractFirst(List* list);

/* печать списка*/
void listPrint(List* list);

/* освобождение памяти из под списка*/
void listDelete(List* &list);