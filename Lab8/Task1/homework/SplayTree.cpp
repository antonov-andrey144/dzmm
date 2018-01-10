#define _CRT_SECURE_NO_WARNINGS
#include "SplayTree.h"
#include <iostream>
#include <string>

// элемент дерева
struct SplayNode
{
	int key;
	char* value;
	SplayNode *left;
	SplayNode *right;
	SplayNode *parent;
};

// корень дерева
struct SplayTree
{
	SplayNode *root;
};

// создание дерева
SplayTree* splayTreeCreate()
{
	return new SplayTree{ nullptr };
}

bool isLeftSon(SplayNode* node)
{
	return (node != nullptr && node->parent != nullptr && node->parent->left == node);
}

bool isRightSon(SplayNode* node)
{
	return (node != nullptr && node->parent != nullptr && node->parent->right == node);
}

// проверка на возможность зигануть
bool canZig(SplayTree* tree, SplayNode* node)
{
	return tree != nullptr && node != nullptr && tree->root != nullptr  && node->parent == tree->root;
}

// проверрка имеет ли деда
bool hasGrandParent(SplayTree* tree, SplayNode* node)
{
	return tree != nullptr && node != nullptr && tree->root != nullptr && node->parent != nullptr && node->parent->parent != nullptr;
}

// перемещение ноды в корень
void assignRoot(SplayTree* tree, SplayNode* node)
{
	tree->root = node;
	node->parent = nullptr;
}

// делает левым сыном
SplayNode* assignLeftSon(SplayNode* parent, SplayNode* son)
{
	parent->left = son;
	if (son != nullptr)
	{
		son->parent = parent;
	}
	return son;
}

// делает правым сыном
SplayNode* assignRightSon(SplayNode* parent, SplayNode* son)
{
	parent->right = son;
	if (son != nullptr)
	{
		son->parent = parent;
	}
	return son;
}

// зигует с помощью ранее написаных функций
bool zig(SplayTree* tree, SplayNode* node)
{
	if (canZig(tree, node))
	{
		if (isLeftSon(node))
		{
			assignLeftSon(tree->root, node->right);

			assignRightSon(node, tree->root);

			assignRoot(tree, node);

			return true;
		}
		else if (isRightSon(node))
		{
			assignRightSon(tree->root, node->left);

			assignLeftSon(node, tree->root);

			assignRoot(tree, node);

			return true;
		}
	}
	return false;
}

// переводит ноду в место её деда
void nodeToGrandParent(SplayTree* tree, SplayNode* node)
{
	if (!hasGrandParent(tree, node))
	{
		return;
	}
	SplayNode* grandParent = node->parent->parent;
	if (grandParent == tree->root)
	{
		assignRoot(tree, node);
	}
	else if (isLeftSon(grandParent))
	{
		assignLeftSon(grandParent->parent, node);
	}
	else if (isRightSon(grandParent))
	{
		assignRightSon(grandParent->parent, node);
	}
}

// выполняется с помощью ранее написаных функций
bool zigzig(SplayTree* tree, SplayNode* node)
{
	if (hasGrandParent(tree, node))
	{
		SplayNode* parent = node->parent; // запоминаем отца и деда
		SplayNode* grandParent = parent->parent;
		if (isLeftSon(node) && isLeftSon(parent))
		{
			nodeToGrandParent(tree, node); // перемещаем ноду в место деда

			assignLeftSon(grandParent, parent->right);
			assignRightSon(parent, grandParent);
			assignLeftSon(parent, node->right);
			assignRightSon(node, parent);

			return true;
		}
		else if (isRightSon(node) && isRightSon(parent))
		{
			nodeToGrandParent(tree, node);

			assignRightSon(grandParent, parent->left);
			assignLeftSon(parent, grandParent);
			assignRightSon(parent, node->left);
			assignLeftSon(node, parent);

			return true;
		}
	}
	return false;
}

bool zigzag(SplayTree* tree, SplayNode* node)
{
	if (hasGrandParent(tree, node))
	{
		SplayNode* parent = node->parent;
		SplayNode* grandParent = parent->parent;
		if (isRightSon(node) && isLeftSon(parent))
		{
			nodeToGrandParent(tree, node);

			assignLeftSon(grandParent, node->right);
			assignRightSon(parent, node->left);
			assignRightSon(node, grandParent);
			assignLeftSon(node, parent);

			return true;
		}
		else if (isLeftSon(node) && isRightSon(parent))
		{
			nodeToGrandParent(tree, node);

			assignRightSon(grandParent, node->left);
			assignLeftSon(parent, node->right);
			assignLeftSon(grandParent, node->right);
			assignRightSon(grandParent, parent);

			return true;
		}
	}
	return false;
}

