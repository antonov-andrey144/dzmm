#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Set.h"

void printMenu()
{
	printf("Выберите действие\n");
	printf("\t0 - Выйти из программы\n");
	printf("\t1 - Добавить элемент во множество\n");
	printf("\t2 - Удалить элемент из множества\n");
	printf("\t3 - Вывести множество по возрастанию\n");
	printf("\t4 - Вывести множество по убыванию\n");
	printf("\t5 - Проверить, содержится ли элемент во множестве\n");
	printf("\t6 - Заполнить множество элементами для теста\n");
	printf("\t7 - Вывод в виде дерева Right-Parent-Left\n");
	printf("\t8 - Вывод в виде дерева Left-Parent-Right\n");
}

void makeChoice(int choice, Set* set)
{
	int element = 0;
	switch (choice)
	{
	case 1:
		printf("Введите элемент для добавления ");
		scanf("%d", &element);
		addToSet(set, element);
		break;
	case 2:
		printf("Введите элемент для удаления ");
		scanf("%d", &element);
		removeFromSet(set, element);
		break;
	case 3:
		printSetAscend(set);
		break;
	case 4:
		printSetDescend(set);
		break;
	case 5:
		printf("Введите элемент ");
		scanf("%d", &element);
		if (containsInSet(set, element))
		{
			printf("Элемент содержится в множестве\n");
		}
		else
		{
			printf("Элемент не содержится в множестве\n");
		}
		break;
	case 6:
		addToSet(set, 10);
		addToSet(set, -2);
		addToSet(set, 15);
		addToSet(set, 7);
		addToSet(set, -5);
		addToSet(set, 12);
		addToSet(set, 20);
		addToSet(set, 5);
		addToSet(set, 9);
		addToSet(set, 3);
		addToSet(set, 6);
		addToSet(set, 8);
		break;
	case 7:
		printRPL(set);
		break;
	case 8:
		printLPR(set);
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Set* set = createSet();

	int choice = -1;

	do
	{
		printMenu();
		printf("Ваш выбор : ");
		scanf("%d", &choice);
		makeChoice(choice, set);
	} while (choice != 0);

	deleteSet(set);

	system("PAUSE");
	return 0;
}