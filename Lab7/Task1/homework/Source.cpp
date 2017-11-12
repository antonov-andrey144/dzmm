#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Set.h"

void printMenu()
{
	printf("�������� ��������\n");
	printf("\t0 - ����� �� ���������\n");
	printf("\t1 - �������� ������� �� ���������\n");
	printf("\t2 - ������� ������� �� ���������\n");
	printf("\t3 - ������� ��������� �� �����������\n");
	printf("\t4 - ������� ��������� �� ��������\n");
	printf("\t5 - ���������, ���������� �� ������� �� ���������\n");
	printf("\t6 - ��������� ��������� ���������� ��� �����\n");
	printf("\t7 - ����� � ���� ������ Right-Parent-Left\n");
	printf("\t8 - ����� � ���� ������ Left-Parent-Right\n");
}

void makeChoice(int choice, Set* set)
{
	int element = 0;
	switch (choice)
	{
	case 1:
		printf("������� ������� ��� ���������� ");
		scanf("%d", &element);
		addToSet(set, element);
		break;
	case 2:
		printf("������� ������� ��� �������� ");
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
		printf("������� ������� ");
		scanf("%d", &element);
		if (containsInSet(set, element))
		{
			printf("������� ���������� � ���������\n");
		}
		else
		{
			printf("������� �� ���������� � ���������\n");
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
		printf("��� ����� : ");
		scanf("%d", &choice);
		makeChoice(choice, set);
	} while (choice != 0);

	deleteSet(set);

	system("PAUSE");
	return 0;
}