void splay(SplayTree* tree, SplayNode* node)
{
	while (zigzig(tree, node) || zigzag(tree, node));
	zig(tree, node);
}

SplayNode* findParent(SplayNode* root, int key)
{
	if (root->key > key && root->left != nullptr)
	{
		return findParent(root->left, key);
	}
	else if (root->key < key && root->right != nullptr)
	{
		return findParent(root->right, key);
	}
	return root;
}

// создание новой ноды
SplayNode* newSplayNode(int key, Element element)
{
	Element copy = new char[40];
	strcpy_s(copy, 40, element);
	return new SplayNode{ key, copy, nullptr, nullptr, nullptr };
}

// добавление ноды в дерево
SplayNode* splayNodeAdd(SplayNode* node, int key, Element element)
{
	if (node->key == key)
	{
		strcpy_s(node->value, 40, element);
	}
	else if (node->key < key)
	{
		if (node->left != nullptr)
		{
			return splayNodeAdd(node->left, key, element);
		}
		return assignLeftSon(node, newSplayNode(key, element));
	}
	else if (node->key > key)
	{
		if (node->right != nullptr)
		{
			return splayNodeAdd(node->right, key, element);
		}
		return assignRightSon(node, newSplayNode(key, element));
	}
}


void splayTreeAdd(SplayTree * tree, int key, Element element)
{
	if (tree->root == nullptr)
	{
		assignRoot(tree, newSplayNode(key, element));
	}
	else
	{
		splay(tree, splayNodeAdd(tree->root, key, element));
	}
}

// поиск ноды
SplayNode* find(SplayNode* node, int key)
{
	if (node == nullptr || node->key == key)
	{
		return node;
	}
	else if (node->key < key)
	{
		return find(node->left, key);
	}
	else if (node->key > key)
	{
		return find(node->right, key);
	}
}

// 
bool splayTreeContains(SplayTree* tree, int key)
{
	SplayNode* node = find(tree->root, key);
	if (node != nullptr)
	{
		splay(tree, node);
		return true;
	}
	return false;
}

char* splayTreeGetByKey(SplayTree * tree, int key)
{
	SplayNode* temp = find(tree->root, key);
	if (temp == nullptr)
	{
		return "";
	}
	else
	{
		return temp->value;
	}
}

void splayTreeDeleteByKey(SplayTree * tree, int key)
{
	SplayNode *node = find(tree->root, key);
	if (node == nullptr)
	{
		return;
	}
	if (node->left != nullptr && node->right != nullptr)
	{
		SplayNode* temp = node->left;
		while (temp->right != nullptr)
		{
			temp = temp->right;
		}
		std::swap(temp->key, node->key);
		std::swap(temp->value, node->value);
		if (temp->parent->right == temp)
		{
			if (temp->left != nullptr)
			{
				temp->parent->right = temp->left;
			}
			else
			{
				temp->parent->right = nullptr;
			}
		}
		else
		{
			if (temp->left != nullptr)
			{
				temp->parent->left = temp->left;
			}
			else
			{
				temp->parent->left = nullptr;
			}
		}
		delete temp;
		if (node->parent != nullptr)
		{
			splay(tree, node->parent);
		}
	}
	else if (node->left != nullptr)
	{
		if (node->parent == nullptr)
		{
			tree->root = node->left;
			tree->root->parent = nullptr;
		}
		else
		{
			if (node->parent->left == node)
			{
				node->parent->left = node->left;
			}
			else
			{
				node->parent->right = node->left;
			}
			node->left->parent = node->parent;
			splay(tree, node->parent);
		}
		delete node;
	}
	else if (node->right != nullptr)
	{
		if (node->parent == nullptr)
		{
			tree->root = node->right;
			tree->root->parent = nullptr;
		}
		else
		{
			if (node->parent->left == node)
			{
				node->parent->left = node->right;
			}
			else
			{
				node->parent->right = node->right;
			}
			node->right->parent = node->parent;
			splay(tree, node->parent);
		}
		delete node;
	}
	else
	{
		if (node->parent != nullptr)
		{
			if (node->parent->left == node)
			{
				node->parent->left = nullptr;
			}
			else
			{
				node->parent->right = nullptr;
			}
			splay(tree, node->parent);
		}
		else
		{
			tree->root = nullptr;
		}
		delete node;
	}
}

void deleteSubTree(SplayNode* root)
{
	if (root->left != nullptr)
	{
		deleteSubTree(root->left);
	}
	if (root->right != nullptr)
	{
		deleteSubTree(root->right);
	}
	delete root;
}

void splayTreeDelete(SplayTree* &tree)
{
	if (tree->root != nullptr)
	{
		deleteSubTree(tree->root);
	}
	delete tree;
	tree = nullptr;
}