#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ArithmeticTree.h"

int main()
{
	ArithmeticTree* tree = createTree("input.txt");

	arithmeticTreePrint(tree);

	printf("%d\n", arithmeticTreeResult(tree));

	deleteTree(tree);
	return 0;
}