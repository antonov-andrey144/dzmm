#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

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

void countingSort(int *arr, int len, int n, int *helpingArr)
{
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
			arr[number] = i;
			++number;
		}
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
	int *helpingArr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		helpingArr[i] = 0;
	}

	initArray(arr, len, n);
	printf("Неотсортированный массив:\n");
	printArray(arr, len);

	countingSort(arr, len, n, helpingArr);
	printf("Отсортированный массив:\n");
	printArray(arr, len);

	system("PAUSE");
	return 0;
}