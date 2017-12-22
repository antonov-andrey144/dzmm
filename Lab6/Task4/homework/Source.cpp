#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

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
	Node* start;
	Node* last;
};

Node* nodeCreate(Contact contact, Node* next = nullptr)
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
	return new List{ nullptr , nullptr };
}

List* listCreate(Node* node)
{
	return new List{ node, node };
}

void listAddFirst(List* &list, Node* node)
{
	node->next = list->start;
	list->start = node;
	if (node->next == nullptr)
	{
		list->last = node;
	}
}

void listAppend(List* &list, Node* &node)
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
}

void listAppend(List* &list, List* &append)
{
	if (append == nullptr || append->last == nullptr)
	{
		return;
	}
	list->last->next = append->start;
	list->last = append->last;
	append->start = nullptr;
	append->last = nullptr;
}

Node* listExtractFirst(List* list) {
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

List* mergeSortedLists(List* list1, List* list2, int sortBy, bool asc)
{
	List* result = listCreate();

	Node* temp1 = listExtractFirst(list1);
	Node* temp2 = listExtractFirst(list2);

	while (temp1 != nullptr && temp2 != nullptr) {
		int cmp = (sortBy == 0 ? nodeCompareByName(temp1, temp2) : nodeCompareByPhone(temp1, temp2));

		if (cmp < 0 == asc) {
			listAppend(result, temp1);
			temp1 = listExtractFirst(list1);
		}
		else if (cmp > 0 == asc)
		{
			listAppend(result, temp2);
			temp2 = listExtractFirst(list2);
		}
		else if (cmp == 0)
		{
			listAppend(result, temp1);
			listAppend(result, temp2);
			temp1 = listExtractFirst(list1);
			temp2 = listExtractFirst(list2);
		}
	}

	listAppend(result, temp1);
	listAppend(result, list1);
	listAppend(result, temp2);
	listAppend(result, list2);

	return result;
}

List* listMergeSort(List* list, int sortBy, bool asc) {
	int length = listLength(list);
	List** merging = new List*[length];
	for (int i = 0; i < length; ++i) {
		merging[i] = listCreate(listExtractFirst(list));
	}

	while (length != 1) {
		for (int i = 0; i < length; i += 2)
		{
			List* list1 = merging[i];
			merging[i] = nullptr;
			List* list2 = nullptr;
			if (i + 1 < length) {
				list2 = merging[i + 1];
				merging[i + 1] = nullptr;
			}
			merging[i / 2] = mergeSortedLists(list1, list2, sortBy, asc);
		}
		length = length / 2 + length % 2;
	}

	List* result = merging[0];
	delete[] merging;
	return result;
}

int main()
{
	List* list = listCreate();

	FILE* file = fopen("input.txt", "r");
	while (!feof(file))
	{
		Contact* contact = new Contact();
		fscanf(file, "%s - %s", contact->name, contact->phone);
		listAddFirst(list, nodeCreate(*contact));
	}
	fclose(file);

	listPrint(list);

	printf("\t\tTrying to sort by name ascending\n");
	list = listMergeSort(list, 0, true);
	listPrint(list);

	printf("\t\tTrying to sort by name descending\n");
	list = listMergeSort(list, 0, false);
	listPrint(list);

	printf("\t\tTrying to sort by phone ascending\n");
	list = listMergeSort(list, 1, true);
	listPrint(list);

	printf("\t\tTrying to sort by phone decending\n");
	list = listMergeSort(list, 1, false);
	listPrint(list);

	system("pause");
	return 0;
}