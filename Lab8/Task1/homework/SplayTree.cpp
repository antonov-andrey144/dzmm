#include "SplayTree.h"
#include <string>

struct SplayNode
{
	int key;
	char* value;
	SplayNode *left;
	SplayNode *right;
	SplayNode *parent;
};

struct SplayTree
{
	SplayNode *root;
};

SplayTree* splayTreeCreate()
{
	return new SplayTree{ nullptr };
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

void zig(SplayTree* tree, SplayNode* node)
{
	node->parent->left = node->right;
	if (node->right != nullptr) 
	{
		node->right->parent = node->parent;
	}
	node->right = node->parent;
	node->parent = node->parent->parent;
	node->right->parent = node;
	if (node->parent == nullptr) 
	{
		tree->root = node;
	}
}

void zag(SplayTree* tree, SplayNode* node)
{
	node->parent->right = node->left;
	if (node->left != nullptr) 
	{
		node->left->parent = node->parent;
	}
	node->left = node->parent;
	node->parent = node->parent->parent;
	node->left->parent = node;
	if (node->parent == nullptr) 
	{
		tree->root = node;
	}
}

void splay(SplayTree* tree, SplayNode* node)
{
	if (node->parent != nullptr) 
	{
		if (node == node->parent->left) 
		{
			if (node->parent->parent == nullptr) 
			{
				zig(tree, node);
			}
			else if (node->parent == node->parent->parent->left) 
			{
				zig(tree, node->parent);
				zig(tree, node);
			}
			else 
			{
				zig(tree, node);
				zag(tree, node);
			}
		}
		else 
		{
			if (node->parent->parent == nullptr) 
			{
				zag(tree, node);
			}
			else if (node->parent == node->parent->parent->right) 
			{
				zag(tree, node->parent);
				zag(tree, node);
			}
			else 
			{
				zag(tree, node);
				zig(tree, node);
			}
		}
		splay(tree, node);
	}
}

void splayTreeAdd(SplayTree * tree, int key, Element element)
{
	Element copy = new char[40];
	strcpy_s(copy, 40, element);
	if (tree->root == nullptr) 
	{
		tree->root = new SplayNode{ key, copy, nullptr, nullptr, nullptr };
	}
	else 
	{
		SplayNode *parent = findParent(tree->root, key);
		if (parent->key > key) 
		{
			SplayNode *newNode = new SplayNode{ key, copy, nullptr, nullptr, parent };
			parent->left = newNode;
			splay(tree, newNode);
		}
		else if (parent->key == key) 
		{
			parent->value = copy;
			splay(tree, parent);
		}
		else 
		{
			SplayNode *newNode = new SplayNode{ key, copy, nullptr, nullptr, parent };
			parent->right = newNode;
			splay(tree, newNode);
		}
	}
}

SplayNode* find(SplayNode* root, int key)
{
	if (root == nullptr || root->key == key) 
	{
		return root;
	}
	else if (root->key > key) 
	{
		return find(root->left, key);
	}
	else 
	{
		return find(root->right, key);
	}
}

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

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void swap(char*& a, char*& b)
{
	char* c = a;
	a = b;
	b = c;
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
		swap(temp->key, node->key);
		swap(temp->value, node->value);
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