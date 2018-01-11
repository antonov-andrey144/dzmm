#pragma once

typedef char* Element;

struct SplayTree;

//�������� �����-������
SplayTree* splayTreeCreate();

//���������� �������� � ������
void splayTreeAdd(SplayTree* &tree, int key, Element element);

//���������� �������� �� �����
Element splayTreeGetByKey(SplayTree* tree, int key);

//�������� ������� ����� � ������
bool splayTreeContains(SplayTree* tree, int key);

//�������� �������� �� �����
void splayTreeDeleteByKey(SplayTree* tree, int key);

//�������� ������
void splayTreeDelete(SplayTree* &tree);