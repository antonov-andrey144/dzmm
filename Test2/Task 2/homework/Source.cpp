#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BiList.h"

void printMenu()
{
	printf("Выберите действие\n");
	printf("\t0 - Выйти из программы\n");
	printf("\t1 - Добавить значение в заданную позицию в двусвязный список\n");
	printf("\t2 - Удалить значение в заданной позиции из списка\n");
	printf("\t3 - Распечатать список\n");
	printf("\t4 - Распечатать список задом наперед\n");
}

void makeChoice(int choice, BiList* list)
{
	int data = 0;
	int pos = 0;
	switch (choice)
	{
	case 1:
		printf("Введите элемент для добавления ");
		scanf("%d", &data);
		printf("Введите позицию для добавления ");
		scanf("%d", &pos);
		listAddToPos(list, pos, data);
		break;
	case 2:
		printf("Введите позицию для удаления ");
		scanf("%d", &pos);
		listRemoveFromPos(list, pos);
		break;
	case 3:
		listPrint(list);
		break;
	case 4:
		listPrintReverse(list);
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	BiList* list = listCreate();

	int choice = -1;

	do
	{
		printMenu();
		printf("Ваш выбор : ");
		scanf("%d", &choice);
		makeChoice(choice, list);
	} while (choice != 0);

	listDelete(list);

	return 0;
}