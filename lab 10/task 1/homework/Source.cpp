#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int** initMatrix(int rows, int cols)
{
	int** matr = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		matr[i] = new int[cols] {0};
		for (int j = 0; j < cols; ++j)
		{
			matr[i][j] = -1;
		}
	}
	return matr;
}

void printMatrix(int** matr, int rows, int cols)
{
	for (int i = 0; i < cols; ++i)
	{
		printf("_____", i);
	}
	printf("\n     ");
	for (int i = 0; i < cols; ++i)
	{
		printf("%3d |", i);
	}
	printf("\n");
	for (int i = 0; i < rows; ++i)
	{
		printf("%4d|", i);
		for (int j = 0; j < cols; ++j)
		{
			printf("%4d|", matr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < cols; ++i)
	{
		printf("_____", i);
	}
	printf("\n");

}

void deleteMatrix(int** matr, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] matr[i];
	}
	delete[] matr;
}

void eraseRoadsToTown(int** roads, int townsCount, int town)
{
	for (int i = 0; i < townsCount; ++i)
	{
		roads[i][town] = -1;
	}
}

int findClosestFromTown(int** roads, int townsCount, int from)
{
	int minTown = -1;
	for (int i = 0; i < townsCount && from != -1; ++i)
	{
		if (roads[from][i] == -1 || i == from)
		{
			continue;
		}
		if (minTown == -1 || roads[from][minTown] > roads[from][i])
		{
			minTown = i;
		}
	}
	return minTown;
}

bool hasRoads(int** roads, int townsCount)
{
	for (int i = 0; i < townsCount; ++i)
	{
		for (int j = 0; j < townsCount; ++j)
		{
			if (roads[i][j] != -1)
			{
				return true;
			}
		}
	}
	return false;
}

void addClosestToCountry(int** roads, int** countries, int townsCount, int countriesCount, int country)
{
	//ищем ближайший незанятый город
	int closestTown = -1;
	int minDistance = -1;
	for (int i = 0; i < townsCount + 1 && countries[country][i] != -1; ++i)
	{
		int tempClosestTown = findClosestFromTown(roads, townsCount, countries[country][i]);

		if (tempClosestTown != -1 && (minDistance == -1 || roads[i][tempClosestTown] < minDistance))
		{
			closestTown = tempClosestTown;
			minDistance = roads[i][tempClosestTown];
		}
	}
	//если таковой нашелся
	if (closestTown != -1)
	{
		//стираем все дороги в него
		eraseRoadsToTown(roads, townsCount, closestTown);
		int i = 0;
		while (countries[country][i] != -1)
		{
			++i;
		}
		//добавляем к списку городов в стране
		countries[country][i] = closestTown;
	}
}

int main()
{
	//начинаем считывание файла
	FILE* fileIn = fopen("input.txt", "r");

	int townsCount = 0;
	int roadsCount = 0;
	fscanf(fileIn, "%d", &townsCount);
	fscanf(fileIn, "%d", &roadsCount);
	int** roads = initMatrix(townsCount, townsCount);
	for (int i = 0; i < roadsCount; ++i)
	{
		int from = 0;
		int to = 0;
		int roadLength = 0;
		fscanf(fileIn, "%d %d %d", &from, &to, &roadLength);
		roads[from][to] = roadLength;
		roads[to][from] = roadLength;
	}

	int countriesCount = 0;
	fscanf(fileIn, "%d", &countriesCount);
	int** countries = initMatrix(countriesCount, townsCount + 1);
	for (int i = 0; i < countriesCount; ++i)
	{
		fscanf(fileIn, "%d", &countries[i][0]);
		eraseRoadsToTown(roads, townsCount, countries[i][0]);
	}
	fclose(fileIn);
	//закончили считывание из файла

	//разбираем города по странам
	while (hasRoads(roads, townsCount)) 
	{
		for (int i = 0; i < countriesCount; ++i)
		{
			addClosestToCountry(roads, countries, townsCount, countriesCount, i);
		}
	}

	//выводим список стран
	for (int i = 0; i < countriesCount; ++i)
	{
		printf("%d -> ", countries[i][0]);
		for (int j = 1; j < townsCount + 1 && countries[i][j] != -1; ++j)
		{
			printf("%d ", countries[i][j]);
		}
		printf("\n");
	}

	//освобождаем память
	deleteMatrix(roads, townsCount, townsCount);
	deleteMatrix(countries, countriesCount, townsCount + 1);

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}