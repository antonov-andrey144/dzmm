#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

void swap(int &a, int &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

void swap(int* arr, int start, int end)
{
	for (int i = start; i < (start + end) / 2; ++i)
		swap(arr[i], arr[end - i + start - 1]);
}

void print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	printf("ведите длинну отрезка n\n");
	int n = 0;
	scanf("%d", &n);
	printf("ведите длинну отрезка m\n");
	int m = 0;
	scanf("%d", &m);

	int* arr = new int[n + m];
	for (int i = 0; i < n + m; ++i)
	{
		arr[i] = rand() % 90 + 10;
	}

	print(arr, n + m);
	swap(arr, 0, n);
	swap(arr, n, n + m);
	swap(arr, 0, n + m);
	print(arr, n + m);

	delete[] arr;
	system("PAUSE");
	return 0;
}