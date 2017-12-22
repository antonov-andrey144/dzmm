#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

void swap(int &a, int &b) 
{
	int c = a;
	a = b;
	b = c;
}

void bubbleSort(int* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void initArray(int *arr, int len, int n)
{
	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand() % n + 1;
	}
}

void printArray(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void countingSort(int *arr, int len, int n)
{
	int *helpingArr = new int[n] {};
	int count = 0;
	for (int i = 0; i < len; ++i)
	{
		++helpingArr[arr[i] - 1];
	}

	int number = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < helpingArr[i]; ++j)
		{
			arr[number] = i + 1;
			++number;
		}
	}
	delete[] helpingArr;
}

void printMenu()
{
	printf("\tМеню\n1 - заполнить массив случайными значениями/перезаполнить массив\n2 - сортировка подсчётом\n3 - сортировка пузырьком\n0 - выход\n\tВаш выбор: ");
}

void menuWorking(int choice, int *arr, int len, int n)
{
	switch (choice)
	{
	case 1:
		initArray(arr, len, n);
		printf("Неотсортированный массив: \n");
		printArray(arr, len);
		printMenu();
		break;

	case 2:
		countingSort(arr, len, n);
		printf("Отсортированный массив: \n");
		printArray(arr, len);
		printMenu();
		break;

	case 3:
		bubbleSort(arr, len);
		printf("Отсортированный массив: \n");
		printArray(arr, len);
		printMenu();

	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

	printf("Введите длину массива\n");
	int len = 0;
	scanf("%d", &len);
	int *arr = new int[len];
	printf("Значения в массиве будут в диапазоне от 1 до n, введите n\n");
	int n = 0;
	scanf("%d", &n);
	printMenu();

	int choice = -1;
	while (choice != 0)
	{
		scanf("%d", &choice);
		menuWorking(choice, arr, len, n);
	}

	delete[] arr;
	return 0;
}