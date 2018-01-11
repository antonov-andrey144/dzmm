#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void swap(int &a, int &b) 
{
	int c = a;
	a = b;
	b = c;
}

void printArray(int* arr, int length)
{
	int count = 1;
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] != arr[i + 1])
		{
			printf("%d[%d], ", arr[i], count);
			count = 1;
		}
		else
		{
			++count;
		}
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

	int arr[100];
	printf("Введите не более ста элементов (через пробел, либо через энтер)\nПоследний элемент должен быть равен нулю.\n");
	int i = -1;
	int count = 0;
	do
	{
		++i;
		scanf("%d", &arr[i]);
		++count;
	} while (arr[i] != 0);

	printf("\n%d\n", count);
	bubbleSort(arr, count);
	printArray(arr, count);

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}