#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int **initMatrix(int rows, int cols)
{
	int **matr = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		matr[i] = new int[cols] {0};
	}
	return matr;
}

void deleteMatrix(int **matr, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] matr[i];
	}
	delete[] matr;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n = 0, m = 0;
	printf("По условию задачи матрица уже существует. Путь существует в файле matrix.txt\nЗаполните файл матрицей, первая строка - n - число строк, через пробел m - число столбцов, далее матрица. \nПосле заполнения матрицы введите что-нибудь.\n");
	int pause = 0;
	scanf("%d", &pause);

	FILE* file = fopen("matrix.txt", "r");
	fscanf(file, "%d", &n);
	fscanf(file, "%d", &m);
	int **arr = initMatrix(n, m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			fscanf(file, "%d", &arr[i][j]);
		}
	}

	int lessValue = 2000000000;
	int mostValue = -2000000000;
	int index = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j] < lessValue)
			{
				lessValue = arr[i][j];
				index = j;
			}
		}
		if (index > -1)
		{
			for (int p = 0; p < n; ++p)
			{
				if (arr[p][index] > mostValue)
				{
					mostValue = arr[p][index];
				}
			}
		}
		if (mostValue == lessValue)
		{
			printf("%d ", lessValue);
		}
		
		lessValue = 2000000000;
		mostValue = -2000000000;
	}


	deleteMatrix(arr, n, m);
	pause = 0;
	scanf("%d", &pause);
	return 0;
}