#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ArithmeticTree.h"

struct Node
{
	bool isValue;
	int data;
	Node* left;
	Node* right;
};

/**
keeping root of Arithmetic Tree
*/
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
	getting offset to second operand
	@param str - source string
	@param offset - start of first operand
*/
int offsetStr(char* str, int offset)
{
	int parcount = str[offset] == '(' ? 1 : 0;
	int i = offset + 1;
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
	return i + 1;
}

/**
	creating Node
	@param str - source string
	@param offset - start of node
	@return pointer to Node
*/
Node* createNode(char* str, int offset = 0)
{
	Node* result = nullptr;
	if (str[offset] == '(')
	{
		result = createOperationNode(str[offset + 1], createNode(str, offset + 3), createNode(str, offsetStr(str, offset + 3)));
	}
	else
	{
		int value = 0;
		int sign = str[offset] == '-' ? -1 : 1;

		for (int i = offset + (str[offset] == '-' ? 1 : 0); str[i] != ' ' && str[i] != ')'; ++i)
		{
			value = 10 * value + str[i] - '0';
		}
		value *= sign;

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

	printf("\"%s\"\n", str);

	return new ArithmeticTree{ createNode(str) };
}

void deleteTree(ArithmeticTree* &tree)
{
	deleteNode(tree->root);
	delete tree;
	tree = nullptr;
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