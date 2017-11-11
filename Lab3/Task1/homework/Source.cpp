#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

int* initArray(int len)
{
	int* result = new int[len];
	for (int i = 0; i < len; ++i)
	{
		result[i] = rand() % 90 + 10;
	}
	return result;
}

void printArray(int* arr, int len)
{
	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void insertSort(int* arr, int startIndex, int endIndex)
{
	for (int i = startIndex; i <= endIndex; ++i)
	{
		for (int j = i; j > startIndex && arr[j - 1] > arr[j]; --j)
		{
			swap(arr[j], arr[j - 1]);
		}
	}
}

void qsort(int* arr, int startIndex, int endIndex, int len)
{
	if ((endIndex - startIndex) < 10) {
		insertSort(arr, startIndex, endIndex);
	}
	else {
		if (startIndex >= endIndex) {
			return;
		}
		int iteratorIndex = startIndex;
		int element = arr[startIndex];
		for (int i = startIndex; i <= endIndex; ++i)
		{
			if (arr[i] < element)
			{
				swap(arr[i], arr[iteratorIndex]);
				++iteratorIndex;
			}
		}
		if (iteratorIndex == startIndex)
		{
			++iteratorIndex;
		}
		qsort(arr, startIndex, iteratorIndex - 1, len);
		qsort(arr, iteratorIndex, endIndex, len);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(nullptr));

	printf("Введите длину массива для сортировки\n");
	int n = 0;
	scanf("%d", &n);
	int *arr = initArray(n);

	printf("Неотсортированный массив: \n");
	printArray(arr, n);
	printf("\n");

	qsort(arr, 0, n - 1, n);
	printf("Отсортированный массив: \n");
	printArray(arr, n);

	delete[] arr;
	system("PAUSE");
	return 0;
}