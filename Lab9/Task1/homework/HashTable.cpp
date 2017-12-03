#include "HashTable.h"
#include "List.h"
#include <iostream>

struct HashTable {
	int length;
	List** lists;
};

int getHash(Element str, int hashSize) // хеш-функция
{
	int result = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		result = (result + str[i]) % hashSize;
	}
	return result;
}

HashTable* hashTableCreate(int length)
{
	HashTable* result = new HashTable{ length, nullptr };
	result->lists = new List*[length];
	for (int i = 0; i < length; ++i)
	{
		result->lists[i] = listCreate();
	}
	return result;
}

void hashTableDelete(HashTable* hashTable)
{
	for (int i = 0; i < hashTable->length; ++i)
	{
		listDelete(hashTable->lists[i]);
	}
	delete[] hashTable->lists;
	delete hashTable;
}

void hashTableAdd(HashTable* hashTable, Element str)
{
	listAdd(hashTable->lists[getHash(str, hashTable->length)], str);
}

void hashTablePrint(HashTable* hashTable)
{
	for (int i = 0; i < hashTable->length; ++i)
	{
		printf("\tHASH:%03d\n", i);
		listPrint(hashTable->lists[i]);
	}
}

int hashTableMaxLength(HashTable* hashTable)
{
	int maxLength = listLength(hashTable->lists[0]);
	for (int i = 0; i < hashTable->length; i++)
	{
		int tempLength = listLength(hashTable->lists[i]);
		maxLength = (tempLength > maxLength ? tempLength : maxLength);
	}
	return maxLength;
}

float hashTableAverageLength(HashTable* hashTable)
{
	float sumLength = 0;
	for (int i = 0; i < hashTable->length; ++i)
	{
		sumLength += listLength(hashTable->lists[i]);
	}
	return sumLength / hashTable->length;
}

float hashTableFillCoeff(HashTable* hashTable)
{
	float filledCount = 0;
	for (int i = 0; i < hashTable->length; ++i)
	{
		if (!listIsEmpty(hashTable->lists[i]))
		{
			++filledCount;
		}
	}
	return filledCount / hashTable->length;
}
