#pragma once

typedef char* Element;

struct SplayTree;

//Создание сплей-дерева
SplayTree* splayTreeCreate();

//добавление элемента в дерево
void splayTreeAdd(SplayTree* &tree, int key, Element element);

//Нахождение элемента по ключу
Element splayTreeGetByKey(SplayTree* tree, int key);

//Проверка наличия ключа в дереве
bool splayTreeContains(SplayTree* tree, int key);

//Удаление элемента по ключу
void splayTreeDeleteByKey(SplayTree* tree, int key);

//Удаление дерева
void splayTreeDelete(SplayTree* &tree);