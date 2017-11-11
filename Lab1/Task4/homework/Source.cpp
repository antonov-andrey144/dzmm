#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int arr[28] = { 0 };
	int result = 0;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				++arr[i + j + k];
			}
		}
	}

	for (int i = 0; i < 28; i++)
	{
		result += arr[i] * arr[i];
	}

	printf("¬сего существует %d счастливых билетиков\n", result);

	system("PAUSE");
	return 0;
}