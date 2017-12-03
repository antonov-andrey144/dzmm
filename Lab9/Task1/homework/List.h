#pragma once

typedef char* Element;

struct Node;

struct List;

List* listCreate();

void listDelete(List* list);

int listLength(List* list);

void listAdd(List* list, Element key);

void listPrint(List* list);

bool listIsEmpty(List* list);