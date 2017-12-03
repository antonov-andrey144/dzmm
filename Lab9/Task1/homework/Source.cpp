#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HashTable.h"

int main()
{
	HashTable* table = hashTableCreate(256); // тут можно задать размер таблицы

	FILE* file = fopen("input.txt", "r");

	char* str;
	while (!feof(file))
	{
		str = new char[50];
		fscanf(file, "%s", str);
		hashTableAdd(table, str);
	}

	fclose(file);

	hashTablePrint(table);
	printf("\n\t\tMax list length : %d\n\t\tAverage list length : %3.2f\n\t\tFill coeff : %3.2f\n", hashTableMaxLength(table), hashTableAverageLength(table), hashTableFillCoeff(table));


	hashTableDelete(table);

	system("pause");
	return 0;
}