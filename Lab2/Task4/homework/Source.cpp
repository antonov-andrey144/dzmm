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
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sort(int* arr, int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
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
}

int main()
{
	srand(time(nullptr));
	int n = 0;
	scanf("%d", &n);
	int* arr = initArray(n);
	printArray(arr, n);

	printf("\n");

	sort(arr, 0, n - 1);

	printArray(arr, n);

	delete[] arr;
	system("PAUSE");
	return 0;
}