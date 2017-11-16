#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

void swap(int &a, int &b) { 
	int c = a;
	a = b;
	b = c;
}

void printMenu() // ������ ����
{
	printf("\t����\n");
	printf("\t0 - �����\n");
	printf("\t1 - ��������� ������ ����� ���������� ����������\n");
	printf("\t2 - ������������� ������\n");
	printf("\t3 - ���������� ������\n");
	printf("\t4 - ��������� ������� �������������� ��������� �������\n");	
}

void initArray(int *arr, int len) // ���������� ������� ���������� ����������
{
	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand() % 90 + 10;
	}
}

void printArray(int* arr, int len) // ������ �������
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubbleSort(int* arr, int len) // ���������� ���������
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void makeChoice(int choice, int *arr, int len)//������������ �������� ��� ��� ������ � ��������
{												//����� ������������� ������� ���� �� printMenu
	switch (choice) {
	case 1:
		initArray(arr, len);
		printArray(arr, len);
		break;

	case 2:
		bubbleSort(arr, len);
		printArray(arr, len);
		break;

	case 3:
		for (int i = 0; i < len / 2; ++i)
		{
			swap(arr[i], arr[len - 1 - i]);
		}
		printArray(arr, len);
		break;

	case 4:
		int arithmetic�verage = 0; // ��������� �������� � ������� �� ����� 100, �� � ��� ����� ������� 2^31/100 = 21474836 �������� ��������� �������.
		for (int i = 0; i < len; ++i)
		{
			arithmetic�verage += arr[i];
		}
		arithmetic�verage /= len;
		printf("������� �������������� = %d\n", arithmetic�verage);
		break;
	}
}

int main(){
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

	printf("��������� �������� � ��������. ������� ������ �������\n");
	int n = 0;
	scanf("%d", &n);
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = 0;
	}
	printArray(arr, n);

	int choice = 0;
	do {
		printMenu();
		printf("��� �����: ");
		scanf("%d", &choice);
		makeChoice(choice, arr, n);
	} while (choice != 0);

	delete[] arr;
	system("PAUSE");
	return 0;
}