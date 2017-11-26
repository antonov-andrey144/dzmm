#pragma once
#define _CRT_SECURE_NO_WARNINGS

/**
	making root of Arithmetic Tree
	@return pointer of root
*/
struct ArithmeticTree; 

/**
	Filling of Arithmetic Tree from file
	@param filename file from which it's filled
*/
ArithmeticTree* createTree(char* filename);

/**
	removing of Arithmetic Tree
	@param tree - tree to removie
*/
void deleteTree(ArithmeticTree* tree); 

/**
	Counting value of Arithmetic Tree
	@param tree - tree to count
*/
int arithmeticTreeResult(ArithmeticTree* tree); 

/**
	printing of Arithmetic Tree
	@param tree - tree to print
*/
void arithmeticTreePrint(ArithmeticTree* tree);