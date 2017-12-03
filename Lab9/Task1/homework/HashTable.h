#pragma once

typedef char* Element;

struct HashTable;

HashTable* hashTableCreate(int length);

void hashTableDelete(HashTable* hashTable);

void hashTableAdd(HashTable* hashTable, Element str);

void hashTablePrint(HashTable* hashTable);

int hashTableMaxLength(HashTable* hashTable);

float hashTableAverageLength(HashTable* hashTable);

float hashTableFillCoeff(HashTable* hashTable);