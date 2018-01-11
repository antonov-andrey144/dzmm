#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ArithmeticTree.h"

int main()
{
	ArithmeticTree* tree = createTree("input.txt");

	arithmeticTreePrint(tree);

	printf("%d\n", arithmeticTreeResult(tree));

	deleteTree(tree);

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}