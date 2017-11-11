#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

int countZero(int *arr, int len)
{
	int count = 0;
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == 0)
		{
			++count;
		}
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	
	int n = 0;
	printf("Введите кол-во элементов массива\n");
	scanf("%d", &n);
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 5;
	}

	printf("Кол-во нулевых элементов = %d\n", countZero(arr, n));

	delete[] arr;

	system("PAUSE");
	return 0;
}