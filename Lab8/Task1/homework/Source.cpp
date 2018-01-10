#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SplayTree.h"

void printMenu()
{
	printf("\tMENU\n");
	printf("0 - exit\n");
	printf("1 - add\n");
	printf("2 - search\n");
	printf("3 - remove\n");
	printf("4 - contains\n");
}

int main()
{
	SplayTree* tree = splayTreeCreate();

	int choice = 0;
	int key = 0;
	Element element = new char[40];
	do 
	{
		printMenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			printf("Input key ");
			scanf("%d", &key);
			printf("Input value ");
			scanf("%s", element);
			splayTreeAdd(tree, key, element);
		}
		break;
		case 2:
		{
			printf("Input key ");
			scanf("%d", &key);
			printf("Found : \"%s\"\n", splayTreeGetByKey(tree, key));
		}
		break;
		case 3:
		{
			printf("Input key ");
			scanf("%d", &key);
			splayTreeDeleteByKey(tree, key);
		}
		break;
		case 4:
		{
			printf("Input key ");
			scanf("%d", &key);
			if (splayTreeContains(tree, key))
			{
				printf("Contains\n");
			}
			else
			{
				printf("Not contains\n");
			}
		}
		break;
		}
	} while (choice != 0);

	splayTreeDelete(tree);
	char *pause = new char[500];
	gets_s(pause, 500);
	delete[] pause;
	return 0;
}