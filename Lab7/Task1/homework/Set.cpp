#include <iostream>
#include "Set.h"

struct Node {
	Value value;
	Node* left;
	Node* right;
};

struct Set
{
	Node* root;
};

Node* createNode(Value value, Node* left = nullptr, Node* right = nullptr)
{
	Node* node = new Node();
	node->value = value;
	node->left = left;
	node->right = right;
	return node;
}

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

void addToNode(Node* node, Value value)
{
	if (node->value > value)
	{
		if (node->left == nullptr)
		{
			node->left = createNode(value);
		}
		else
		{
			addToNode(node->left, value);
		}
	}
	if (node->value < value)
	{
		if (node->right == nullptr)
		{
			node->right = createNode(value);
		}
		else
		{
			addToNode(node->right, value);
		}
	}
}

Node* rightMostNode(Node* node)
{
	Node* tempNode = node;
	while (tempNode->right != nullptr)
	{
		tempNode = tempNode->right;
	}
	return tempNode;
}

void removeFromNode(Node* &node, Value value)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->value > value)
	{
		removeFromNode(node->left, value);
	}

	if (node->value < value)
	{
		removeFromNode(node->right, value);
	}

	if (node->value == value)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			delete node;
			node = nullptr;
			return;
		}
		if (node->left == nullptr && node->right != nullptr)
		{
			Node* tempNode = node->right;
			delete node;
			node = tempNode;
			return;
		}
		if (node->left != nullptr && node->right == nullptr)
		{
			Node* tempNode = node->left;
			delete node;
			node = tempNode;
			return;
		}
		if (node->left != nullptr && node->right != nullptr)
		{
			if (node->left->right == nullptr)
			{
				Node* tempNode = node->left;
				tempNode->right = node->right;
				delete node;
				node = tempNode;
				return;
			}

			Node* tempNode = rightMostNode(node->left);
			node->value = tempNode->value;						

			removeFromNode(node->left, node->value);
		}
	}
}

void printNode(Node* node, int level, bool direction, bool asTree)
{
	if (node == nullptr)
	{
		return;
	}

	if (direction)
	{
		printNode(node->left, level + 1, direction, asTree);
	}
	else
	{
		printNode(node->right, level + 1, direction, asTree);
	}

	if (asTree)
	{
		for (int i = 0; i < level; ++i)
		{
			printf("   ");
		}
	}
	printf("%3d%c", node->value, asTree ? '\n' : ' ');

	if (direction)
	{
		printNode(node->right, level + 1, direction, asTree);
	}
	else
	{
		printNode(node->left, level + 1, direction, asTree);
	}
}

bool containsNode(Node* node, Value value)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->value == value)
	{
		return true;
	}
	if (node->value > value)
	{
		return containsNode(node->left, value);
	}
	if (node->value < value)
	{
		return containsNode(node->right, value);
	}
}

Set* createSet()
{
	Set* newSet = new Set();
	newSet->root = nullptr;
	return newSet;
}

void deleteSet(Set* &set)
{
	if (set->root == nullptr)
	{
		return;
	}
	deleteNode(set->root);
	delete set;
	set = nullptr;
}

void addToSet(Set* set, Value value)
{
	if (set->root == nullptr)
	{
		set->root = createNode(value);
	}
	else
	{
		addToNode(set->root, value);
	}
}

void removeFromSet(Set* set, Value value)
{
	removeFromNode(set->root, value);
}

void printSetAscend(Set* set)
{
	if (set->root == nullptr)
	{
		printf("EMPTY");
	}
	else
	{
		printNode(set->root, 0, true, false);
	}
	printf("\n");
}

void printSetDescend(Set* set)
{
	if (set->root == nullptr)
	{
		printf("EMPTY");
	}
	else
	{
		printNode(set->root, 0, false, false);
	}
	printf("\n");
}

void printLPR(Set* set)
{
	printf("__________________________________________________\n\n");
	if (set->root == nullptr)
	{
		printf("EMPTY\n");
	}
	else
	{
		printNode(set->root, 0, true, true);
	}
	printf("__________________________________________________\n");
}

void printRPL(Set* set)
{
	printf("__________________________________________________\n\n");
	if (set->root == nullptr)
	{
		printf("EMPTY\n");
	}
	else
	{
		printNode(set->root, 0, false, true);
	}
	printf("__________________________________________________\n");
}

bool containsInSet(Set* set, Value value)
{
	return containsNode(set->root, value);
}
