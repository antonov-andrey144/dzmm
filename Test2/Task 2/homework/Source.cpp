#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BiList.h"

void printMenu()
{
	printf("�������� ��������\n");
	printf("\t0 - ����� �� ���������\n");
	printf("\t1 - �������� �������� � �������� ������� � ���������� ������\n");
	printf("\t2 - ������� �������� � �������� ������� �� ������\n");
	printf("\t3 - ����������� ������\n");
	printf("\t4 - ����������� ������ ����� �������\n");
}

void makeChoice(int choice, BiList* list)
{
	int data = 0;
	int pos = 0;
	switch (choice)
	{
	case 1:
		printf("������� ������� ��� ���������� ");
		scanf("%d", &data);
		printf("������� ������� ��� ���������� ");
		scanf("%d", &pos);
		listAddToPos(list, pos, data);
		break;
	case 2:
		printf("������� ������� ��� �������� ");
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
		printf("��� ����� : ");
		scanf("%d", &choice);
		makeChoice(choice, list);
	} while (choice != 0);

	listDelete(list);

	return 0;
}