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

void qsort(int* arr, int startIndex, int endIndex)
{
	if (startIndex >= endIndex) return;
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
	qsort(arr, startIndex, iteratorIndex - 1);
	qsort(arr, iteratorIndex, endIndex);
}

int mostFrequentElement(int* arr, int len)
{
	int frequency = 0;
	int frequentelement = 0;
	int tempfrequency = 1;
	int tempfrequentelement = arr[0];
	for (int i = 1; i < len; ++i) {
		if (tempfrequentelement == arr[i]) {
			tempfrequency++;
		}
		else
		{
			if (tempfrequency > frequency)
			{
				//printf("%d -> %d\n", tempfrequentelement, tempfrequency);
				frequentelement = tempfrequentelement;
				frequency = tempfrequency;
			}
			tempfrequency = 1;
			tempfrequentelement = arr[i];
		}
	}
	if (tempfrequency > frequency)
		return tempfrequentelement;
	else
		return frequentelement;
}

int main()
{
	srand(time(0));

	int* arr = 0;
	int n = 0;

	printf("Input n ");
	scanf("%d", &n);
	arr = initArray(n);
	qsort(arr, 0, n - 1);
	printf("\n");
	printArray(arr, n);

	printf("%d\n", mostFrequentElement(arr, n));

	delete[] arr;
	system("PAUSE");
	return 0;
}