#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int substring(char* src, char* sub)
{
	int subLen = strlen(sub);
	int srcLen = strlen(src);
	char* shift = new char[subLen] { 0 };
	for (int i = 0; i < subLen - 1; ++i)
	{
		for (int j = i + 1; j < subLen - 1; ++j)
		{
			if (sub[i] == sub[j])
			{
				shift[i] = j;
			}
		}
	}

	for (int i = 0, j = 0; i <= srcLen - subLen && j >= 0; i += shift[j] + 1) 
	{
		for (j = subLen - 1; j >= 0 && sub[j] == src[i + j]; --j);
		{
			if (j < 0)
			{
				return i;
			}
		}
	}

	return -1;
}

int main()
{
	char str[200], sub[10];
	
	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%s", str);
	fclose(file);

	printf("input string for searching in \n\"%s\"\n10 chars in lowercase only\n", str);
	scanf("%s", sub);

	printf("first index of substring occurance : %d\n", substring(str, sub));
	int pause = 0;
	printf("\n");
	scanf("%d", &pause);
	return 0;
}