#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ArithmeticTree.h"

/**
	@param isValue separation to symbol and number
	@param data it's just a data)0))00
	@param left pointer to left son
	@param right pointer to right son
*/
struct Node
{
	bool isValue;
	int data;
	Node* left;
	Node* right;
};

struct ArithmeticTree
{
	Node* root;
};

/**
	creating Node of Value
	@param value - value of element
	@return pointer to Node
*/
Node* createValueNode(int value)
{
	return new Node{ true, value, nullptr, nullptr };
}

/**
	creating Node of operation
	@param operation - math operation (+, -, /, *, %)
	@param left pointer to left son
	@param right pointer to right son
	@return pointer to Node
*/
Node* createOperationNode(char operation, Node* left, Node* right)
{
	return new Node{ false, operation, left, right };
}

/**
	offsetting pointer to required place
	@param str pointer to offsetting
*/
char* offsetStr(char* str)
{
	int parcount = str[0] == '(' ? 1 : 0;
	int i = 1;
	while (parcount != 0)
	{
		if (str[i] == '(')
		{
			++parcount;
		}
		if (str[i] == ')')
		{
			--parcount;
		}
		++i;
	}
	while (str[i] != ' ')
	{
		++i;
	}
	return str + i + 1;
}

/**
	creating Node
	@param str - pointer to Node
	@return pointer to Node
*/
Node* createNode(char* str)
{
	Node* result = nullptr;
	//printf("creating \"%s\"\n", str);
	if (str[0] == '(')
	{
		//printf("created operation node %c\n", str[1]);
		result = createOperationNode(str[1], createNode(str + 3), createNode(offsetStr(str + 3)));
	}
	else
	{
		int value = 0;
		int sign = str[0] == '-' ? -1 : 1;

		for (int i = str[0] == '-' ? 1 : 0; str[i] != ' ' && str[i] != ')'; ++i)
		{
			value = 10 * value + str[i] - '0';
		}
		value *= sign;

		//printf("created value node %d\n", value);

		result = createValueNode(value);
	}
	return result;
}

/**
	Deleting Node
	@param Node - node to delete
*/
void deleteNode(Node* node)
{
	if (node->left != nullptr)
	{
		deleteNode(node->left);
	}
	if (node->right != nullptr)
	{
		deleteNode(node->right);
	}
	delete node;
}

/**
	A function which recursively counts the nodes
	@param node - node to count
	@return value
*/
int nodeValue(Node* node)
{
	if (node->isValue)
	{
		return node->data;
	}
	else
	{
		switch (node->data)
		{
		case '+': return nodeValue(node->left) + nodeValue(node->right);
		case '-': return nodeValue(node->left) - nodeValue(node->right);
		case '*': return nodeValue(node->left) * nodeValue(node->right);
		case '/': return nodeValue(node->left) / nodeValue(node->right);
		case '%': return nodeValue(node->left) % nodeValue(node->right);
		default: return 0;
		}
	}
}

void printNode(Node* node)
{
	if (node->isValue)
	{
		printf("%d ", node->data);
	}
	else
	{
		printf("( %c ", node->data);
	}

	if (node->left != nullptr)
	{
		printNode(node->left);
	}

	if (node->right != nullptr)
	{
		printNode(node->right);
		printf(") ");
	}
}

ArithmeticTree * createTree(char* filename)
{
	FILE* file = fopen(filename, "r");
	char str[200] = "";
	fgets(str, 200, file);
	fclose(file);

	return new ArithmeticTree{ createNode(str) };
}

void deleteTree(ArithmeticTree* tree)
{
	deleteNode(tree->root);
}

int arithmeticTreeResult(ArithmeticTree* tree)
{
	return nodeValue(tree->root);
}

void arithmeticTreePrint(ArithmeticTree * tree)
{
	printNode(tree->root);
	printf("\n");
}