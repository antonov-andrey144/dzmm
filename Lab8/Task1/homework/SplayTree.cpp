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
	if (node != nullptr)
	{
		node->parent = nullptr;
	}
}

// делает левым сыном, возвращает указатель на сына (используется при добавлении)
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

// вращает влево или вправо
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

// ставит ноду на место ее деда
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

// делает двойное вращение в одну сторону
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


void splayTreeAdd(SplayTree* &tree, int key, Element element)
{
	if (tree == nullptr)
	{
		tree = splayTreeCreate();
	}
	if (tree->root == nullptr)
	{
		assignRoot(tree, newSplayNode(key, element));
	}
	else
	{
		splay(tree, splayNodeAdd(tree->root, key, element));
	}
}

// поиск ноды по ключу
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

// проверка, есть ли данный ключ в дереве
bool splayTreeContains(SplayTree* tree, int key)
{
	SplayNode* temp = find(tree->root, key);
	if (temp != nullptr)
	{
		splay(tree, temp);
		return true;
	}
	return false;
}

//поиск значения по ключу
char* splayTreeGetByKey(SplayTree * tree, int key)
{
	SplayNode* temp = find(tree->root, key);
	if (temp == nullptr)
	{
		return "";
	}
	else
	{
		splay(tree, temp);
		return temp->value;
	}
}

SplayNode* minNode(SplayNode *node) {
	while (node->left)
	{
		node = node->left;
	}
	return node;
}

void deleteRoot(SplayTree * tree)
{
	SplayNode* root = tree->root;
	if (root->left == nullptr)
	{
		assignRoot(tree, root->right);
	}
	else if (root->right == nullptr)
	{
		assignRoot(tree, root->left);
	}
	else
	{
		SplayNode* min = minNode(root->right);
		if (min->parent != root)
		{
			assignLeftSon(min->parent, min->right);
			assignRightSon(min, root->right);
		}
		assignLeftSon(min, root->left);
		assignRoot(tree, min);
	}
	delete root;
}

void splayTreeDeleteByKey(SplayTree * tree, int key)
{
	SplayNode* temp = find(tree->root, key);
	if (temp == nullptr)
	{
		return;
	}
	splay(tree, temp);

	deleteRoot(tree);
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