#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int countRows(char* fileName)
{
	FILE* file = fopen(fileName, "r");
	int tmp = 0;
	int res = 0;
	while (!feof(file))
	{
		fscanf(file, "%d", &tmp);
		++res;
	}
	fclose(file);
	return sqrt(res);
}

void initTable(char* fileName, int** &table, int &dim)
{
	dim = countRows(fileName);
	table = new int*[dim];
	FILE* file = fopen(fileName, "r");
	for (int i = 0; i < dim; ++i)
	{
		table[i] = new int[dim];
		for (int j = 0; j < dim; ++j)
		{
			fscanf(file, "%d", &table[i][j]);
		}
	}
	fclose(file);
}

void printTable(int** table, int dim)
{
	for (int i = 0; i < dim; ++i)
	{
		printf("____");
	}
	printf("\n");
	for (int i = 0; i < dim; ++i)
	{
		for (int j = 0; j < dim; ++j)
		{
			printf("%4d", table[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < dim; ++i)
	{
		printf("____");
	}
	printf("\n");
}

void deleteTable(int** &table, int dim)
{
	for (int i = 0; i < dim; ++i)
	{
		delete[] table[i];
	}
	delete[] table;
	table = nullptr;
}

int main()
{
	int dim = 0;
	int** table = nullptr;
	initTable("matr.txt", table, dim);
	bool* visited = new bool[dim] { 0 };
	int* path = new int[dim * dim]{ 0 }; //������, ����� ������� �������� �������� ������
	printTable(table, dim);
	int minI = 0;
	int minJ = 0;
	int minCost = 0;
	int tmpMin = 0;
	int visitedCount = 1;
	visited[0] = true;

	while (visitedCount < dim) 
	{
		tmpMin = -1;
		for (int i = 0; i < dim; ++i)
		{
			for (int j = 0; j < dim; ++j)
			{
				if ((visited[i]) && (table[i][j] != -1) && (tmpMin == -1 || table[i][j] < tmpMin))
				{
					tmpMin = table[i][j];
					minI = i;
					minJ = j;
				}
			}
		}
		if (!visited[minJ])
		{
			path[visitedCount] = minJ;
			++visitedCount;
			minCost += tmpMin;
			visited[minJ] = true;
			printf("%d->%d [%d]\n", minI, minJ, tmpMin);
		}
		table[minI][minJ] = table[minJ][minI] = -1;
	}

	printf("weight = %d\n", minCost);
	delete[] path;
	delete[] visited;
	deleteTable(table, dim);

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}