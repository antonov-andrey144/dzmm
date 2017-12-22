#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void initArray(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand() % 90 + 10;
	}
}

void printArray(int* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
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

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

	printf("Введите длину массива\n");
	int len = 0;
	scanf("%d", &len);
	int *arr = new int[len];

	initArray(arr, len);
	printf("Неотсортированный массив: \n");
	printArray(arr, len);
	printf("Oтсортированный массив: \n");
	bubbleSort(arr, len);
	printArray(arr, len);

	system("PAUSE");
	return 0;
}