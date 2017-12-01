#pragma once
#include <iostream>

typedef int Element;

struct Node;

struct BiList;

BiList* listCreate();

void listDelete(BiList* list);

void listAddToPos(BiList* list, int pos, Element data);

void listRemoveFromPos(BiList* list, int pos);

void listPrint(BiList* list);

void listPrintReverse(BiList* list);