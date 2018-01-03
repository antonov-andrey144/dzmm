#pragma once
#include <string>

struct Contact
{
	char name[15];
	char phone[15];
};

struct Node;

struct List;

/* �������� ���� � �������� ��������� � ���������� �� ��������� ����*/
Node* nodeCreate(Contact contact, Node* next = nullptr);

/* ��������� ���� ��� �� ����� ��������*/
int nodeCompareByName(Node* node1, Node* node2);

/* ��������� ���� ��� �� ������ �������� ��������*/
int nodeCompareByPhone(Node* node1, Node* node2);

/* �������� ������� ������ */
List* listCreate();

/* �������� ������ � �������� ������ �����*/
List* listCreate(Node* node);

/* ����������� ����� ������*/
int listLength(List* list);

/* ���������� ���� � ������ ������*/
void listAddFirst(List* list, Node* node);

/* ���������� ���� � ����� ������*/
void listAppend(List* list, Node* node);

/* ���������� ���� �������*/
void listAppend(List* list, List* append);

/* ���������� ������� �������� �� ������*/
Node* listExtractFirst(List* list);

/* ������ ������*/
void listPrint(List* list);

/* ������������ ������ �� ��� ������*/
void listDelete(List* &list);