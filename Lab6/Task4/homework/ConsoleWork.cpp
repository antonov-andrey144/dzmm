#include "ConsoleWork.h"

void startWork(List* &list)
{
	list = listCreate();
}

void doWork(List* &list)
{
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
	listMergeSort(list, 0, true);
	listPrint(list);

	printf("\t\tTrying to sort by name descending\n");
	listMergeSort(list, 0, false);
	listPrint(list);

	printf("\t\tTrying to sort by phone ascending\n");
	listMergeSort(list, 1, true);
	listPrint(list);

	printf("\t\tTrying to sort by phone decending\n");
	listMergeSort(list, 1, false);
	listPrint(list);
}

void endWork(List* &list)
{
	listDelete(list);
}
