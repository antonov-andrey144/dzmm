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
	for (int i = 0; i < len; i++)
	{
		result[i] = rand() % 90 + 10;
	}
	return result;
}

void printArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void qsort(int* arr, int startIndex, int endIndex)
{
	if (startIndex >= endIndex) return;
	int iteratorIndex = startIndex;
	int element = arr[startIndex];
	for (int i = startIndex; i <= endIndex; i++)
	{
		if (arr[i] < element)
		{
			swap(arr[i], arr[iteratorIndex]);
			iteratorIndex++;
		}
	}
	if (iteratorIndex == startIndex)
	{
		iteratorIndex++;
	}
	qsort(arr, startIndex, iteratorIndex - 1);
	qsort(arr, iteratorIndex, endIndex);
}

int contains(int* arr, int start, int end, int element) {
	if (start > end) return 0;
	if (element == arr[(start + end) / 2]) return 1;
	if (element < arr[(start + end) / 2])
		return contains(arr, start, (start + end) / 2 - 1, element);
	else
		return contains(arr, (start + end) / 2 + 1, end, element);
}

int main()
{
	srand(time(0));

	int* arrSource = 0;
	int* arr = 0;
	int n = 0;
	int k = 0;

	printf("Input n ");
	scanf("%d", &n);
	arrSource = initArray(n);

	printf("Input k ");
	scanf("%d", &k);
	arr = initArray(k);

	qsort(arrSource, 0, n - 1);

	printf("\n");
	printArray(arrSource, n);
	printf("\n");
	printArray(arr, k);

	printf("\n");


	for (int i = 0; i < k; i++)
	{
		if (contains(arrSource, 0, n, arr[i]))
		{
			printf("%d found\n", arr[i]);
		}
		else
		{
			printf("%d not found\n", arr[i]);
		}
	}

	delete[] arrSource;
	delete[] arr;
	system("PAUSE");
	return 0;
}