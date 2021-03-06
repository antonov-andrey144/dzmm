#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HashTable.h"

int main()
{
	HashTable* table = hashTableCreate(256); // ��� ����� ������ ������ �������

	FILE* file = fopen("input.txt", "r");

	while (!feof(file))
	{
		char* str = new char[50];
		fscanf(file, "%s", str);
		hashTableAdd(table, str);
	}

	fclose(file);

	hashTablePrint(table);
	printf("\n\t\tMax list length : %d\n\t\tAverage list length : %3.2f\n\t\tFill coeff : %3.2f\n", hashTableMaxLength(table), hashTableAverageLength(table), hashTableFillCoeff(table));


	hashTableDelete(table);

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}