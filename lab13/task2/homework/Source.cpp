#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void initTable(char* fileName, int** &table, int &rows, int &cols)
{
	FILE* file = fopen(fileName, "r");
	fscanf(file, "%d %d", &rows, &cols);
	table = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		table[i] = new int[cols];
		for (int j = 0; j < cols; ++j)
		{
			fscanf(file, "%d", &table[i][j]);
		}
	}
	fclose(file);
}

void deleteTable(int** &table, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] table[i];
	}
	delete[] table;
	table = nullptr;
}

int getState(char chr) 
{
	switch (chr)
	{
	case '/':
		return 0;
	case '*':
		return 1;
	default:
		return 2;
	}
}

int main()
{
	int** states = nullptr;
	int rows = 0;
	int cols = 0;
	initTable("states.txt", states, rows, cols);

	char str[256] = "";
	int i = 0;
	int state = 0;

	FILE* file = fopen("text.txt", "r");
	while (!feof(file))
	{
		fscanf(file, "%s", str);
		i = 0;
		while (str[i] != '\0')
		{
			if (state == 1 && str[i] == '*')
			{
				printf("/*");
			}
			else if (state == 2 || state == 3)
			{
				printf("%c", str[i]);
			}
			state = states[state][getState(str[i])];
			++i;
		}
		if (state == 2) printf("\n");
	}
	fclose(file);

	deleteTable(states, rows, cols);
	int pause = 0;
	printf("\n");
	scanf("%d", &pause);
	return 0;
}