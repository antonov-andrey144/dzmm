#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "list.h"

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

void BFS(bool *visited, int unit, int n, int **matrix)
{
	int *queue = new int[n];
	int count = 0;
	int head = 0;
	for (int i = 0; i < n; ++i)
	{
		queue[i] = 0;
	}
	queue[count + 1] = unit;
	++count;
	visited[unit] = true;
	while (head < count)
	{
		unit = queue[head + 1];
		++head;
		printf("%d ", unit + 1);
		for (int i = 0; i < n; ++i)
			if (matrix[unit][i] && !visited[i])
			{
				queue[count + 1] = i;
				++count;
				visited[i] = true;
			}
	}

	//delete[] queue;

}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	FILE* file = fopen("matrix.txt", "r");
	int n = 0;
	int m = 0;
	fscanf(file, "%d", &n);
	m = n;
	int **matrix = initMatrix(n, m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			fscanf(file, "%d", &matrix[i][j]);
		}
	}
	fclose(file);

	bool *visited = new bool[n];

	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}

	BFS(visited, 0, n, matrix);

	delete[] visited;

	deleteMatrix(matrix, n, m);
	int pause = 0;
	printf("\n");
	scanf("%d", &pause);
	return 0;
}